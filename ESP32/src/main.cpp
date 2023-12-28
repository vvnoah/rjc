#include <Arduino.h>
#include <WiFi.h>
#include <WebSocketsServer.h>
#include <ArduinoJson.h>

#include "components/joystick/rjc_joystick.h"
#include "components/display/rjc_display.h"

WiFiClient wifi_client;
WebSocketsServer websocket = WebSocketsServer(81);

RJC_JOYSTICK rjc_joystick;
RJC_DISPLAY rjc_display;

static const char*  SSID = "";
static const char*  PASSWORD = "";

void setup() 
{
  Serial.begin(9600);

  delay(200);

  rjc_display.begin();

  delay(200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);


  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(200);
    Serial.println("Connecting to WiFi");
    rjc_display.draw_top_section("Connecting");
  } 

  Serial.printf("WiFi connected, IP: %s\n", WiFi.localIP().toString().c_str());
  rjc_display.draw_top_section("Connected!");

  delay(200);

  websocket.begin();
}

void loop() 
{
  rjc_display.draw_top_section("System");

  rjc_joystick_t joystick_data;
  rjc_joystick.update_joystick_position_randomly(&joystick_data);

  String message;
  if (joystick_data.pos_x != 0 || joystick_data.pos_y != 0) 
  {
    StaticJsonDocument<100> jsonDocument;

    jsonDocument["type"] = "cursor";
    jsonDocument["data"]["x"] = joystick_data.pos_x;
    jsonDocument["data"]["y"] = joystick_data.pos_y;

    
    serializeJson(jsonDocument, message);

    websocket.broadcastTXT(message);

    Serial.println("Sent data over WebSocket: " + message);
  }
  websocket.loop();

  rjc_display.draw_system_page(&joystick_data, WiFi.localIP().toString().c_str(), SSID);
}