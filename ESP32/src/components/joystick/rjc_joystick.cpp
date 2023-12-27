#include "rjc_joystick.h"

void RJC_JOYSTICK::update_joystick_position(rjc_joystick_t *joystick_data)
{
    if (joystick_data->pos_x > joystick_data->center_x + joystick_data->deadzone || joystick_data->pos_x < joystick_data->center_x - joystick_data->deadzone)
    {
        joystick_data->pos_x = map(joystick_data->pos_x, 0, 4096, joystick_data->pos_min, joystick_data->pos_max);
    } 
    else
    {
        joystick_data->pos_x = 0;
    }

    if (joystick_data->pos_y > joystick_data->center_y + joystick_data->deadzone || joystick_data->pos_y < joystick_data->center_y - joystick_data->deadzone)
    {
        joystick_data->pos_y = map(joystick_data->pos_y, 0, 4096, joystick_data->pos_min, joystick_data->pos_max);
    }
    else
    {
        joystick_data->pos_y = 0;
    }
}