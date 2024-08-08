#include <IRremote.h> // add IR remote library

const byte IR_RECEIVE_PIN = 2;   // pin for the IR sensor

void setup()
{
  Serial.begin(115200); // initialize serial communication
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
 
}
void loop() 
{
  if(IrReceiver.decode()) // when button is pressed and code is received
  {
      String ir_code = String(IrReceiver.decodedIRData.command, HEX);
      if(ir_code != "0"){
        Serial.println(ir_code);
      }

   
    if(ir_code=="c")
    {
      digitalWrite(ledo,HIGH);
    }

    if(ir_code=="18")
    {
      digitalWrite(ledt,HIGH);
    }

    if(ir_code=="5e")
    {
      digitalWrite(ledth,HIGH);
    }
   if(ir_code=="16")
    {
      digitalWrite(ledo,LOW);
       digitalWrite(ledt,LOW);
        digitalWrite(ledth,LOW);
    }
  
    
    IrReceiver.resume();     // again be ready to receive next code
  }
  
}
