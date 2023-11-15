#include <Arduino.h>
#include <BleMouse.h>

BleMouse mouse("Joystick Controller", "UCLL");

void move_mouse_with_joystick();

void setup() {
  Serial.begin(9600);
  mouse.begin();
}

void loop() {
  if(mouse.isConnected()) {
    move_mouse_with_joystick();
  }

  delay(35);
}

void move_mouse_with_joystick() {
  unsigned int joystick_x = analogRead(34);
  unsigned int joystick_y = analogRead(35);
  unsigned int joystick_center_x = 1920;
  unsigned int joystick_center_y = 1820;
  unsigned int joystick_deadzone = 100;

  // Linear mapping.
  int mapped_joystick_x = 0;
  int mapped_joystick_y = 0;
  
  if (joystick_x > joystick_center_x + joystick_deadzone || joystick_x < joystick_center_x - joystick_deadzone) {
    mapped_joystick_x = map(joystick_x, 0, 4096, -15, 15);
  }

  if (joystick_y > joystick_center_y + joystick_deadzone || joystick_y < joystick_center_y - joystick_deadzone) {
    mapped_joystick_y = map(joystick_y, 0, 4096, -15, 15);
  }

  Serial.print("\r");
  Serial.print("x: ");
  Serial.print(mapped_joystick_x);
  Serial.print(" | y: ");
  Serial.println(mapped_joystick_y);

  mouse.move(mapped_joystick_x, mapped_joystick_y);
}