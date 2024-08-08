 // Elboghdady car 
 
#include <IRremote.h>


 const int ENA = A1;
 const int ENB = A2;
 const int sound = 4;
 const int whiteleds = 5;
 const int IN1 = A3;
 const int IN2 = A4;
 const int IN3 = A5;
 const int IN4 = A6;
 const  int motorspeed = 255 ;
 int sensor;
const byte IR_RECEIVE_PIN = 2;


void front_direction(){
  analogWrite(ENA,motorspeed);
  analogWrite(ENB,motorspeed);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW); 
 
}

void back_direction(){
 analogWrite(ENA,motorspeed);
  analogWrite(ENB,255);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH); 
  
}

void right_direction(){
 analogWrite(ENA,motorspeed);
  analogWrite(ENB,motorspeed);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);  
  
}


void left_direction(){
  analogWrite(ENA,motorspeed);
  analogWrite(ENB,motorspeed);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW); 
  
}

void motor_break(){
 analogWrite(ENA,0);
  analogWrite(ENB,0);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW); 
  
}

void setup() {
 Serial.begin(250000);
  Serial.println("IR Receive test");
   IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
 pinMode(ENA,OUTPUT);
 pinMode(ENB,OUTPUT);
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT); 
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
 pinMode(sound,OUTPUT);
 pinMode(whiteleds,OUTPUT);
 pinMode(3,INPUT);
 
 
 digitalWrite(sound,HIGH);
 digitalWrite(whiteleds,HIGH);
 delay(500); 
digitalWrite(whiteleds,LOW);
 digitalWrite(sound,LOW);
 delay(500);
 digitalWrite(whiteleds,HIGH);
 digitalWrite(sound,HIGH);
 delay(500); 
 digitalWrite(whiteleds,LOW);
 digitalWrite(sound,LOW);
}

void loop() {
  sensor = digitalRead(3);
 
   if (IrReceiver.decode())
   {
      String ir_code = String(IrReceiver.decodedIRData.command, HEX);
      Serial.println(ir_code);



      
   // direction
   
      if(ir_code == "e")
        front_direction();
   
      
      if(ir_code == "a")
        back_direction();
      if(ir_code == "12")
       right_direction();
      if(ir_code == "1a")
        left_direction();
        if(ir_code == "6")
        motor_break();


   
    


    //leds

    if(ir_code == "8")
       digitalWrite(whiteleds,HIGH);     
       
 if(ir_code == "1c")
       digitalWrite(whiteleds,LOW); 
            

      // sound 

      if(ir_code == "13")
       digitalWrite(sound,HIGH); 
       delay(250);
       digitalWrite(sound,LOW);      
      
    
       
    
      

      
      IrReceiver.resume();
   }

 if(sensor == 0)
        motor_break();  

}
