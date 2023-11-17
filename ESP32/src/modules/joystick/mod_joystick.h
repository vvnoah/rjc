#ifndef MOD_JOYSTICK_H
#define MOD_JOYSTICK_H

#include <Arduino.h>
#include <BleMouse.h>

BleMouse mouse("Joystick Controller", "UCLL");

class MOD_JOYSTICK
{
    public:
    static void setup();
    static void loop();

    private:
    static void move_mouse_with_joystick();
};

#endif