/**
   BasicHTTPClient.ino

    Created on: 24.05.2015

*/

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#include <WiFiClient.h>

ESP8266WiFiMulti WiFiMulti;

unsigned long int ID=0;

void setup() {

  Serial.begin(9600);
  // Serial.setDebugOutput(true);

  Serial.println();
  Serial.println();
  Serial.println();

  for (uint8_t t = 4; t > 0; t--) {
   // Serial.printf("[SETUP] WAIT %d...\n", t);
   // Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("Acajabón", "12345678");

}

String url = "http://192.168.43.253:3000/api/cards/actions";


void loop() {

  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {
//    if (Serial.available()){
//      ID = Serial.read();

//      Serial.print(todo);

  //    Thief_56124618

//    ID = todo.substring(0, todo.indexOf("_"));
//    modo = todo.substring(todo.indexOf("_") + 1);
        
    WiFiClient client;

    HTTPClient http;

    //Serial.print("[HTTP] begin...\n");
    String terminado = url + "/ALGO" + "/" + "56124618";
    if (http.begin(client, terminado)) {  // HTTP
        //Serial.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.POST("Algo");
  
        // httpCode will be negative on error
        if (httpCode > 0) {
          // HTTP header has been send and Server response header has been handled
         // Serial.printf("[HTTP] GET... code: %d\n", httpCode);
  
          // file found at server
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
            String payload = http.getString();
            //Serial.println(payload);
          }
        } else {
          //Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }
  
        http.end();
      } else {
       // Serial.printf("[HTTP} Unable to connect\n");
      }

//    }
  }

  delay(10000);
}
