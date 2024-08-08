
/*
  The circuit:
   LCD RS pin to digital pin 12
   LCD Enable pin to digital pin 11
   LCD D4 pin to digital pin 5
   LCD D5 pin to digital pin 4
   LCD D6 pin to digital pin 3
   LCD D7 pin to digital pin 2
   LCD R/W pin to ground
   LCD VSS pin to ground
   LCD VCC pin to 5V
   10K resistor:
   ends to +5V and ground
   wiper to LCD VO pin (pin 3)
*/

#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int Hours = 12 ;
int Minutes = 0 ;
int Secondes = 0 ;
int ButtonA;
int ButtonB;
int Start_button;
float Time = 1 ; // AM = 1 , PM = 0 .
int HC = 6;
int MC = 9;
int SC = 10;
void Button_read() {
  ButtonA = digitalRead(8);
  ButtonB = digitalRead(9);
  Start_button = digitalRead(10);
}
void TimeS(){
   if  (Time == 1 ) {
    lcd.setCursor(13, 0);
    lcd.print("AM");
  }

  if (Time == 0 ) {
    lcd.setCursor(13, 0);
    lcd.print("PM");
  }
  
}
void Clock_manual_determine() {
  if (ButtonA == 0) {
    Hours = (Hours - 1);

  }
  if (ButtonB == 0) {
    Hours = (Hours + 1);
  }
}

void Clock_utomatic_determine(){
  if (Secondes == 60) {
    Minutes = (Minutes + 1);
    Secondes = (Secondes - 60);
  }
  if (Minutes == 60) {
    Hours = (Hours + 1);
    Minutes = (Minutes - 60 );
  }

  if (Hours == 13 && Time == 1 ) {
    Hours = (Hours - 12);
    Time = (Time - 1);
  }
  if (Hours == 13 && Time == 0 ) {
    Hours = (Hours - 12);
    Time = (Time + 1);
  }
  
}

void logo() {
  lcd.setCursor(10, 1);
  lcd.print("mo2009");
}
void setup() {
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(5, 0);
  lcd.print("Welcome");
  delay(1000);
  lcd.clear();
}


void loop() {
  Button_read();
  Clock_manual_determine();
  lcd.clear();
    lcd.setCursor(HC, 0);
    lcd.print(Hours);
    lcd.setCursor(8, 0);
    lcd.print(":");
    lcd.setCursor(MC, 0);
    lcd.print(Minutes);
    TimeS();
    logo();
  if (Start_button == 0) {
    //Mean_code
    lcd.clear();
    lcd.setCursor(HC, 0);
    lcd.print(Hours);
    lcd.setCursor(8, 0);
    lcd.print(":");
    lcd.setCursor(MC, 0);
    lcd.print(Minutes);
    TimeS();
    logo();
    delay(1000);
    Secondes=(Secondes+1);
    Clock_utomatic_determine();
    
   
    
    
    if(Hours <10){
       HC=7;
    }
    if(Hours >10){
       HC=6;
    }
    

  }
}
