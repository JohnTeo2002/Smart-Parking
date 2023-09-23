#include <DNSServer.h>

void DNSConnection() {
  // Initialize server routes
  server.on("/", HTTP_GET, handleRoot);

  // Start the server
  server.begin();
}

/*
void setup() {
  DNSConnection()
}
*/
