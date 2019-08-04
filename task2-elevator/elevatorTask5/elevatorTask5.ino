// this code for Task 5 

// the buttons of the floors
int up0 = 10;
int up1 = 2;
int up2 = 3;
int up3 = 4;
int down1 = 6; 
int down2 = 7;
int down3 = 8;
int down4 = 9;

// They are flags for changing the state
int x =0; int y =0; int z = 0; 

int ladder = 1; // to indicate if the selected button is for up (ladder = 1) or for down (ladder = 0)
int floors; // where i stand 
int currentElevator;

// Declaring functions before class to stop errors
void nearstPath(int currentFloor, int ladder);
void getMinPath(int x , int y, int z);
void getMinUpPath ( int floorElevator1, int floorElevator2 , int floorElevator3 ,int floors , int elevator1, int elevator2, int elevator3 );
void getMinDownPath ( int floorElevator1, int floorElevator2 , int floorElevator3 ,int floors , int elevator1, int elevator2, int elevator3 );
void requiredud ( int floors );

class elevator {
  
public: int state; // for the state of the elevator if it is  going up (1) or down (0) 
public:  int floorElevator;  // to indicate what floor the elevator exists
  
  //int upPin;
  //int downPin;
  
  long OnTime;     // milliseconds of on-time                 the time which the elevator would take to go up 
  long OffTime;    // milliseconds of off-time                the time which the elevator would take to go down 
  unsigned long previousMillis;   // will store last time elevator was updated


  // constructor to set the initial conditions of the elevators 
  public:
  elevator(//int up ,int down, 
  long on, long off , int currentFloor, int stateOfElevator)
  {
  //upPin = up;
  //downPin = down; 
  //pinMode(upPin, INPUT);     
  //pinMode(downPin, INPUT);     
  floorElevator = currentFloor;

  OnTime = on;
  OffTime = off; 
  
  state = stateOfElevator; //going up (1) or down (0)   
  previousMillis = 0; // setting 
  }
  
    void Update()
  {
     // check to see if it's time to change the state of the elevator
    unsigned long currentMillis = millis();
    
    if (digitalRead(up0) == HIGH )//&& (currentMillis - previousMillis >= OnTime)) 
    {
      floors = 0; int ladder = 1;
      nearstPath(floors, ladder);
      previousMillis = currentMillis;  // Remember the time
      }
      
      else if ((digitalRead(up0) == LOW)) //&& (currentMillis - previousMillis >= OffTime))
    {
      previousMillis = currentMillis;   // Remember the time
    }

    
    if (digitalRead(up1) == HIGH )//&& (currentMillis - previousMillis >= OnTime)) 
    {
      floors = 1; int ladder = 1;
      nearstPath(floors, ladder);
      previousMillis = currentMillis;  // Remember the time
      //requiredud (  floors );
      }
      
      else if (digitalRead(up1) == LOW )//&& (currentMillis - previousMillis >= OffTime))
    {
      previousMillis = currentMillis;   // Remember the time
    }

    
if (digitalRead(up2) == HIGH )//&& (currentMillis - previousMillis >= OnTime)) 
{int floors = 2; int ladder = 1;
      nearstPath(floors, ladder);
      previousMillis = currentMillis;  // Remember the time
      //requiredud ( floors );
      
}   
else if (digitalRead(up2) == LOW)// && (currentMillis - previousMillis >= OffTime))
    {
      previousMillis = currentMillis;   // Remember the time
    }
if (digitalRead(up3) == HIGH )//&& (currentMillis - previousMillis >= OnTime)) 
{ int floors = 3; int ladder = 1;

      nearstPath(floors, ladder);
      previousMillis = currentMillis; 
      //requiredud ( floors );
}
   else if (digitalRead(up3) == LOW)// && (currentMillis - previousMillis >= OffTime))
    {
      previousMillis = currentMillis;   // Remember the time
    }

if (digitalRead(down1) == HIGH )//&& (currentMillis - previousMillis >= OnTime)) 
{int floors = 1; int ladder = 0;

      nearstPath(floors, ladder);
      previousMillis = currentMillis; 
      // requiredud (  floors );

}
   else if (digitalRead(down1) == LOW)// && (currentMillis - previousMillis >= OffTime))
    {
      previousMillis = currentMillis;   // Remember the time
      
    }
if (digitalRead(down2) == HIGH )//&& (currentMillis - previousMillis >= OnTime)) 
{int floors = 2; int ladder = 0;

      nearstPath(floors, ladder);
      previousMillis = currentMillis; 
      //requiredud (  floors );

}
   else if (digitalRead(down2) == LOW)// && (currentMillis - previousMillis >= OffTime))
    {
      previousMillis = currentMillis;   // Remember the time
    }
if (digitalRead(down3) == HIGH )//&& (currentMillis - previousMillis >= OnTime)) 
{int floors = 3; int ladder = 0;

      nearstPath(floors, ladder);
      previousMillis = currentMillis; 
     // requiredud (  floors );
      
}   else if (digitalRead(down3) == LOW)// && (currentMillis - previousMillis >= OffTime))
    {
      previousMillis = currentMillis;   // Remember the time
    }
if (digitalRead(down4) == HIGH )//&& (currentMillis - previousMillis >= OnTime)) 
{int floors = 4; int ladder = 0;  

      nearstPath(floors, ladder);
      previousMillis = currentMillis; 
     // requiredud ( floors );
      
}   else if (digitalRead(down4) == LOW)// && (currentMillis - previousMillis >= OffTime))
    {
      previousMillis = currentMillis;   // Remember the time
    }
    
   
 }
  
};

