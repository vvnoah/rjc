#ifndef RJC_JOYSTICK_H
#define RJC_JOYSTICK_H

#include <Arduino.h>
#include <cstdlib>
#include <ctime>

struct rjc_joystick_t {
    int pin_x = 34;
    int pin_y = 35;

    int pos_min = -10;
    int pos_max = 10;

    int pos_x = 0;
    int pos_y = 0;

    int center_x = 1920;
    int center_y = 1820;

    int deadzone = 100;
};

class RJC_JOYSTICK 
{
    public:
    void update_joystick_position(rjc_joystick_t *joystick_data);
    void update_joystick_position_randomly(rjc_joystick_t *joystick_data);
};

#endif //RJC_JOYSTICK_H