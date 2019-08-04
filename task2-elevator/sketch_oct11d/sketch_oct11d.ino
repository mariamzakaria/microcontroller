int matlabval=0;
int randNumber;
void setup()
{
Serial.begin(9600);
}
void loop()
{randNumber = random(0, 4);
  
   if (Serial.available() > 0) {
    matlabval=Serial.read()-48;
//Serial.println(6);
Serial.println(randNumber); 
      }
  }