elevator elevator1(500, 500, 0, 1);
elevator elevator2(500, 500, 1, 1);
elevator elevator3(500, 500, 4, 0);

void getMinPath(int x , int y, int z){
  if (x < y )
 {  if (x < z)
      {  
        Serial.println ("1");
        Serial.println ("|");
        currentElevator = 1; 
        Serial.println (elevator1.floorElevator); // therefore elevator 1 is the minimum
        Serial.println ("|");
//        Serial.println (floors);
//        Serial.println ("|");
        elevator1.state= ladder;
        Serial.println (ladder);

               requiredud (  floors );

      }
      else  // therefore elevator 3 is the minimum
      {
        Serial.println ("3");     
        Serial.println ("|");

        currentElevator = 3; 
        Serial.println (elevator3.floorElevator);
        Serial.println ("|");
        //Serial.println (floors);
        //Serial.println ("|");
        elevator3.state= ladder;
        Serial.println (ladder );
              requiredud (  floors );

  }
  }
  else if (y < z )
  { 
    Serial.println ("2");
    Serial.println ("|");
    currentElevator = 2; 
    Serial.println (elevator2.floorElevator ); // therefore elevator 2 is the minimum
    Serial.println ("|");
//    Serial.println (floors);
//    Serial.println ("|");
    elevator2.state= ladder;
    Serial.println (ladder );
                  requiredud (  floors );

    }
    else{
      Serial.println ("3");
      currentElevator = 3; 
      Serial.println ("|");
      Serial.println (elevator3.floorElevator);
      Serial.println ("|");
//      Serial.println (floors);
//      Serial.println ("|");
      elevator3.state= ladder;
      Serial.println (ladder );
            requiredud (  floors );

        }
  }

void getMinUpPath ( int floorElevator1, int floorElevator2 , int floorElevator3 ,int floors , int elevator1, int elevator2, int elevator3 )
{
  if( (elevator1 == 1)&& (floorElevator1 > floors))
  {x = 8 -floorElevator1 + floors;}

if( (elevator2 == 1)&& (floorElevator2 > floors))
  {y = 8 - floorElevator2 + floors;}

 if( (elevator3 == 1)&& (floorElevator3 > floors))
  {z = 8 - floorElevator3 + floors;}

if( (elevator1 == 1)&& (floorElevator1 < floors))
  {x = abs  (floorElevator1 - floors);}

if( (elevator2 == 1)&& (floorElevator2 < floors))
  {y = abs  (floorElevator2 - floors);}
  
if( (elevator3 == 1)&& (floorElevator3 < floors))
  {z = abs  (floorElevator3 - floors);}

 if (elevator1 == 0)
 {x = abs (0 - floorElevator1) + floors;}

 if (elevator2 == 0)
 {y = abs (0 - floorElevator2) + floors;}

 if (elevator3 == 0)
 {z = abs (0 - floorElevator3) + floors;}
 
getMinPath (x, y, z);

  }
