// #include <WiFi.h>
// #include <PubSubClient.h>
#include <BleMouse.h>

const char *ssid = "KotAzurPloeg+2";
const char *password = "";
const char *mqtt_server = "192.168.0.134";  // IP Address

// WiFiClient espClient;
// PubSubClient client(espClient);
BleMouse mouse("Joystick Controller", "UCLL");

struct JoystickState {
  mode: String,
}

// void setup_wifi() {
//   delay(10);
//   Serial.println("Connecting to WiFi");
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("WiFi connected");
// }

void setup_bluetooth() {
  mouse.begin();
}

void setup() {
  Serial.begin(9600);
  // setup_wifi();
  setup_bluetooth();
  // client.setServer(mqtt_server, 1883);
}

void move_mouse_with_joystick() {
  unsigned int joystick_x = analogRead(34);
  unsigned int joystick_y = analogRead(35);
  unsigned int joystick_center_x = 1920;
  unsigned int joystick_center_y = 1820;
  unsigned int joystick_deadzone = 100;

  int mapped_joystick_x = 0;
  int mapped_joystick_y = 0;
  if (joystick_x > joystick_center_x + joystick_deadzone || joystick_x < joystick_center_x - joystick_deadzone) {
    mapped_joystick_x = map(joystick_x, 0, 4096, -12, 12);
  }

  if (joystick_y > joystick_center_y + joystick_deadzone || joystick_y < joystick_center_y - joystick_deadzone) {
    mapped_joystick_y = map(joystick_y, 0, 4096, -12, 12);
  }

  Serial.print("\r");
  Serial.print("x: ");
  Serial.print(mapped_joystick_x);
  Serial.print(" | y: ");
  Serial.println(mapped_joystick_y);

  mouse.move(mapped_joystick_x, mapped_joystick_y);
}

void loop() {
  // Check mqtt connection
  // if (!client.connected()) {
  //   reconnect_mqtt();
  // }
  // client.loop();

  if(mouse.isConnected()) {
    move_mouse_with_joystick();
  }

  delay(25);
}

// void reconnect_mqtt() {
//   while (!client.connected()) {
//     Serial.print("Attempting MQTT connection...");
//     if (client.connect("ESP32Client")) {
//       Serial.println("connected");
//       client.subscribe("inTopic");
//     } else {
//       Serial.print("failed, rc=");
//       Serial.print(client.state());
//       Serial.println(" try again in 5 seconds");
//       delay(1000);
//     }
//   }
// }
