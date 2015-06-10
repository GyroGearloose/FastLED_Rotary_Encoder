/*
Read regular Rotary Encoder
This sketch can also be used for motors with Hall sensors  

Interrupts:
Board         int.0 int.1 int.2 int.3 int.4 int.5 
Uno, Ethernet   2     3         
Mega2560        2     3    21    20     19   18 

For two Hall Sensors / two Motors / two Rotary Encoders a Mega2560 or Teensy 3.1 is needed!
J.Bruegl, June 2015
*/

#define encoder0PinA_M1 2                    // Encoder A
#define encoder0PinB_M1 3                    // Encoder B
volatile int encoder0Pos_M1 = 0;             // also negative values
byte count = 0;
byte lastCount = 0; 
#define MAX_ENCODER_VAL  10                  // defines how many steps the encoder shall deliver
                                             // e.g. 0..10

void setup () {
  pinMode(encoder0PinA_M1, INPUT);
  pinMode(encoder0PinB_M1, INPUT);
  digitalWrite(encoder0PinA_M1, HIGH);       // use internal pull-ups
  digitalWrite(encoder0PinB_M1, HIGH);  
  attachInterrupt(1, doEncoderA_M1, CHANGE); // encoder pin on interrupt 0 (pin  2)
  attachInterrupt(0, doEncoderB_M1, CHANGE); // encoder pin on interrupt 1 (pin  3) 
  
  Serial.begin(115200);
}

void loop()      {

// set the upper and lower limits for counting 
      if (encoder0Pos_M1 > MAX_ENCODER_VAL)            // this limits the encoder max value 
          encoder0Pos_M1 = MAX_ENCODER_VAL;
  
      if (encoder0Pos_M1 < 0)                          // this limits the encoder max value 
          encoder0Pos_M1 = 0;

      count = encoder0Pos_M1;
      bool trigger = 0;
      if (count != lastCount) trigger = 1;            // if it's changed, trigger the different events

   switch (count)  {
 
     case 0:
       if (trigger) {
       Serial.println("ZERO");
       // put here your light effect
       }
     break; 

     case 1:
       if (trigger) {
       Serial.println("ONE");

       }
     break; 

     case 2:
       if (trigger) {
       Serial.println("TWO");
     
       }
     break; 

     case 3:
       if (trigger)  {
       Serial.println("THREE");
     
       }
     break; 

     case 4:
       if (trigger)  {
       Serial.println("FOUR");

       }
     break; 

     case 5:
      if (trigger)  {
      Serial.println("FIVE");

       }
     break; 

     case 6:
       if (trigger) {
       Serial.println("SIX");

       }
     break; 

     case 7:
       if (trigger)  {
       Serial.println("SEVEN");

       }
     break; 

     case 8:
       if (trigger)  {
       Serial.println("EIGHT");

       }
     break; 

     case 9:
       if (trigger)  {
       Serial.println("NINE");

       }
     break; 

     case 10:
       if (trigger)  {
       Serial.println("TEN");

       }
     break; 
   }

   lastCount = count;        // reset the counter
   trigger = 0;              // and re-arm the trigger  

     delay(30);
}
 
 //-----------------------------------------------------------------------------------------------------
void doEncoderA_M1(){

if (digitalRead(encoder0PinA_M1) == HIGH) {      // look for a low-to-high on channel A
   if (digitalRead(encoder0PinB_M1) == LOW) {    // check channel B to see which way encoder is turning
     encoder0Pos_M1 = encoder0Pos_M1 + 1;   }    // CW
      else {
      encoder0Pos_M1 = encoder0Pos_M1 - 1;  }    // CCW
   }

else  {                                          // must be a high-to-low edge on channel A                                      
   if (digitalRead(encoder0PinB_M1) == HIGH) {   // check channel B to see which way encoder is turning  
     encoder0Pos_M1 = encoder0Pos_M1 + 1;    }   // CW
      else {
     encoder0Pos_M1 = encoder0Pos_M1 - 1;    }   // CCW
      }
  }
void doEncoderB_M1(){


if (digitalRead(encoder0PinB_M1) == HIGH) {      // look for a low-to-high on channel B
   if (digitalRead(encoder0PinA_M1) == HIGH) {   // check channel A to see which way encoder is turning
     encoder0Pos_M1 = encoder0Pos_M1 + 1;    }   // CW
      else {
     encoder0Pos_M1 = encoder0Pos_M1 - 1;    }   // CCW
   }



else {                                           // Look for a high-to-low on channel B
    if (digitalRead(encoder0PinA_M1) == LOW) {   // check channel B to see which way encoder is turning  
     encoder0Pos_M1 = encoder0Pos_M1 + 1;    }   // CW
      else {
     encoder0Pos_M1 = encoder0Pos_M1 - 1;    }   // CCW
     }
} 
//-------------------------------------------------------------------------------------------------------
