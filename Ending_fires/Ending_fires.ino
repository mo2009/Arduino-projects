#include <Servo.h>  //include servo.h library
Servo myservo;
int pos = 0;    
const int sensor1 = 3;
const int sensor2 = 4;
const int pump = 5;
int sensor1Read;
int sensor2Read;
void put_off_fire() {
  digitalWrite(pump, HIGH);
  delay(500);
  for (pos = 60; pos <= 200; pos += 2) {
    myservo.write(pos);
    delay(10);
  }
  for (pos = 200 ; pos >= 60; pos -= 2) {
    myservo.write(pos);
    delay(10);
  }

}
void setup() {
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(pump, OUTPUT);
  myservo.attach(9);
  myservo.write(120); 
}

void loop() {
  sensor1Read = digitalRead(sensor1);
  sensor2Read = digitalRead(sensor2);
  if (sensor1Read==0) {
    put_off_fire();
  }
  if (sensor1Read==1) {
  digitalWrite(pump, LOW);
  myservo.write(120);
  }
}
