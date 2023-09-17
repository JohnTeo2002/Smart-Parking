#include <ESP8266WebServer.h>

const int serverPort = 80;                // Port for the web server (HTTP)

ESP8266WebServer server(serverPort);

void clientHandler() {
  server.handleClient();
}

/*
void loop() {
  // Handle client requests
  clientHandler()
}
*/