void getMinDownPath (int floorElevator1, int floorElevator2 , int floorElevator3 ,int floors , int elevator1, int elevator2,int  elevator3 )
{

  if( (floorElevator1< floors)&& (elevator1 == 0)){
      x= abs (0-floorElevator1)+ (floors-0);
      }
       if( (floorElevator2< floors)&& (elevator2 == 0)){
      y= abs (0-floorElevator2)+ (floors-0);
      }
       if( (floorElevator3< floors)&& (elevator3 == 0)){
      z= abs (0-floorElevator3)+ (floors-0);
      }
         if( (floorElevator1> floors)&& (elevator1 == 0)){
      x= floorElevator1- floors;
      }
          if( (floorElevator2> floors)&& (elevator2 == 0)){
      y= floorElevator2- floors;
      }
          if( (floorElevator3> floors)&& (elevator3 == 0)){
      z= floorElevator3- floors;
      }
      if (elevator1==1){
        x = 10-floorElevator1 - floors; 
        }
         if (elevator2==1){
        y = 10-floorElevator2 - floors; 
        } 
        if (elevator3==1){
        z = 10-floorElevator3 - floors; 
        }
    getMinPath (x, y, z);
  }

// floors is the value of which floor we stand.
 void nearstPath (int floors , int ladder)
 {
switch (floors){
case 0:

if (ladder  == 1)
{
getMinUpPath ( elevator1.floorElevator,  elevator2.floorElevator ,  elevator3.floorElevator , floors , elevator1.state, elevator2.state, elevator3.state);
}

case 1:
case 2:
case 3:
if (ladder == 1)
{
getMinUpPath ( elevator1.floorElevator,  elevator2.floorElevator ,  elevator3.floorElevator , floors , elevator1.state, elevator2.state, elevator3.state);
  } 
  else if (ladder == 0)
  { 
getMinDownPath ( elevator1.floorElevator,  elevator2.floorElevator ,  elevator3.floorElevator , floors , elevator1.state, elevator2.state, elevator3.state);
  }
    

case 4:

if (ladder == 0)
{
getMinDownPath ( elevator1.floorElevator,  elevator2.floorElevator ,  elevator3.floorElevator , floors , elevator1.state, elevator2.state, elevator3.state);
 }
 
 }
 }
 

void requiredud ( int floors )
{
  
 int requiredfloor = Serial.read();
//  
//  if ((ladder == 1)&&( floors < requiredfloor )){
//for (int i = floors; i <= requiredfloor ; i++  ) {
  delay (1500);
//  floors =i;
//  Serial.print(floors);
//  }   
  

  if(currentElevator==1){elevator1.floorElevator=requiredfloor; elevator1.state=ladder; }
  if(currentElevator==2){elevator2.floorElevator=requiredfloor; elevator2.state=ladder;}
  if(currentElevator==3){elevator3.floorElevator=requiredfloor; elevator3.state=ladder;}
 
  
   delay (3000);
   
//    }
    
//    if ((ladder == 1)&&( floors > requiredfloor )){
//      
// for (int i = floors;  i <=4 ; i ++  ) {
//  delay (1500);
//  floors=i;
//  Serial.println(i);
//  
// }
//
// for (int i = floors; i >= requiredfloor ; i-- ) {
//  delay (1500);
//   floors=i;
//  Serial.println(floors);
//  }   
//  if(currentElevator==1){elevator1.floorElevator=floors; elevator1.state=0; }
//  if(currentElevator==2){elevator2.floorElevator=floors; elevator2.state=0;}
//  if(currentElevator==3){elevator3.floorElevator=floors; elevator3.state=0; }
//   delay (3000);
//      
//      }
// 
  }

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Default communication rate of the Bluetooth module
  pinMode(up0, INPUT);
  pinMode(up1, INPUT);
  pinMode(up2, INPUT);
  pinMode(up3, INPUT);
  pinMode(down1, INPUT);
  pinMode(down2, INPUT);
  pinMode(down3, INPUT);
  pinMode(down4, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   while(Serial.available( ) > 0)
 {
  elevator1.Update();
  elevator2.Update();
  elevator3.Update();
 }

}
