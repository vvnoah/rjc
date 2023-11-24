#ifndef MOD_JOYSTICK_H
#define MOD_JOYSTICK_H

#include <Arduino.h>

struct JoystickPosition {
    int x;
    int y;
};

class RJC_JOYSTICK
{
    public:
    static JoystickPosition get_mapped_position(int min, int max);
};

#endif