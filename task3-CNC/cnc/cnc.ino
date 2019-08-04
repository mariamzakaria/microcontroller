#include <Vector.h>
#include <SoftwareSerial.h>
#include <Servo.h>
#include <Stepper.h>

const int stepsPerRevolution = 20; 
 
// Connection pins:
Stepper myStepperX(stepsPerRevolution, 8,9,10,11);
Stepper myStepperY(stepsPerRevolution, 2,3,4,5);

SoftwareSerial mySerial(0 , 1); // RX, TX
char var;
String temp,incomingData;
Vector<double> xReadings;
Vector<double> yReadings;

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);
  
  //Servo
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object
  myservo.write(25); // tell servo to go to position in variable 'pos'
  
 // Stepper
 myStepperY.setSpeed(200);
 myStepperY.setSpeed(200);
}
void loop()
{
  if (mySerial.available())
  {
    var = mySerial.read();
    temp = String(var);
    if(var == 'x')
    {
      xReadings.push_back(incomingData.toInt());
      Serial.println("x= "+incomingData);
      incomingData="";
    }
     else if(var == 'y')
    {
      yReadings.push_back(incomingData.toInt());
      Serial.println("y= "+incomingData);
      incomingData="";
    }
    else if(var == 'e')
    {
      plot();
      //xReadings.clear();
     // yReadings.clear();
      Serial.println("end");
      incomingData="";
    }
    else 
    {
      incomingData+=temp;
//    Serial.println(incomingData);
    }
  }
}
void plot()
{
  for (int i =0 ; i <= xReadings.size(); i++)
  {
    //if(i==0)
   //  {
       for (pos = 50; pos >= 30; pos -= 1) 
       { 
        // in steps of 1 degree
        myservo.write(pos);              
        delay(15);                       
       }
   // }
     if( i==1){
     int xStep = map(xReadings[i],0,1,10,250);
     myStepperX.step(xStep);
       delay(150); 
     }
      if( i==2){
     int yStep = map(yReadings[i],0,1,10,250);
     myStepperY.step(yStep); 
     delay(150);
      }

       if( i==3){
     int xStep = map(xReadings[i],0,1,10,250);
     myStepperX.step(-xStep); 
      delay(150);
     }
      if( i==4){
     int yStep = map(yReadings[i],0,1,10,250);
     myStepperY.step(-yStep); 
     delay(150);
      }

      
  }
  for (pos = 30; pos <= 50; pos += 1) 
  { 
    // in steps of 1 degree
    myservo.write(pos);              
    delay(15);                       
  }
}
