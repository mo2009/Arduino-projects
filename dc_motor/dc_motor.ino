const int motorA = A1 ;
const int right = 11 ;
const int left = 10 ;
int ro ;
int rt ;
int sppeed ;

void setup() {
  Serial.begin(9600);
  pinMode(motorA,OUTPUT);
  pinMode(right,OUTPUT);
  pinMode(left,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.println("made by moustafa elboghdady");
}

void loop() {
  Serial.println(sppeed);

sppeed=analogRead(A0);
sppeed=map(sppeed,0,1023,0,255);
 ro = digitalRead(3);
 rt = digitalRead(4);
analogWrite(motorA,sppeed);
if(ro= 0){
  pinMode(right,HIGH);
  pinMode(left,LOW);
  pinMode(13,HIGH);
}
if(rt = 0){
 pinMode(right,LOW);
  pinMode(left,HIGH);
  pinMode(12,HIGH); 
  
  }

}
