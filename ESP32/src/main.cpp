#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

WiFiClient wifi_client;
PubSubClient mqtt_client(wifi_client);

const char* SSID = "0.0.0.0";
const char* PASSWORD = "";
const char* MQTT_SERVER = "0.0.0.0"; // IP
const int MQTT_PORT = 3000;
const char* MQTT_USER = "ucll";
const String MQTT_CLIENTID = "ESP32-" + String(random(0xffff), HEX);

void get_mapped_joystick_position();
void connect_mqtt();

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println(WiFi.localIP());
}

void loop() {
  if(WiFi.status() == WL_CONNECTED) {
    if(!mqtt_client.connected()) {
      connect_mqtt();
    }
    mqtt_client.loop();

    // IF MODE MEDIA, GET BUTTON INPUT AND PUBLISH MEDIA COMMANDS.
    mqtt_client.publish("/media/audio_vol_up", "");
  }

  delay(35);
}

struct JoystickPosition {
  int x;
  int y;
};

JoystickPosition get_mapped_joystick_position(int min, int max) {
  unsigned int joystick_x = analogRead(34);
  unsigned int joystick_y = analogRead(35);
  unsigned int joystick_center_x = 1920;
  unsigned int joystick_center_y = 1820;
  unsigned int joystick_deadzone = 100;

  // Linear mapping.
  JoystickPosition mapped_joystick_position;
  mapped_joystick_position.x = 0;
  mapped_joystick_position.y = 0;
  
  if (joystick_x > joystick_center_x + joystick_deadzone || joystick_x < joystick_center_x - joystick_deadzone) {
    mapped_joystick_position.x = map(joystick_x, 0, 4096, min, max);
  }

  if (joystick_y > joystick_center_y + joystick_deadzone || joystick_y < joystick_center_y - joystick_deadzone) {
    mapped_joystick_position.y = map(joystick_y, 0, 4096, min, max);
  }

  Serial.print("\r");
  Serial.print("x: ");
  Serial.print(mapped_joystick_position.x);
  Serial.print(" | y: ");
  Serial.println(mapped_joystick_position.y);

  return mapped_joystick_position;
} 

void connect_mqtt() {
  mqtt_client.setServer(MQTT_SERVER, MQTT_PORT);
}