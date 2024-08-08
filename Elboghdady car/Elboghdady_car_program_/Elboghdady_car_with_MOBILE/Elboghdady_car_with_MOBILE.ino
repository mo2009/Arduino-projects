/*
   -- Elboghdady_car --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.7 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.10.2 or later version;
     - for iOS 1.8.2 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL_RX 2
#define REMOTEXY_SERIAL_TX 3
#define REMOTEXY_SERIAL_SPEED 9600
#define REMOTEXY_ACCESS_PASSWORD "Elboghdady"


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,7,0,0,0,140,0,15,30,2,
  1,0,84,4,12,12,10,9,12,12,
  36,31,76,101,100,115,0,1,0,7,
  4,12,12,26,10,12,12,36,31,83,
  111,117,110,100,0,1,0,19,18,12,
  12,19,22,12,12,26,31,0,1,0,
  34,34,12,12,26,34,12,12,26,31,
  0,1,0,4,33,12,12,8,35,12,
  12,26,31,0,1,0,19,49,12,12,
  24,51,12,12,26,31,0,129,0,39,
  20,57,10,47,59,18,6,6,69,108,
  98,111,103,104,100,97,100,121,0,129,
  0,59,34,18,11,53,41,18,6,6,
  67,97,114,0,1,0,19,34,12,12,
  20,34,12,12,26,31,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t Leds; // =1 if button pressed, else =0 
  uint8_t Sound; // =1 if button pressed, else =0 
  uint8_t Front; // =1 if button pressed, else =0 
  uint8_t Right; // =1 if button pressed, else =0 
  uint8_t Left; // =1 if button pressed, else =0 
  uint8_t Back; // =1 if button pressed, else =0 
  uint8_t Break; // =1 if button pressed, else =0 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//    MY coding , voids and integrs        //
/////////////////////////////////////////////
 const int ENA = 11;
 const int ENB = 10;
 const int sound = A0;
 const int whiteleds = A3;
 const int IN1 = 9;
 const int IN2 = 8;
 const int IN3 = 7;
 const int IN4 = 6;
 const  int motorspeed = 255 ;
 int lightsensor ;


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
  analogWrite(ENB,motorspeed);
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

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////



void setup() 
{
  RemoteXY_Init (); 
  pinMode(A0,OUTPUT);
 pinMode(10,OUTPUT);
 pinMode(11,OUTPUT);
 pinMode(A3,OUTPUT);
 pinMode(A4,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(A1,INPUT);
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
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();


  if( RemoteXY.Front == 1 ){
    
  front_direction();
    
  }


  if( RemoteXY.Back == 1 ){

   back_direction();
    
  }


  if( RemoteXY.Right == 1 ){
    right_direction();
    
  }


  if( RemoteXY.Left == 1 ){

    left_direction();
    
  }

  if( RemoteXY.Break == 1 ){

    motor_break();  
    
  }

  if( RemoteXY.Leds == 1 ){

    digitalWrite(whiteleds,HIGH); 
    
  }

  if( RemoteXY.Sound = 1 ){
    digitalWrite(sound,HIGH); 
    delay(250);
    digitalWrite(sound,LOW);  
  }

  
  
  
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 


}
