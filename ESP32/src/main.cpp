#include <Arduino.h>

#include "modules/mqtt/mod_mqtt.h"
#include "modules/joystick/mod_joystick.h"

WiFiClient wifi_client;
PubSubClient mqtt_client(wifi_client);

void setup()
{
  Serial.begin(9600);
  MOD_MQTT::setup();
  
}

void loop()
{
  MOD_MQTT::loop();


  delay(35);
}