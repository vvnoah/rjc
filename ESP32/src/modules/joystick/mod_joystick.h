#ifndef MOD_JOYSTICK_H
#define MOD_JOYSTICK_H

#include <Arduino.h>
#include <BleMouse.h>

BleMouse mouse("Joystick Controller", "UCLL");

struct JoystickPosition {
    int x;
    int y;
};

const int joystick_click_pin = 2;
bool scrolling_mode = false;

class MOD_JOYSTICK
{
    public:
    static void setup();
    static void loop();

    private:
    static JoystickPosition get_mapped_joystick_position(int min, int max);
    static void move_mouse_with_joystick();
    static void scroll_mouse_with_joystick();
};

#endif