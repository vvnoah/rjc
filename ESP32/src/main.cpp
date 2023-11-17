#include <Arduino.h>

#include "modules/mqtt/mod_mqtt.h"
#include "modules/joystick/mod_joystick.h"

void setup()
{
  Serial.begin(9600);

  MOD_MQTT::setup();
  MOD_JOYSTICK::setup();
  
}

void loop()
{
  MOD_MQTT::loop();
  MOD_JOYSTICK::loop();


  delay(35);
}