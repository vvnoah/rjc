#include <Arduino.h>
#include <WiFi.h>
#include <WebSocketsServer.h>
#include <ArduinoJson.h>

#include "components/joystick/rjc_joystick.h"
#include "components/display/rjc_display.h"

// WiFiClient wifi_client;
// WebSocketsServer websocket = WebSocketsServer(81);

// RJC_JOYSTICK Joystick;
RJC_DISPLAY Screen;

// static const char*  SSID           = "";
// static const char*  PASSWORD       = "";

void setup() 
{
  Serial.begin(9600);

  delay(100);

  Screen.begin();

  // WiFi.mode(WIFI_STA);
  // WiFi.begin(SSID, PASSWORD);
  // Serial.println("Connecting to WiFi ");

  // while (WiFi.status() != WL_CONNECTED) 
  // {
  //   delay(500);
  //   Serial.print(".");
  // }

  // Serial.printf("WiFi connected, IP: %s\n", WiFi.localIP().toString().c_str());
  // websocket.begin();
}

void loop() 
{
  // rjc_joystick_t joystick_data;
  // Joystick.update_joystick_position(&joystick_data);

  // if (joystick_data.pos_x != 0 || joystick_data.pos_y != 0) 
  // {
  //   StaticJsonDocument<100> jsonDocument;

  //   jsonDocument["type"] = "cursor";
  //   jsonDocument["data"]["x"] = joystick_data.pos_x;
  //   jsonDocument["data"]["y"] = joystick_data.pos_y;

  //   String message;
  //   serializeJson(jsonDocument, message);

  //   websocket.broadcastTXT(message);

  //   Serial.println("Sent joystick position over WebSocket: " + message);
  // }

  // websocket.loop();
  delay(20);
}