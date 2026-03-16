#include <WiFi.h>
#include <WebServer.h>
#include <SPIFFS.h>  // Librería para el sistema de archivos

const char* ssid = "wifi";
const char* password = "contraseña";
WebServer server(80);

// Declaración de funciones
void handle_root();
void handleNotFound();
void setup() {
  Serial.begin(115200);
  
  // Inicializar SPIFFS
  if(!SPIFFS.begin(true)) {
    Serial.println("Error al montar SPIFFS");
    return;
  }
  
  Serial.println("Conectando a WiFi...");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi conectado exitosamente");
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());
  
  // Configurar rutas del servidor
  server.on("/", handle_root);
  server.onNotFound(handleNotFound);
  
  server.begin();
  Serial.println("Servidor HTTP iniciado");
}

void loop() {
  server.handleClient();
}

void handle_root() {
  // Leer el archivo HTML de SPIFFS
  File file = SPIFFS.open("/index.html", "r");
  if(!file) {
    server.send(500, "text/plain", "Error al cargar el archivo HTML");
    return;
  }
  
  String html = file.readString();
  file.close();
  
  server.send(200, "text/html", html);
}

void handleNotFound() {
  server.send(404, "text/plain", "404: Página no encontrada");
}