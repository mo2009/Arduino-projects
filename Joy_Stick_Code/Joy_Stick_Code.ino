 
// Joy stick code
// x = A1
// y = A0
int xr;
int yr ;
const int red = 10;
const int blue = 11;
void setup() {
  pinMode(9,INPUT);    
  pinMode(A0,INPUT); 
  pinMode(A1,INPUT);
  digitalWrite(9,HIGH);
  pinMode(red,OUTPUT); 
  pinMode(blue,OUTPUT);
 Serial.begin(9600);

}

void loop() {

  // Center: yr==507 && yr==506 && xr==491 && xr==492

 // Front : yr==507 && yr==506 && yr==508 && xr==1023 

 // Back  : yr==507 && yr==506 && xr==0

 // Left  : yr==0 && xr==491 && xr==492

 // Right : yr==1023 && xr==491 && xr==492

  yr = analogRead(A0);
  xr = analogRead(A1);
  Serial.println("read");
  Serial.println(yr);
  Serial.println(xr);
  //centr
  if(yr==507&&  xr==491){
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
    }
    //.
    if(yr==507&&  xr==492){
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
    }
 //front
  if(yr==507 &&  xr==1023 ){
   digitalWrite(red,LOW);
    digitalWrite(blue,HIGH); 
  }
  //.
  if( yr==506  && xr==1023 ){
    digitalWrite(red,LOW);
    digitalWrite(blue,HIGH);
  }
  //.
  if( yr==508 && xr==1023 ){
    digitalWrite(red,LOW);
    digitalWrite(blue,HIGH);
  }
 //back
 if(yr==507 &&  xr==0){
  digitalWrite(red,HIGH);
    digitalWrite(blue,LOW);
 }
 //.
 if(yr==506 &&  xr==0){
  digitalWrite(red,HIGH);
    digitalWrite(blue,LOW);
 }

 
 // right 
  if(yr==1023 && xr==491 ){
    digitalWrite(red,HIGH);
    digitalWrite(blue,LOW);
    }
//.
  if(yr==1023&&  xr==492){
    digitalWrite(red,HIGH);
    digitalWrite(blue,LOW);
    }

    
    
    //left
    if(yr==0 && xr==491 ){
    digitalWrite(red,LOW);
    digitalWrite(blue,HIGH);
    }

   //.
   if(yr==0 && xr==492 ){
    digitalWrite(red,LOW);
    digitalWrite(blue,HIGH);
    }
}
