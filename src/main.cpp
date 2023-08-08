#include <Arduino.h>

#include <WiFi.h>
#include "esp_http_server.h"

const char* ssid = "Moogle";
const char* wifi_password = "parched-shadow-stride";

void setupSerial();
void setupWifi();

void setup() {
  setupSerial();
  setupWifi();
}

void setupSerial() {
  Serial.begin(115200);
  while (!Serial);
  Serial.println("Serial setup");
}

void setupWifi() {
  Serial.println("Connecting to WiFi network: " + String(ssid));
  WiFi.begin(ssid, wifi_password);
  WiFi.setSleep(false);
  WiFi.setHostname("shhh");

  Serial.println("Waiting for connection...");
  while(WiFi.status() != WL_CONNECTED) {
    delay(10000);
    Serial.print("Connection status: ");
    Serial.println(WiFi.status());
  }
  Serial.println("Connected to WiFi network");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void printHeartbeat();

void loop() {
  // Do nothing
  delay(10000);
  printHeartbeat();
}

void printHeartbeat() {
  Serial.println("");
  Serial.println("Heartbeat:");
  Serial.println("");
  Serial.println("WiFi Status:");
  Serial.print("Connection status: ");
  Serial.println(WiFi.status());
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
}
