#include <ESP8266WiFi.h>
#include "DHTesp.h"

//const char* ssid = "wifi name";
//const char* password = "password"; 
String inputString = "",str="";
#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.

//IP or name of address root: ie: google.com
//NOT google.com/nothing/after/the/dotcom.html
const char* hostGet = "2c72a4fa.ngrok.io"; 
DHTesp dht;
void setup() {
    Serial.begin(9600);
      WiFiCon();
       dht.setup(4, DHTesp::DHT11);
      
}

void loop() {
  if (WiFiCon() > 0) 
  {
  
  postData();
    }
  delay(20);

}
