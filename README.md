# ESP32 Web Server - Station Mode

Este proyecto muestra cómo crear un **servidor web básico utilizando un ESP32 en modo Station (STA)**.  
El ESP32 se conecta a una red WiFi existente y crea un **servidor HTTP** que permite acceder a una página web desde cualquier dispositivo conectado a la misma red.

Cuando un usuario accede a la dirección IP del ESP32 desde un navegador, se muestra una **página HTML sencilla**.

---

# Características

- Conexión del ESP32 a una red WiFi existente
- Creación de un **servidor HTTP**
- Servir una página **HTML básica**
- Uso de la librería `WebServer`
- Acceso desde navegador en la misma red

---

# Hardware necesario

- ESP32
- Cable USB
- Ordenador
- Router WiFi

---

# Librerías utilizadas

El proyecto utiliza las siguientes librerías del framework de ESP32:

```cpp
#include <WiFi.h>
#include <WebServer.h>