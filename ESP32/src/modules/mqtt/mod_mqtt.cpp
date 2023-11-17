#include "mod_mqtt.h"

void MOD_MQTT::setup() 
{
    WiFi.begin(SSID, PASSWORD);
    Serial.println ("Connecting to wifi ");

    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("Connected.");

    mqtt_client.setServer(MQTT_SERVER, MQTT_PORT);
}

void MOD_MQTT::loop() 
{
    if (!mqtt_client.connected()) 
    {
        connect_mqtt();
    }
    mqtt_client.loop();
}

void MOD_MQTT::connect_mqtt() 
{
    while (!mqtt_client.connected()) 
    {
        Serial.println("Connecting to MQTT client ");
        if (mqtt_client.connect("ESP32Client")) 
        {
            // Subscribes here.
        }
        else
        {
            Serial.println("Failed. Client: ");
            Serial.print(mqtt_client.state());
            Serial.println("Trying again.");
            delay(1000);
        }
    }
}