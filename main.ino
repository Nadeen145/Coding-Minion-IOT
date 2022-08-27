#include "my_utility.h"
#include "motors.h"
#include "distance_sensors.h"
#include "charge_detect.h"

#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WebSerial.h>

#include <Firebase_ESP_Client.h>
//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

// Firebase project API Key
#define API_KEY "AIzaSyAWjSDHTgJVYfuhwAVy9StRqDm_eqc0lwU"
// RTDB URLefine the RTDB URL */
#define DATABASE_URL "https://hi-robot-c64d7-default-rtdb.firebaseio.com/" 

// Path for file in Firebase
#define FILE_PATH "wirelessCar/" 

#define MANUAL_DRIVE_DELAY 300
#define NO_FIREBASE_DELAY 150

int charging_back_delay;
int lastState;
extern int robotMode;
int curr_robot_mode;
bool autonomous_in_charge;
static SemaphoreHandle_t mutex;
static SemaphoreHandle_t mutex2;
int user_charge;
int curr_user_charge;
extern int cornerNumber;
extern int currCornerNumber; //  0 - (corner_number-1)
//time_t rawtime aka long int (%ld) contains the number of seconds since 1970
//time(&rawtime);
extern time_t lastChargeTime;
extern time_t currentTime;
extern time_t startChargeTime;
extern Tb6612fng* motors;
extern int charging_interval;
extern int charging_forward_delay;
extern int charging_time;

int vSpeed = 255;   // Standard Speed can take a value between 0-255
bool backward = false;
bool right = false;
bool left = false;
bool forward = false;

int tmp_speed;
bool tmp_back;
bool tmp_right;
bool tmp_left;
bool tmp_forward;

// Firebase Data object
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
bool signupOK = false;

