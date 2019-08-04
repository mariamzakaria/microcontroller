int up0 = 10;
int up1 = 2;
int up2 = 3;
int up3 = 4;
int down1 = 6; 
int down2 = 7;
int down3 = 8;
int down4 = 9;
int x =0; 
int y =0; 
int z = 0;
int ladder = 1;                            // to indicate if the selected button is for up (ladder = 1) or for down (ladder = 0)
int floorElevator1=0; int elevator1 = 1;  // inialize values of each elevator and if it's going up (1) or down (0) 
int floorElevator2=1; int elevator2 = 1;
int floorElevator3=4; int elevator3 = 0; 

int currentElevator;

void getMinPath(int x , int y, int z){
  if (x < y )
 {  if (x < z)
      {  Serial.println ("1");
         Serial.println ("|");
          //delay(1000);
         currentElevator = 1; 
         Serial.println (floorElevator1); // therefore elevator 1 is the mini
          Serial.println ("|");
          // delay(1000);
         Serial.println (ladder);
          delay(1000);
         requiredud ( );
      }
      else  // therefore elevator 3 is the minimum
      {Serial.println ("3");
        Serial.println ("|");
        // delay(1000);
      currentElevator = 3; 
       Serial.println (floorElevator3);
        Serial.println ("|");
       //  delay(1000);
       Serial.println (ladder );
       delay(1000);
       requiredud ();
        }
  }
  else if (y < z )
  { Serial.println ("2");
     Serial.println ("|");
     // delay(1000);
       currentElevator = 2; 
    Serial.println (floorElevator2 ); // therefore elevator 2 is the minimum
     Serial.println ("|");
    //  delay(1000);
    Serial.println (ladder );
     delay(1000);
     requiredud ( );
    }
    else{Serial.println ("3");
           Serial.println ("|");
           //delay(1000);
        currentElevator = 3; 
        Serial.println (floorElevator3);
         Serial.println ("|");
         // delay(1000);
        Serial.println (ladder );
        delay(1000);
        requiredud ( );
        }
  }

