#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *ssid = "Your_SSID";           // Wi-Fi SSID
const char *password = "Your_Password";   // Wi-Fi password

const char *host = "Your_Hostname";       // Hostname for ESP8266 (optional)
const int serverPort = 80;                // Port for the web server (HTTP)

ESP8266WebServer server(serverPort);

void setup() {
  // Connect to Wi-Fi
  WiFi.hostname(host);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize server routes
  server.on("/", HTTP_GET, handleRoot);

  // Start the server
  server.begin();
}

void loop() {
  // Handle client requests
  server.handleClient();
}

void handleRoot() {
  // Load the HTML file from SPIFFS (file system)
  String page;
  if (loadHtmlFile("/webpage.html", page)) {
    server.send(200, "text/html", page);
  } else {
    server.send(500, "text/plain", "Failed to load webpage");
  }
}

bool loadHtmlFile(const char *filename, String &output) {
  // Open the file in read mode
  File file = SPIFFS.open(filename, "r");
  if (!file) {
    return false;
  }

  // Read file content into the output string
  while (file.available()) {
    output += (char)file.read();
  }

  // Close the file
  file.close();
  return true;
}
