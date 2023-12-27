#include <Arduino.h>
#include <WiFi.h>
#include <WebSocketsServer.h>
#include <ArduinoJson.h>

#include "components/joystick/rjc_joystick.h"

WiFiClient wifi_client;
WebSocketsServer websocket = WebSocketsServer(81);

static const char*  SSID           = "";
static const char*  PASSWORD       = "";

void setup() 
{
  Serial.begin(9600);

  delay(100);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);
  Serial.println("Connecting to WiFi ");

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }

  Serial.printf("WiFi connected, IP: %s\n", WiFi.localIP().toString().c_str());
  websocket.begin();
}

void loop() 
{
  JoystickPosition joystick_position = RJC_JOYSTICK::get_mapped_position(-10, 10);

  if (joystick_position.x != 0 || joystick_position.y != 0) 
  {
    StaticJsonDocument<100> jsonDocument;

    jsonDocument["type"] = "cursor";
    jsonDocument["data"]["x"] = joystick_position.x;
    jsonDocument["data"]["y"] = joystick_position.y;

    String message;
    serializeJson(jsonDocument, message);

    websocket.broadcastTXT(message);

    Serial.println("Sent joystick position over WebSocket: " + message);
  }

  websocket.loop();
  delay(20);
}