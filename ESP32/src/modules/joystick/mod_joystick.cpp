#include "mod_joystick.h"

void MOD_JOYSTICK::setup()
{
}

void MOD_JOYSTICK::loop()
{
}

JoystickPosition MOD_JOYSTICK::get_mapped_joystick_position(int min, int max)
{
    unsigned int joystick_x = analogRead(34);
    unsigned int joystick_y = analogRead(35);
    unsigned int joystick_center_x = 1920;
    unsigned int joystick_center_y = 1820;
    unsigned int joystick_deadzone = 100;

    // Linear mapping.
    JoystickPosition mapped_position;
    mapped_position.x = 0;
    mapped_position.y = 0;

    if (joystick_x > joystick_center_x + joystick_deadzone || joystick_x < joystick_center_x - joystick_deadzone)
    {
        mapped_position.x = map(joystick_x, 0, 4096, min, max);
    }

    if (joystick_y > joystick_center_y + joystick_deadzone || joystick_y < joystick_center_y - joystick_deadzone)
    {
        mapped_position.y = map(joystick_y, 0, 4096, min, max);
    }

    Serial.print("\r");
    Serial.print("x: ");
    Serial.print(mapped_position.x);
    Serial.print(" | y: ");
    Serial.println(mapped_position.y);

    return mapped_position;
}