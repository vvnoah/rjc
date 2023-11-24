#include <Arduino.h>
#include <WiFi.h>
#include <WebSocketsServer.h>
#include <ArduinoJson.h>

#include "modules/joystick/rjc_joystick.h"

WiFiClient wifi_client;
WebSocketsServer websocket = WebSocketsServer(81);

static const char*  SSID           = "BillyTheRobot";
static const char*  PASSWORD       = "eloict1234";

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {
    // Handle events here
}

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);
  Serial.println("Connecting to WiFi ");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.printf("WiFi connected, IP: %s\n", WiFi.localIP().toString().c_str());
  websocket.begin();
}

void loop() {
  JoystickPosition joystick_position = RJC_JOYSTICK::get_mapped_position(-10, 10);

  // Example: Send joystick position over WebSocket when the joystick is moved
  if (joystick_position.x != 0 || joystick_position.y != 0) {
    // Create a JSON document
    StaticJsonDocument<100> jsonDocument;

    // Populate the JSON document
    jsonDocument["type"] = "cursor";
    jsonDocument["data"]["x"] = joystick_position.x;
    jsonDocument["data"]["y"] = joystick_position.y;

    // Serialize the JSON document to a String
    String message;
    serializeJson(jsonDocument, message);

    // Send the message to all connected clients
    websocket.broadcastTXT(message);

    Serial.println("Sent joystick position over WebSocket: " + message);
  }

  websocket.loop();
  delay(35);
}