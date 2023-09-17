#include <ESP8266WiFi.h>

/*ADD YOUR PASSWORD BELOW*/
const char *ssid = "Askey5100-CD58";
const char *password = "NMCxYyhs3L";

WiFiClient client;

/*
* Connect your controller to WiFi
*/
void connectToWiFi() {
//Connect to WiFi Network
   Serial.println();
   Serial.println();
   Serial.print("Connecting to WiFi");
   Serial.println("...");
   WiFi.begin(ssid, password);
   int retries = 0;
  while ((WiFi.status() != WL_CONNECTED) && (retries < 15)) {
   retries++;
   delay(500);
   Serial.print(".");
  }
  if (retries > 10000000) {
    Serial.println(F("WiFi connection FAILED"));
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println(F("WiFi connected!"));
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  }
    Serial.println(F("Setup ready"));
}
//This code will try to connect to the network 15 times. If it can’t connect, then it will fail and print out a failure message in the Serial Monitor.
//Otherwise, you’ll see that the controller is connected.

/*
 * call connectToWifi() in setup()
 */

/*
void setup(){
 Serial.begin(115200);
 connectToWiFi();
}
*/

/*
void loop(){
 //...other setup code here...
}
*/

