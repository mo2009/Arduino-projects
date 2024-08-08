void setup() {
   pinMode(13, OUTPUT);
   pinMode(12, OUTPUT);
   pinMode(11, OUTPUT);    
  
 

}

void loop() {
   //green led
   
      digitalWrite(13, HIGH); 
  delay(10000);                       
  digitalWrite(13, LOW);   
  
      
       // yellow led
    
       
      digitalWrite(12, HIGH); 
  delay(3000);                       
  digitalWrite(12, LOW);                  
      
//red led
        
      digitalWrite(11, HIGH); 
  delay(10000);                       
  digitalWrite(11, LOW);
      

    // yellow led
    
       
      digitalWrite(12, HIGH); 
  delay(3000);                       
  digitalWrite(12, LOW);      
                 
}
