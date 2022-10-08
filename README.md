# Coding Minion
A robotic minion that can scan barcodes, move parallel to the wall, turn 90, 180 degree, blink, sing and dance.


# Goal 
A robotic minion that solves mazes with the help of the user's programming. The minion walks straight, and when it hits a wall or a junction, it turns to the right or left or forward and continues to walk. The direction of rotation is determined according to a program that the user "programs" by arranging colored cards containing barcodes. The entire programming is done before starting the trip by scanning the barcodes. If there is a mistake, the user rearranges the cards and scans again.


## Backstory
This repo is the product of the course 236333 - Project in IoT, at the Technion university. This project was created by Nadeen Bawardi, Banan Ashkar, Dalal Eghbaria and guided with the help of Tom Sopher, Itay Dabran and Natali Uda.


## System Parts 
* ESP32 Dev Module.
* 3 VL53L1X Distance Sensors.
* GM65.
* Buzzer.
* 3 RGB leds.
* 2 white leds.
* 14 resistors.
* Two Adafruit N20 DC Motors.
* L298 motors driver.
* Two 3D-Printed wheels.
* Two guiding rolling wheels.
* Minion skeleton (Handmade, as shown [here](https://www.youtube.com/watch?v=xytOwOuyp5M)).
* Silver power bank miracase.
* On/Off switcher.


## Used Libraries
The external libraries used in the project are:
* [VL53L1X](https://www.arduino.cc/reference/en/libraries/vl53l1x/)
* [ESP32 analogWrite](https://www.arduino.cc/reference/en/libraries/esp32-analogwrite/)
* [L298N](https://www.arduino.cc/reference/en/libraries/l298n/)


## Helping Links //////////
Links that helped us to deal with the sensors:

| Sensor | Links |
| ---- | ----------- |
| VL53L1X Distance Sensors | (https://github.com/pololu/vl53l1x-arduino) 
(https://youtu.be/dzbGmIZv26E)
(https://microcontrollerslab.com/esp32-i2c-communication-tutorial-arduino-ide/#Using_Multiple_I2C_Devices_with_ESP32_same_addresses)
(https://randomnerdtutorials.com/esp32-i2c-communication-arduino-ide/) |
| 4 | - |
| 5 | - |
| 6 | - |
| 7 | - |
| 8 | - |
| 9 | - |
| 11 | - |
| 12 | - |
| 13 | - |
| 14 | - |


## Contributors
* Nadeen Bawardi
* Banan Ashkar
* Dalal Eghbaria















תיעוד להפעלת הפרויקט או שכפול שלו   - להשתמש ב-WIKI המובנה של GITHUB (מומלץ) או לשים קבצים  בתיקיית documentation  מסוג MarkDown,  WORD (עדיף) או PDF 
דיאגרמת חיבורים (הכנתם בתחילת סמסטר, יש לעדכן אותה אם היו שינויים)
הוראות התקנה / קומפילציה - אם יש (אפשר גם בסוף ה-README)
דאטה ותוצאות של ניסוי ולידציה שעשיתם. אם יש בעיה של מקום שימו קישור לתיקיית ONEDRIVE או משהו דומה.

 UNIT TESTS  - אם יש לכם חיישנים או אבזרי חומרה , שימו את קוד הבדיקה בתיקייה Unit Tests  זה יכול גם לשמש אתכם במקרה של תקלה לבדוק אבזרי חומרה בשיטת האלימינציה. אפשר גם לשים קוד נסיון לממשקים שונים של שירותי ענן כגון Firebase .

תיעוד ממשק משתמש
סטטוסים - אם יש סטטוסים שונים למערכת, מה השמות שלהם ואיך הם מיוצגים בממשק משתמש (כולל סטטוסים של שגיאות ותקלות). אם יש סטטוס שמיוצג על ידי ממשק המשתמש ציינו איך ( הודעה בצג, צבע של נורה, ממשק משתמש באפליקציה)
פרמטרים - רשימת פרמטרים שניתן לקנפג בפרויקט בעזרת ממשק משתמש, בעזרת קובץ פרמטרים או ישירות בקוד - מומלץ הסבר קצר על כל אחד. אם יש הרבה, אז ה-15 המשמעותיים ביותר לדעתכם.
הנחיות לכיול - קליברציה (אם יש בפרויקט)
