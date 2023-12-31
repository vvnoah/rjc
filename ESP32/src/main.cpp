#include <Arduino.h>
#include <WiFi.h>
#include <WebSocketsServer.h>
#include <ArduinoJson.h>

#include "components/joystick/rjc_joystick.h"
#include "components/display/rjc_display.h"
#include "components/button/rjc_button.h"

WiFiClient wifi_client;
WebSocketsServer websocket = WebSocketsServer(81);

RJC_JOYSTICK rjc_joystick;
RJC_DISPLAY rjc_display;
RJC_BUTTON button_modes(12);
RJC_BUTTON button_1(13);
RJC_BUTTON button_2(14);

static const char*  SSID = "WiFi-2.4-F508";
static const char*  PASSWORD = "wd542j9hwappj";

int mode_index = 0;
String modes[] = {"Info", "Cursor"};

void setup() 
{
  Serial.begin(9600);
  delay(50);

  rjc_display.begin();
  delay(200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(200);
    Serial.println("Connecting to WiFi");
    rjc_display.draw_top_section("Connecting");
    //rjc_display.draw_loading_animation();
  } 

  Serial.printf("WiFi connected, IP: %s\n", WiFi.localIP().toString().c_str());
  rjc_display.draw_top_section("Connected!");

  delay(200);

  websocket.begin();
}

void loop() 
{
  if(button_modes.clicked())
  {
    Serial.printf("previous mode: %s\r\n", modes[mode_index]);
    if(mode_index < sizeof(modes)/sizeof(modes[0]) - 1)
    {
      mode_index++;
    }
    else if(mode_index >= sizeof(modes)/sizeof(modes[0]) - 1)
    {
      mode_index = 0;
    }
    Serial.printf("current mode: %s\r\n", modes[mode_index]);
  }

  rjc_display.draw_top_section(modes[mode_index]);

  rjc_joystick_t joystick_data;
  rjc_joystick.update_joystick_position(&joystick_data);

  String json_message = "";
  StaticJsonDocument<100> jsonDocument;

  jsonDocument["joystick_position"]["x"] = joystick_data.pos_x;
  jsonDocument["joystick_position"]["y"] = joystick_data.pos_y;
  jsonDocument["buttons"]["button_1"] = 0;
  jsonDocument["buttons"]["button_2"] = 0;
  
  if(button_1.clicked()) jsonDocument["buttons"]["button_1"] = 1;
  if(button_2.clicked()) jsonDocument["buttons"]["button_2"] = 1;

  serializeJson(jsonDocument, json_message);
  websocket.broadcastTXT(json_message);
  Serial.println("Sent data over WebSocket: " + json_message);

  if(mode_index == 0)
  {
    rjc_display.draw_system_page(&joystick_data, WiFi.localIP().toString().c_str(), SSID);
  }

  websocket.loop();
}