void getMinUpPath ( int floorElevator1, int floorElevator2 , int floorElevator3 ,int floors , int elevator1, int elevator2, int elevator3 )
{
  if( (elevator1 == 1)&& (floorElevator1 > floors))
  {x = 8 - floorElevator1 + floors;}

if( (elevator2 == 1)&& (floorElevator2 > floors))
  {y = 8 - floorElevator2 + floors;}

 if( (elevator3 == 1)&& (floorElevator3 > floors))
  {z = 8 - floorElevator3 + floors;}

if( (elevator1 == 1)&& (floorElevator1 < floors))
  {x = abs  (floorElevator1 - floors);}

if( (elevator2 == 1)&& (floorElevator1 < floors))
  {y = abs  (floorElevator2 - floors);}
  
if( (elevator3 == 1)&& (floorElevator1 < floors))
  {z = abs  (floorElevator3 - floors);}

 if (elevator1 == 0)
 {x = abs (0 - floorElevator1) + floors;}

 if (elevator1 == 0)
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
 void nearstPath (int floorElevator1 , int floorElevator2, int floorElevator3, int floors , int ladder)
 {
switch (floors){
case 0:
// {if ((floorElevator1 == floors)&&(elevator1 == ladder)){ Serial.println ("01"); Serial.println (floorElevator1); Serial.println (ladder );}
// if ((floorElevator2 == floors)&&(elevator2 == ladder)){ Serial.println ("02"); Serial.println (floorElevator2); Serial.println (ladder );}
// if ((floorElevator3 == floors)&&(elevator2 == ladder)){ Serial.println ("03"); Serial.println (floorElevator3); Serial.println (ladder );}
// 
// }
if (ladder  == 1)
{

//x= floorElevator1-floors;
//y= floorElevator2-floors;
//z= floorElevator3-floors;
getMinUpPath ( floorElevator1,  floorElevator2 ,  floorElevator3 , floors , elevator1, elevator2, elevator3 );
}
//break;

case 1:
// if ((floorElevator1 == floors)&&(elevator1 == ladder)){Serial.println ("01"); Serial.println (floorElevator1); Serial.println (ladder );}
// if ((floorElevator2 == floors)&&(elevator2 == ladder)){Serial.println ("02"); Serial.println (floorElevator2); Serial.println (ladder );}
// if ((floorElevator3 == floors)&&(elevator2 == ladder)){Serial.println ("03"); Serial.println (floorElevator3); Serial.println (ladder );}

if (ladder == 1)
{
//
//x= floorElevator1-floors;
//y= floorElevator2-floors;
//z= floorElevator3-floors;
getMinUpPath ( floorElevator1,  floorElevator2 ,  floorElevator3 , floors , elevator1, elevator2, elevator3 );

// the third priority for the coming down
// to get minimum
//getMinPath (x, y, z);
  } 
  else if (ladder == 0)
  { getMinDownPath ( floorElevator1,  floorElevator2 ,  floorElevator3 , floors , elevator1, elevator2, elevator3 );
    
    }

//break;
case 2:
// if ((floorElevator1 == floors)&&(elevator1 == ladder)){Serial.println ("01"); Serial.println (floorElevator1); Serial.println (ladder );}
// if ((floorElevator2 == floors)&&(elevator2 == ladder)){Serial.println ("02"); Serial.println (floorElevator2); Serial.println (ladder );}
// if ((floorElevator3 == floors)&&(elevator2 == ladder)){Serial.println ("03"); Serial.println (floorElevator3); Serial.println (ladder );}

if (ladder == 1)
{
//x= floorElevator1-floors;
//y= floorElevator2-floors;
//z= floorElevator3-floors;
//
//// the third priority for the coming down
//// to get minimum
//getMinPath (x, y, z);
 getMinUpPath ( floorElevator1,  floorElevator2 ,  floorElevator3 , floors , elevator1, elevator2, elevator3 );

  } 
  else if (ladder == 0)
  {
    getMinDownPath ( floorElevator1,  floorElevator2 ,  floorElevator3 , floors , elevator1, elevator2, elevator3 );
    }
//break;
case 3:
// if ((floorElevator1 == floors)&&(elevator1 == ladder)){Serial.println ("01"); Serial.println (floorElevator1); Serial.println (ladder );}
// if ((floorElevator2 == floors)&&(elevator2 == ladder)){Serial.println ("02"); Serial.println (floorElevator2); Serial.println (ladder );}
// if ((floorElevator3 == floors)&&(elevator2 == ladder)){Serial.println ("03"); Serial.println (floorElevator3); Serial.println (ladder );}

if (ladder == 1)
{
//x= floorElevator1-floors;
//y= floorElevator2-floors;
//z= floorElevator3-floors;
//
//// the third priority for the coming down
//// to get minimum
//getMinPath (x, y, z);
 getMinUpPath ( floorElevator1,  floorElevator2 ,  floorElevator3 , floors , elevator1, elevator2, elevator3 );

  } 
  else if (ladder == 0)
  {
    getMinDownPath ( floorElevator1,  floorElevator2 ,  floorElevator3 , floors , elevator1, elevator2, elevator3 );
    }
//break;
case 4:
// if ((floorElevator1 == floors)&&(elevator1 == ladder)){Serial.println ("01"); Serial.println (floorElevator1); Serial.println (ladder );}
// if ((floorElevator2 == floors)&&(elevator2 == ladder)){Serial.println ("02"); Serial.println (floorElevator2); Serial.println (ladder );}
// if ((floorElevator3 == floors)&&(elevator2 == ladder)){Serial.println ("03"); Serial.println (floorElevator3); Serial.println (ladder );}

if (ladder == 0)
{
  getMinDownPath ( floorElevator1,  floorElevator2 ,  floorElevator3 , floors , elevator1, elevator2, elevator3 );
 }
//break;
 }
 }
 void requiredud (  )
{
  
 int requiredfloor = Serial.read();
  
//  if ((ladder == 1)&&( currentFloor < requiredfloor )){
//for (int i = currentFloor; i <= requiredfloor ; i++  ) {
 delay (1500);
//  currentFloor =i;
//  Serial.print(currentFloor);
//  }   
  

  if(currentElevator==1){floorElevator1=requiredfloor; elevator1=ladder; }
  if(currentElevator==2){floorElevator2=requiredfloor; elevator2=ladder;}
  if(currentElevator==3){floorElevator3=requiredfloor; elevator3=ladder;}
 
  
   delay (3000);
   
   // }
    
//    if ((ladder == 1)&&( currentFloor > requiredfloor )){
//      
// for (int i = currentFloor;  i <=4 ; i ++  ) {
//  delay (1500);
//  currentFloor=i;
//  Serial.println(i);
//  
// }
//
// for (int i = currentFloor; i >= requiredfloor ; i-- ) {
//  delay (1500);
//   currentFloor=i;
//  Serial.println(currentFloor);
//  }   
//  if(currentElevator==1){floorElevator1=currentFloor; elevator1=0; }
//  if(currentElevator==2){floorElevator2=currentFloor; elevator2=0;}
//  if(currentElevator==3){floorElevator3=currentFloor; elevator3=0; }
//   delay (3000);
//      
//      }
 
  }

void setup() {
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
 while(Serial.available( ) > 0)
 {


 if (digitalRead(up0) == HIGH) 
{int floor0 = 0; int ladder = 1;
  nearstPath(floorElevator1, floorElevator2, floorElevator3, floor0, ladder);
 // int requiredFloor = Serial.read();
// requiredud ( floor0 );

}
if (digitalRead(up1) == HIGH) 
{int floor1 = 1; int ladder = 1;
  nearstPath(floorElevator1, floorElevator2, floorElevator3, floor1, ladder);
// int  requiredFloor = Serial.read();
//  requiredud ( floor1 );

}
if (digitalRead(up2) == HIGH) 
{int floor2 = 2; int ladder = 1;
    nearstPath(floorElevator1, floorElevator2, floorElevator3, floor2, ladder);
  // int requiredFloor = Serial.read();
//    requiredud ( floor2 );

}
if (digitalRead(up3) == HIGH) 
{ int floor3 = 3; int ladder = 1;
    nearstPath(floorElevator1, floorElevator2, floorElevator3, floor3, ladder);
  // int requiredFloor = Serial.read();
//   requiredud ( floor3 );

}

if (digitalRead(down1) == HIGH) 
{int floor1 = 1; int ladder = 0;
    nearstPath(floorElevator1, floorElevator2, floorElevator3, floor1, ladder);
  // int requiredFloor = Serial.read();
//   requiredud ( floor1);

}
if (digitalRead(down2) == HIGH) 
{int floor2 = 2; int ladder = 0;
    nearstPath(floorElevator1, floorElevator2, floorElevator3, floor2, ladder);
  //int  requiredFloor = Serial.read();
 //  requiredud ( floor2);

}
if (digitalRead(down3) == HIGH) 
{int floor3 = 3; int ladder = 0;
    nearstPath(floorElevator1, floorElevator2, floorElevator3, floor3, ladder);
  // int requiredFloor = Serial.read();
//    requiredud ( floor3);

}
if (digitalRead(down4) == HIGH) 
{int floor4 = 4; int ladder = 0;
    nearstPath(floorElevator1, floorElevator2, floorElevator3, floor4, ladder);
    // int requiredFloor = Serial.read(); 
//  requiredud ( floor4 );

}

}

 }
