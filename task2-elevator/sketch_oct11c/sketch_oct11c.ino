int a1=0;
    int a2=0;
    int val=0;
    
    void setup()
    {
    Serial.begin(9600);
    }
     
    void loop()
    {
         a1=analogRead(0);
         a2=analogRead(1);
         if (Serial.available() >0) {

    /* whatever is available from the serial is read here    */
    val = Serial.read();
    
    {
      
      if(val==10)
      {
        Serial.println(elevator);
      }
      else
            if(val==20)
      {
        Serial.println(floors);
      }
      else
            if(val==30)
      {
        Serial.println(new1);
      }
    }
  }
}  










