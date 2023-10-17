#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "(Internet navn)";
const char* password = "(Koden)";

const int motor1EN = D2; // Tilslut motor 1's EN-pin til en GPIO-pin
const int motor1A = D3;  // Tilslut motor 1's A-pin til en GPIO-pin
const int motor1B = D4;  // Tilslut motor 1's B-pin til en GPIO-pin

const int motor2EN = D5; // Tilslut motor 2's EN-pin til en GPIO-pin
const int motor2A = D6;  // Tilslut motor 2's A-pin til en GPIO-pin
const int motor2B = D7;  // Tilslut motor 2's B-pin til en GPIO-pin

ESP8266WebServer server(80);

void handleRoot() {
  String message = "Velkommen til Motorstyring";
  server.send(200, "text/plain", message);
}

void handleGPIO() {
  String command = server.arg("cmd");
  
  if (command == "1") {
    // Aktiver motor 1 til at køre fremad
    digitalWrite(motor1A, HIGH);
    digitalWrite(motor1B, LOW);
    digitalWrite(motor1EN, HIGH);

    // Aktiver motor 2 til at køre fremad
    digitalWrite(motor2A, HIGH);
    digitalWrite(motor2B, LOW);
    digitalWrite(motor2EN, HIGH);

    String message = "Begge motorer kører fremad";
    server.send(200, "text/plain", message);
  } else if (command == "3") {
    // Aktiver motor 1 til at køre baglæns
    digitalWrite(motor1A, LOW);
    digitalWrite(motor1B, HIGH);
    digitalWrite(motor1EN, HIGH);

    // Aktiver motor 2 til at køre baglæns
    digitalWrite(motor2A, LOW);
    digitalWrite(motor2B, HIGH);
    digitalWrite(motor2EN, HIGH);

    String message = "Begge motorer kører baglæns";
    server.send(200, "text/plain", message);
  } else if (command == "2") {
    // Deaktiver begge motorer
    digitalWrite(motor1EN, LOW);
    digitalWrite(motor2EN, LOW);

    String message = "Begge motorer er stoppet";
    server.send(200, "text/plain", message);
  } else {
    String message = "Ugyldig kommando";
    server.send(400, "text/plain", message);
  }
}

void setup() {
  Serial.begin(115200);

  // Konfigurer motor-GPIO som OUTPUT
  pinMode(motor1EN, OUTPUT);
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2EN, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);

  // Tilslut til Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Forbindelse til WiFi...");
  }
  Serial.println("Forbundet til WiFi");
  Serial.print("ESP8266 IP-adresse: ");
  Serial.println(WiFi.localIP()); 
  // Konfigurer HTTP-ruter
  server.on("/", HTTP_GET, handleRoot);
  server.on("/gpio", HTTP_GET, handleGPIO);

  // Start HTTP-server
  server.begin();
}

void loop() {
  server.handleClient();
}


//http://192.168.180.237/gpio?cmd=2
