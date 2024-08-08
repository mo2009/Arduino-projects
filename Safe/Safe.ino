#include <LiquidCrystal.h>
#include <Servo.h>
Servo myservo;
const int rs = 12, en = 11, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int PO =  9;
const int PT =  9;
const int PTH = 9;
int NO ;
int NT ;
int NTH ;
int BO ;
int BT ;
const int sound = 2 ; 
  

void setup()
{
  lcd.begin(16, 2);
  myservo.attach(9);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);  
  pinMode(7,INPUT);
  pinMode(8,INPUT);  
  pinMode(2,OUTPUT);
  myservo.write(0);
  lcd.print("welcome back");
  delay(120);
  lcd.clear();
 
}

void loop()
{
  lcd.setCursor(2, 0);
  lcd.print("Tech masters");
  BO = digitalRead(7);
  BT = digitalRead(8);
  NO = analogRead(A0);
  NT = analogRead(A1);
  NTH = analogRead(A2);  
  NO = map(NO,0,1023,0,9);
  NT = map(NT,0,1023,0,9);
  NTH = map(NTH,0,1023,0,9);
  lcd.setCursor(0, 1);
  lcd.print("Password : ");
  lcd.setCursor(11, 1);
  lcd.print(NO);
  lcd.setCursor(13, 1);
  lcd.print(NT);
  lcd.setCursor(15, 1);
  lcd.print(NTH);
  if(BO == 0){
  if(NO == PO && NT == PT && NTH == PTH){
    //correct
    digitalWrite(sound,LOW);
    myservo.write(90);
  }
  
  if(NO != PO && NT != PT && NTH != PTH ||  NO != PO && NT == PT && NTH == PTH ||  NO == PO && NT != PT && NTH == PTH || NO == PO && NT == PT && NTH != PTH || NO != PO && NT == PT && NTH != PTH || NO != PO && NT != PT && NTH == PTH || NO == PO && NT != PT && NTH != PTH || NO != PO && NT == PT && NTH == PTH  ){
    digitalWrite(sound,HIGH);
    myservo.write(0);

  }
  }
if(BT == 0){
      myservo.write(0);

}
  
 
}
