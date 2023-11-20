#include <Arduino.h>
#include <WiFi.h>
#include <PicoMQTT.h>

#include "modules/joystick/rjc_joystick.h"

WiFiClient wifi_client;
PicoMQTT::Server mqtt;

static const char*  SSID           = "KotAzurPloeg+2";
static const char*  PASSWORD       = "";
static const int    MQTT_PORT      = 1883;
static const char*  MQTT_USER      = "UCLL";
static const String mqtt_ID = "ESP32-" + String(random(0xffff), HEX);

void mqtt_callback(char* topic, byte* payload, unsigned int length);


void setup()
{
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);
  Serial.println ("Connecting to wifi ");
  while (WiFi.status() != WL_CONNECTED) 
  {
      delay(500);
      Serial.print(".");
  }
  Serial.printf("WiFi connected, IP: %s\n", WiFi.localIP().toString().c_str());
  mqtt.begin();
}

void loop()
{
  JoystickPosition joystick_position = RJC_JOYSTICK::get_mapped_position(-10, 10);
  if (joystick_position.y > 0) 
  {
    if(mqtt.publish("volume/up", "1"))
    {
      Serial.println("[mqtt]: volume up");
    }
    else
    {
      Serial.println("[mqtt_error]: failed to publish volume up");
    }
  }
  else if (joystick_position.y < 0)
  {
    if(mqtt.publish("volume/down", "1"))
    {
      Serial.println("[mqtt]: volume down");
    }
    else
    {
      Serial.println("[mqtt_error]: failed to publish volume down");
    }
  }

  mqtt.loop();
  delay(35);
}

void mqtt_callback(char* topic, byte* payload, unsigned int length) {
    // Handle received messages
    Serial.print("Received Message - Topic: ");
    Serial.println(topic);
    Serial.print("Payload: ");
    Serial.write(payload, length);
    Serial.println();
}