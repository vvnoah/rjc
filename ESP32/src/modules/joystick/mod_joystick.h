#ifndef MOD_JOYSTICK_H
#define MOD_JOYSTICK_H

#include <Arduino.h>

struct JoystickPosition {
    int x;
    int y;
};

class MOD_JOYSTICK
{
    public:
    static void setup();
    static void loop();
    static JoystickPosition get_mapped_joystick_position(int min, int max);
};

#endif