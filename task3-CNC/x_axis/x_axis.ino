#include <Servo.h>

#include <Stepper.h>
 
const int stepsPerRevolution = 20; 
 
//Connection pins:
//Stepper myStepperY(stepsPerRevolution, 2,6,4,5);
Stepper myStepperX(stepsPerRevolution, 8,9,10,11); 
 Servo myservo; 
 int pos = 0; 
void setup() {
 //Set speed:
 myStepperX.setSpeed(100);
 //myStepperY.setSpeed(100);
 //max 250 steps for dvd/cd stepper motors 
 //myStepperX.step(160);
 // myStepperX.step(160);
  //delay(1000);
 myservo.attach(6);  // attaches the servo on pin 9 to the servo object
   // tell servo to go to position in variable 'pos'
  //delay(15); 
  //myservo.write(50);
  //delay(15); 
 //myStepperY.step(160); 
//myservo.write(25); // tell servo to go to position in variable 'pos'
//   delay(15);
// myservo.write(50); // tell servo to go to position in variable 'pos'
 // delay(15);
 }
 
void loop() {
 
 myStepperX.step(100);
 delay(100);
 for (pos = 30; pos <= 50; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 50; pos >= 30; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
 /*myservo.write(POS);
 delay(15);
  myservo.write(0);
 delay(15);*/
  myStepperX.step(-100);
 delay(100);
  for (pos = 30; pos <= 50; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
/* myservo.write(5);
 delay(15);
  myservo.write(0);
 delay(15);*/
 /*for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);  */                     // waits 15ms for the servo to reach the position
  }
 
 

