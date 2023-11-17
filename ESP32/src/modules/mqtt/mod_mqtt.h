#ifndef MOD_MQTT_H
#define MOD_MQTT_H

#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

WiFiClient wifi_client;
PubSubClient mqtt_client(wifi_client);

const char*  SSID           = "";
const char*  PASSWORD       = "";
const char*  MQTT_SERVER    = "";
const int    MQTT_PORT      = 3000;
const char*  MQTT_USER      = "UCLL";
const String MQTT_CLIENT_ID = "ESP32-" + String(random(0xffff), HEX);

class MOD_MQTT 
{
    public:
    static void setup();
    static void loop();

    private:
    static void connect_mqtt();
};

#endif