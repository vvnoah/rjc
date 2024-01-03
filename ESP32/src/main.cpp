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

static const char*  SSID = "KotAzurPloeg+2";
static const char*  PASSWORD = "";

int nu = 0;
int vroeger = 0;
int mode_index = 0;

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
    //rjc_display.draw_loading_animation();
  } 

  Serial.printf("WiFi connected, IP: %s\n", WiFi.localIP().toString().c_str());
  rjc_display.draw_top_section("Connected!");

  delay(200);

  websocket.begin();
}

String modes[] = {"Info", "Cursor","Scroll", "Media"};

void loop() 
{
  nu = digitalRead(12);

  if(nu != vroeger)
  {
    if(nu == HIGH)
    {
      Serial.printf("size of modes: %i\r\n", sizeof(modes)/sizeof(modes[0]));
      if(mode_index < sizeof(modes)/sizeof(modes[0]) - 1)
      {
        Serial.printf("mode index: %i\r\n", mode_index);
        mode_index++;
      }
      else if(mode_index >= sizeof(modes)/sizeof(modes[0]) - 1)
      {
        Serial.printf("mode index: %i\r\n", mode_index);
        mode_index = 0;
      }
      Serial.printf("mode index: %i\r\n", mode_index);
    }
  }
  vroeger = nu;

  rjc_display.draw_top_section(modes[mode_index]);

  rjc_joystick_t joystick_data;
  rjc_joystick.update_joystick_position(&joystick_data);
  String json_message = "";

  if(mode_index == 0)
  {
      rjc_display.draw_system_page(&joystick_data, WiFi.localIP().toString().c_str(), SSID);
  }

  if(mode_index == 1)
  {
      if (joystick_data.pos_x != 0 || joystick_data.pos_y != 0) 
      {
        StaticJsonDocument<100> jsonDocument;

        jsonDocument["type"] = "cursor";
        jsonDocument["data"]["x"] = joystick_data.pos_x;
        jsonDocument["data"]["y"] = joystick_data.pos_y;
        
        serializeJson(jsonDocument, json_message);

        websocket.broadcastTXT(json_message);

        Serial.println("Sent data over WebSocket: " + json_message);
      }
  }

  if(mode_index == 2)
  {
      if (joystick_data.pos_x != 0 || joystick_data.pos_y != 0) 
      {
        StaticJsonDocument<100> jsonDocument;

        jsonDocument["type"] = "scroll";
        jsonDocument["data"]["x"] = joystick_data.pos_x;
        jsonDocument["data"]["y"] = joystick_data.pos_y;
        
        serializeJson(jsonDocument, json_message);

        websocket.broadcastTXT(json_message);

        Serial.println("Sent data over WebSocket: " + json_message);
      }
  }

  if(mode_index == 3)
  {
      if (joystick_data.pos_x != 0 || joystick_data.pos_y != 0) 
      {
        StaticJsonDocument<100> jsonDocument;

        jsonDocument["type"] = "media";
        jsonDocument["data"]["x"] = joystick_data.pos_x;
        jsonDocument["data"]["y"] = joystick_data.pos_y;
        
        serializeJson(jsonDocument, json_message);

        websocket.broadcastTXT(json_message);

        Serial.println("Sent data over WebSocket: " + json_message);
      }
  }

  websocket.loop();
}