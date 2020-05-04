String Seriial() {  
  inputString="";
  while(Serial.available()>0)    //Checks is there any data in buffer 
  {
    //Serial.print("We got:");
     char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;//Read serial data byte and send back to serial monitor
    //Serial.println("kkkkkkkkk");
  }
 
  return inputString;
}
