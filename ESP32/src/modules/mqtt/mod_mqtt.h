#ifndef MOD_MQTT_H
#define MOD_MQTT_H

#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

extern WiFiClient wifi_client;
extern PubSubClient mqtt_client;

static const char*  SSID           = "";
static const char*  PASSWORD       = "";
static const char*  MQTT_SERVER    = "";
static const int    MQTT_PORT      = 3000;
static const char*  MQTT_USER      = "UCLL";
static const String MQTT_CLIENT_ID = "ESP32-" + String(random(0xffff), HEX);

class MOD_MQTT 
{
    public:
    static void setup();
    static void loop();

    private:
    static void connect_mqtt();
};

#endif