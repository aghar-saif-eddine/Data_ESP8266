void postData() {

   WiFiClient clientGet;
   const int httpGetPort = 80;

   //the path and file to send the data to:
   String urlGet = "/data";


  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();
 
  // We now create and add parameters:

  String src = String(analogRead(0));

  String typ = String(humidity);
  String nam =  String(temperature);
  String vint = "92"; 

  urlGet += "?data=" + src + "&typ=" + typ + "&nam=" + nam ;//+ "&int=" + vint;
     Serial.print("src=");
     Serial.println(src);
      Serial.print("typ=");
     Serial.println(typ);
      Serial.print("nam=");
     Serial.println(nam);
      Serial.print(">>> Connecting to host: ");
      Serial.println(hostGet);
      
       if (!clientGet.connect(hostGet, httpGetPort)) {
        Serial.print("Connection failed: ");
        Serial.print(hostGet);
      } else {
          clientGet.println("GET " + urlGet + " HTTP/1.1");
          clientGet.print("Host: ");
          clientGet.println(hostGet);
          clientGet.println("User-Agent: ESP8266/1.0");
          clientGet.println("Connection: close\r\n\r\n");
          
          unsigned long timeoutP = millis();
          while (clientGet.available() == 0) {
            
            if (millis() - timeoutP > 10000) {
              Serial.print(">>> Client Timeout: ");
              Serial.println(hostGet);
              clientGet.stop();
              return;
            }
          }

          //just checks the 1st line of the server response. Could be expanded if needed.
          while(clientGet.available()){
            String retLine = clientGet.readStringUntil('\r');
            Serial.println(retLine);
            break; 
          }

      } //end client connection if else
                        
      Serial.print(">>> Closing host: ");
      Serial.println(hostGet);
          
      clientGet.stop();

}
