#define echoPin 2
#define trigPin 3
char Bluetooth_moudule ;
long duration;
int distance;
int mode ;
const byte IR_RECEIVE_PIN = 2;
int Max_depth_distance = 4;
const int ENA = A1;
const int ENB = A0;
const int IN1 = 9;
const int IN2 = 10;9
const int IN3 = 11;
const int IN4 = 12;
const int sound = 7;
const int led = A5;
const int motorspeed = 250 ;
float turn_delay = 400;//350
float walk_delay = 10;//350 
void Mbreak() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}
void front() {
  analogWrite(ENA, motorspeed);
  analogWrite(ENB, motorspeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}

void back() {
  analogWrite(ENA, motorspeed);
  analogWrite(ENB, motorspeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}

void right() {
  analogWrite(ENA, motorspeed);
  analogWrite(ENB, motorspeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}
void left() {
  analogWrite(ENA, motorspeed);
  analogWrite(ENB, motorspeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}



void Read() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

}




void setup()
{
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(6, INPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);



  // TODO you setup code

}

void loop()
{
  Read();
  mode = digitalRead(4);
  Serial.println(mode);
  if(mode==0){
    
     if(distance>2){
      front();
    }
    else if(distance<2){
      Mbreak();
      delay(100);
      back();
      delay(500);
      right();
      delay(500);
    }

    
    
  }
  
  if(mode==1){
   
    if (Serial.available()) {
    Bluetooth_moudule = Serial.read();
    Serial.println(Bluetooth_moudule);
  }
  if (Bluetooth_moudule == 'F') {          
    front();
  }

  else if (Bluetooth_moudule == 'B') {    
    back();
  }

  else if (Bluetooth_moudule == 'L') {    
    left();
  }
  else if (Bluetooth_moudule == 'G') {    
    left();
  }
  else if (Bluetooth_moudule == 'H') {    
    left();
  }


  else if (Bluetooth_moudule == 'R') {    
    right();
  }

  else if (Bluetooth_moudule == 'L') {    
    right();
  }
  else if (Bluetooth_moudule == 'J') {    
  }

  

  else if (Bluetooth_moudule == 'S') {    
    Mbreak();
  }
    
  
  
  }
  
}
