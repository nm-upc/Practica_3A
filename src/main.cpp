#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "MOVISTAR_79C8";
const char* password = "TAMALEON";
WebServer server(80);

// HTML & CSS contents which display on web server
String HTML = "<!DOCTYPE html>\
<html>\
<body>\
<h1>My Primera Pagina con ESP32 - Station Mode &#128522;</h1>\
</body>\
</html>";

// DECLARAR handle_root ANTES DE setup()
void handle_root() {
  server.send(200, "text/html", HTML);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Try Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected successfully");
  Serial.print("Got IP: ");
  Serial.println(WiFi.localIP());
  
  server.on("/", handle_root);  // Ahora handle_root ya está declarada
  server.begin();
  Serial.println("HTTP server started");
  delay(100);
}

void loop() {
  server.handleClient();
}