//-------------------------------Firebase--------------------------------------
void FirebaseSetup() {
  /* Assign the api key (required) */
  config.api_key = API_KEY;
  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;
  /* Set Config Timeouts */
  //config.timeout.wifiReconnect = 3 * 1000;
  //config.timeout.socketConnection = 3 * 1000;
  config.timeout.serverResponse = 3 * 1000; 

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")){
    WebSerial.println("ok");
    signupOK = true;
  }
  else{
    WebSerial.println("Error: sign up to Firebase");
    //Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h
  
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void readRealTimeDB_ValueInt(const char *param_name, int *output) {
      char start_str[150] = FILE_PATH;
      if (Firebase.RTDB.get(&fbdo, strcat(start_str, param_name))) {
        //Serial.println("READ: " + param_name + " succesfully");
        //Serial.println("PATH: " + fbdo.dataPath());
        //Serial.println("TYPE: " + fbdo.dataType());
        //Serial.print("VALUE : ");
        //Serial.println(fbdo.to<int>());
        *output = fbdo.to<int>(); 
      }
      else {
        WebSerial.print("FAILED reading ");
        WebSerial.println(param_name);
        Serial.printf("FAILED reading %s", param_name);
        WebSerial.println("REASON: " + fbdo.errorReason());
        Serial.println("REASON: " + fbdo.errorReason());
      }  
}

void readRealTimeDB_ValueBool(const char *param_name, bool *output) {
  char start_str[150] = FILE_PATH;
      if (Firebase.RTDB.getBool(&fbdo, strcat(start_str, param_name))) {
        //Serial.println("READ: " + param_name + " succesfully");
        //Serial.println("PATH: " + fbdo.dataPath());
        //Serial.println("TYPE: " + fbdo.dataType());
        //Serial.print("VALUE : ");
        //Serial.println(fbdo.to<int>());
        *output = fbdo.to<bool>(); 
      }
      else {
        WebSerial.println("FAILED reading");
        WebSerial.println(param_name);
        Serial.printf("FAILED reading %s", param_name);
        WebSerial.println("REASON: " + fbdo.errorReason());
        Serial.println("REASON: " + fbdo.errorReason());
      }  
}

void updateRealTimeDB_ValueInt(const char *param_name, int value) {
  char start_str[150] = FILE_PATH;
  if (Firebase.RTDB.setInt(&fbdo, strcat(start_str, param_name), value)) {
    Serial.println("PASSED");
    Serial.println("PATH: " + fbdo.dataPath());
    Serial.println("TYPE: " + fbdo.dataType());
  }
  else {
    WebSerial.println("FAILED UPDATING INT");
    WebSerial.println(param_name);
    Serial.printf("FAILED updating %s", param_name);
    WebSerial.println("REASON: " + fbdo.errorReason());
    Serial.println("REASON: " + fbdo.errorReason());
  }
}

void updateRealTimeDB_ValueString(const char *param_name, const char* value){
  char start_str[150] = FILE_PATH;
  if (Firebase.RTDB.setString(&fbdo, strcat(start_str, param_name), value)){
    Serial.println("PASSED");
//    Serial.println("PATH: " + fbdo.dataPath());
//    Serial.println("TYPE: " + fbdo.dataType());
  } else {
    Serial.println("FAILED");
    Serial.println("REASON: " + fbdo.errorReason());
  }
}
//-----------------------------------------------------------------------------
//------------------------------Motors-----------------------------------------
void readMotorsDB_Commands() {
    readRealTimeDB_ValueInt("speed", &vSpeed);   
    
    readRealTimeDB_ValueBool("forward", &forward);
    
    readRealTimeDB_ValueBool("backwards", &backward);
    
    readRealTimeDB_ValueBool("left", &left);
    
    readRealTimeDB_ValueBool("right", &right);
}
//-----------------------------------------------------------------------------
AsyncWebServer server(80);

void recvMsg(uint8_t *data, size_t len){
  WebSerial.println("Received Data...");
  String d = "";
  for(int i=0; i < len; i++){
    d += char(data[i]);
  }
  WebSerial.println(d);
}

int tmp_robot_mode;
int tmp_user_charge;
const TickType_t xDelay = portTICK_PERIOD_MS;

void thread_read_state(void* param){
  while(true){
    if (Firebase.ready()){
      xSemaphoreTake(mutex, portMAX_DELAY);
      readRealTimeDB_ValueInt("state", &tmp_robot_mode);
      xSemaphoreGive(mutex);
      vTaskDelay(300 / xDelay);
      xSemaphoreTake(mutex, portMAX_DELAY);
      readRealTimeDB_ValueInt("go_charge", &tmp_user_charge);
      xSemaphoreGive(mutex);
      vTaskDelay(300 / xDelay);
      if(tmp_robot_mode == MANUAL){
        //Serial.println("taking mutex");
        xSemaphoreTake(mutex, portMAX_DELAY);
        readMotorsDB_Commands();
        xSemaphoreGive(mutex);
        //Serial.println("releasing mutex");
      }
    }
    xSemaphoreTake(mutex2, portMAX_DELAY);
    robotMode = tmp_robot_mode;
    //Serial.printf("robot mode: %d\n", robotMode);
    user_charge = tmp_user_charge;
    xSemaphoreGive(mutex2);
    if(tmp_robot_mode == AUTONOMOUS){
      //delay(3000);
      vTaskDelay(3000 / xDelay);
    }
    //vTaskDelay(50 / xDelay);
  }
}

void havhav(){
  pinMode(2, OUTPUT);
  for(int i=0; i<4; i++){
    delay(500);
    digitalWrite(2,HIGH);
    delay(500);
    digitalWrite(2,LOW);
  }
}

void setup() {
  havhav();
  //delay(5000);
  Serial.begin(115200); // Serial port for debugging purposes
  time(&lastChargeTime);
  Serial.println("**STARTING ESP SETUP**");
  // Connect to WiFi & setupWebSerial
  connectToWiFi(); 
  WebSerial.begin(&server);
  WebSerial.msgCallback(recvMsg);
  server.begin();
  // Setting up distance sensors
  setupDistanceSensors();
  //setup motors and charging sensor
  setupMotorPins();
  setupChargeDetection();
  autonomous_in_charge = false;
  // Connect to Firebase 
  while(!signupOK)
    FirebaseSetup();   
  //set corner number  
  readRealTimeDB_ValueInt("corners_number", &cornerNumber);
  readRealTimeDB_ValueInt("charge_interval", &charging_interval);
  readRealTimeDB_ValueInt("charge_forward_delay", &charging_forward_delay);
  readRealTimeDB_ValueInt("charge_back", &charging_back_delay);
  readRealTimeDB_ValueInt("charging_time", &charging_time);
  updateRealTimeDB_ValueString("esp32_ip", WiFi.localIP().toString().c_str());

  TaskHandle_t xHandle = NULL;
  mutex = xSemaphoreCreateMutex();
  mutex2 = xSemaphoreCreateMutex();
  xTaskCreate(thread_read_state, "rfirebase", 40000, NULL, tskIDLE_PRIORITY, &xHandle);
  configASSERT(xHandle);
  
  //delay(5000);
  WebSerial.println("**FINISHED ESP SETUP**");
}

bool need_to_charge;
bool charge_succ;

void loop() {
  stopEngine();
  vTaskDelay(50 / xDelay);
  if (Firebase.ready()) {
    //WebSerial.println("firebase is ready");
    //Serial.println("taking mutex 2");
    xSemaphoreTake(mutex2, portMAX_DELAY);
    curr_robot_mode = robotMode;
    curr_user_charge = user_charge;
    xSemaphoreGive(mutex2);
    //Serial.println("releasing mutex2");
    if (curr_robot_mode == AUTONOMOUS && lastState == MANUAL){
      WebSerial.println("zeroing current corner number (switched from manual to autonomous");
      currCornerNumber = 0;
    }         
    if (curr_robot_mode == MANUAL) {
      //Serial.println("trying to catch manual mutex");
      xSemaphoreTake(mutex, portMAX_DELAY);
      tmp_speed = vSpeed;
      tmp_back = backward;
      tmp_right = right;
      tmp_left = left;
      tmp_forward = forward;
      xSemaphoreGive(mutex);
      //Serial.println("did it");
      setMotorsValueByCommand(MANUAL_DRIVE_DELAY, tmp_speed, tmp_back, tmp_right, tmp_left, tmp_forward);
      need_to_charge = need_charging();
      if(need_to_charge == true){
        xSemaphoreTake(mutex, portMAX_DELAY);
        updateRealTimeDB_ValueInt("low_battery", 1);
        xSemaphoreGive(mutex);
      }
    } else if (curr_robot_mode == AUTONOMOUS) {
        if (autonomous_in_charge == true) {
          time(&currentTime);                                  // Sample current time
          if ((currentTime - startChargeTime) > charging_time){  // Check if we done chargeing 
            lastChargeTime = currentTime;                      // Update last charge time             
            WebSerial.println("Go Backward exit charging station");
            motors->drive(-1.0, -1.0, charging_back_delay); 
            turn_90_degree_left();
            autonomous_in_charge = false;
            xSemaphoreTake(mutex, portMAX_DELAY);
            updateRealTimeDB_ValueInt("currently_charging", 0);
            xSemaphoreGive(mutex);
          }
        } else {
          //WebSerial.println("entering autonomous movement");  
          // Sample distance sensors
          int distanceRightSense = readDistanceRight(); //distance of sensor 1
          int distanceFrontSense = readDistanceFront(); //distance of sensor 2      
          // In case we in corner and needs to charge -> handle it.
          need_to_charge = need_charging();
          if(need_to_charge == true){
            xSemaphoreTake(mutex, portMAX_DELAY);
            updateRealTimeDB_ValueInt("low_battery", 1);
            xSemaphoreGive(mutex);
          }
          if (chargingHandle(distanceFrontSense, curr_user_charge, need_to_charge)) {
            //Serial.println("taking mutex before charging");
            xSemaphoreTake(mutex, portMAX_DELAY);
            updateRealTimeDB_ValueInt("go_charge", 0);
            xSemaphoreGive(mutex);
            charge_succ = move_into_charging_position();
            xSemaphoreTake(mutex, portMAX_DELAY);
            if(!charge_succ){
              updateRealTimeDB_ValueInt("charge_error", 1);
            }
            xSemaphoreGive(mutex);
            if(!charge_succ){
              vTaskDelay(1000000 / xDelay);
            }
            //Serial.println("releasing mutex after charging");
            autonomous_in_charge = true;
            xSemaphoreTake(mutex, portMAX_DELAY);
            updateRealTimeDB_ValueInt("currently_charging", 1);
            xSemaphoreGive(mutex);
          }              
          if (autonomous_in_charge == false) { // Initinalize motors accordingly to the sensors (correction of movement according to the data)
            setMotorsValueBySensors(distanceRightSense, distanceFrontSense);
          } 
        }       
      }      
    }
   else {
    WebSerial.println("Error: Firebase connection error");
    delay(NO_FIREBASE_DELAY); // The state sample delay
  }
  lastState = curr_robot_mode;
}
