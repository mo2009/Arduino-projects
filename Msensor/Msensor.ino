
  #define echoPin 2 
  #define trigPin 3 

  long duration; 
  int distance; 
  int firstread ;
  const int action = 11;
  
void setup() {    
 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(4,INPUT);
  pinMode(action,OUTPUT);
  Serial.begin(9600); 

  // first read 

  digitalWrite(trigPin, LOW);
  delayMicroseconds(10000000);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10000000);
  
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
   delayMicroseconds(3000000);
  
  firstread  = duration * 0.034 / 2; 
  
  Serial.print("Distance: ");
  Serial.print(firstread);
  Serial.println(" cm");

}

void loop() {

 
 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.034 / 2; 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");


  // the code

   if(distance < firstread-3 ){

    digitalWrite(action,HIGH);
    delay(400);
    digitalWrite(action,LOW);
   }

   
      
     
 
}
