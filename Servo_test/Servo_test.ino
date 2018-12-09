/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
Servo myservo1;
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(34);  // attaches the servo on pin 9 to the servo object 
  myservo1.attach(40);
  Serial.begin(9600);
} 
 
void loop() 
{ 
   /*myservo.write(180);             // tell servo to go to position in variable 'pos' 
   delay(15);
   myservo1.write(180);             // tell servo to go to position in variable 'pos' 
   delay(15);  
   */
  for(pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);
    Serial.println(pos);
    delay(50);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos); 
    Serial.println(pos);
    delay(50);                       // waits 15ms for the servo to reach the position 
  }
  
} 
