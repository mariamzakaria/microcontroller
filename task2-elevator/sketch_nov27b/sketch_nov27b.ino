const int ledpin=13;
int recValue;
 int elevator;
 int floors;
 int directions;
int thefloor;
void setup()
{
Serial.begin(9600);
pinMode(3, INPUT);
pinMode(4, INPUT);
pinMode(5, INPUT);
}

void loop()
{elevator= digitalRead(3);
   floors= digitalRead(4);
    directions= digitalRead(5);
  
  if(Serial.available()>0)
  
  {   recValue=Serial.read();  
    
     
//      If use will send value 100 from MATLAB                                           then LED will turn ON
     { if(recValue==10)
       Serial.println(elevator);
      
        if(recValue=20)
       Serial.println(floors);
       
        if(recValue=30)
       Serial.println(directions);
       
        if(recValue=40)
        thefloor=Serial.read();
       Serial.println(thefloor);
       }
        
      }
    }

