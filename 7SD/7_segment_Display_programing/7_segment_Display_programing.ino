
//.
void oo (){
  digitalWrite(6,HIGH);
  delay(1000);
  digitalWrite(6,LOW);
}

// 0
void cc(){
  digitalWrite(13,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
}
//1
void a(){

  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
  delay(1000);
   digitalWrite(9,LOW);
  digitalWrite(8,LOW);  
}

//2

void b (){
  digitalWrite(13,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(9,HIGH);
   digitalWrite(10,HIGH);
   delay(1000);
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(7,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
}

//3
void c(){ 
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(7,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);

  
}

//4
void d(){
  digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    delay(1000);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
  
}
///5
void e(){

  digitalWrite(13,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(7,LOW); 
    digitalWrite(8,LOW);
}
//6
void f (){

   digitalWrite(13,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    digitalWrite(7,LOW); 
}
//7
void g (){
digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
  
}
//8
void h(){
     digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);  
}
//9
void i (){

  digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(8,LOW);
    digitalWrite(7,LOW); 
}
void setup() {
  pinMode(6,OUTPUT);
  pinMode(13,OUTPUT );
  pinMode(12,OUTPUT );
  pinMode(11,OUTPUT );
  pinMode(10,OUTPUT );
  pinMode(9,OUTPUT );
  pinMode(8,OUTPUT );
  pinMode(7,OUTPUT);

}
void loop() {
a();
 delay(5000);

}
