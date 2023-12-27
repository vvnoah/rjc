#ifndef RJC_JOYSTICK_H
#define RJC_JOYSTICK_H

#include <Arduino.h>

struct JoystickPosition {
    int x;
    int y;
};

JoystickPosition get_mapped_position(int min, int max);

#endif