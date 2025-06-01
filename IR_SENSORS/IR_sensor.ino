#define D3 3
#define DA5 A5
#define D13 13
#define D2 2
#define d8 8
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
//IR
void setup() {
  // put your setup code here, to run once:
  pinMode(A4,OUTPUT);
  pinMode(3,INPUT);
  pinMode(A5,OUTPUT);
  pinMode(4,INPUT);


}



void loop()
{

 if (digitalRead(3)==HIGH)
{
  digitalWrite(13,HIGH);
  // delay(10); 
                       // wait for a second
    lcd.init();                      // initialize the lcd 
    // lcd.init();
  // Print a message to the LCD.
    lcd.backlight();
  lcd.setCursor(0,0);
  // printing slot status
    lcd.print("Slot1:EMPTY");
    delay(0);
}
 else{
  digitalWrite(13,LOW);
  // delay(10);
  lcd.init();                      // initialize the lcd 
  // lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("slot1: parked");
  
}
{
 if (digitalRead(2)==HIGH)
{
  digitalWrite(10,HIGH);
  delay(0); 
                       // wait for a second
    lcd.init();                      // initialize the lcd 
    // lcd.init();
  // Print a message to the LCD.
    lcd.backlight();
  lcd.setCursor(0,1);
  // printing slot status
    lcd.print("Slot2: EMPTY");
    delay(0);
}
 else{
  digitalWrite(10,LOW);
  delay(0); //1000 = 1 SECOND 
  lcd.init();                      // initialize the lcd 
  // lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,1);
  lcd.print("slot2: parked");
  delay(0);
  
}
}
}



