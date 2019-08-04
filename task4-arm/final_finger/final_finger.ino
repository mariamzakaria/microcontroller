
#include <Servo.h>

Servo servo1,servo2;
int daraga = 0,daraga2=0;   
const int haraka1 = 2;
const int haraka2  =3;
const int haraka3 = 4;
const int haraka4 = 5;

void setup() {
  
  Serial.begin(9600);
  
  //pin to servo
  servo1.attach(6);
  servo1.write(0);
  servo2.attach(7);
  servo2.write(0);
 
  pinMode(haraka1, INPUT);
  pinMode(haraka2, INPUT);
  pinMode(haraka3, INPUT);
  pinMode(haraka4, INPUT);
}

void loop() {

      //FIRST FINGER
      if(digitalRead(haraka1) == HIGH) 
      {  
       Serial.println("A");
       delay(1000);
      
       for (daraga =daraga; daraga <40; daraga += 1) { 
       servo1.write(daraga);             
       delay(15); 
       Serial.println(daraga);               
        }
         
      }    
             
      else if(digitalRead(haraka1) == LOW) 
      {
       Serial.println("a");
       delay(1000);
      
       for (daraga =daraga; daraga >0; daraga -= 1) { 
       servo1.write(daraga);       
       delay(15); 
       Serial.println(daraga);  
         }
  
      }

        if(digitalRead(haraka2) == HIGH) 
      {
       Serial.println("B");
       delay(1000);
       
       for (daraga =daraga; daraga <80; daraga += 1) {
      servo1.write(daraga);              
      delay(15); 
      Serial.println(daraga);  
          }
     }

     else if(digitalRead(haraka2) == LOW) 
      {
       Serial.println("b");
       delay(1000);
      for (daraga =daraga; daraga >40; daraga -= 1) { 
     servo1.write(daraga);             
      delay(15); 
     Serial.println(daraga);  
}
      
} 
     
     
       //SECOND FINGER
       if(digitalRead(haraka3) == HIGH) 
      {  
       Serial.println("C");
       delay(1000);
       for (daraga2 =daraga2; daraga2 <80; daraga2 += 1) { 
       servo2.write(daraga2);             
       delay(15); 
       Serial.println(daraga2);               
        }
      
      }    
             
      else if(digitalRead(haraka3) == LOW) 
      {
       Serial.println("c");
       delay(1000);
       for (daraga2 =daraga2; daraga2 >0; daraga2 -= 1) { 
       servo2.write(daraga2);            
       delay(15); 
       Serial.println(daraga2);  
          }
  
      }

        if(digitalRead(haraka4) == HIGH) 
      {
       Serial.println("D");
       delay(1000);
       for (daraga2 =daraga2; daraga2 <80; daraga2 += 1) {
       servo2.write(daraga2);             
       delay(15); 
       Serial.println(daraga2);  
        }
}

 else if(digitalRead(haraka4) == LOW) 
      {
       Serial.println("d");
       delay(1000);
       for (daraga2 =daraga2; daraga2 >40; daraga2 -= 1) {
       servo2.write(daraga2);           
       delay(15); 
      Serial.println(daraga2);  
           }
 
}
}      
