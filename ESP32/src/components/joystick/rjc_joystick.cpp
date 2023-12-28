#include "rjc_joystick.h"

void RJC_JOYSTICK::update_joystick_position(rjc_joystick_t *joystick_data)
{
    int unmapped_pos_x = analogRead(joystick_data->pin_x);
    int unmapped_pos_y = analogRead(joystick_data->pin_y);
    
    if (unmapped_pos_x > joystick_data->center_x + joystick_data->deadzone || unmapped_pos_x < joystick_data->center_x - joystick_data->deadzone)
    {
        joystick_data->pos_x = map(unmapped_pos_x, 0, 4096, joystick_data->pos_min, joystick_data->pos_max);
    } 
    else
    {
        joystick_data->pos_x = 0;
    }

    if (unmapped_pos_y > joystick_data->center_y + joystick_data->deadzone || unmapped_pos_y < joystick_data->center_y - joystick_data->deadzone)
    {
        joystick_data->pos_y = map(unmapped_pos_y, 0, 4096, joystick_data->pos_min, joystick_data->pos_max);
    }
    else
    {
        joystick_data->pos_y = 0;
    }
}

void RJC_JOYSTICK::update_joystick_position_randomly(rjc_joystick_t *joystick_data)
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    int unmapped_pos_x = std::rand() % 4096;

    std::srand(static_cast<unsigned int>(std::time(0)));
    int unmapped_pos_y = std::rand() % 4096;

    if (unmapped_pos_x > joystick_data->center_x + joystick_data->deadzone || unmapped_pos_x < joystick_data->center_x - joystick_data->deadzone)
    {
        joystick_data->pos_x = map(unmapped_pos_y, 0, 4096, joystick_data->pos_min, joystick_data->pos_max);
    } 
    else
    {
        joystick_data->pos_x = 0;
    }

    if (unmapped_pos_y > joystick_data->center_y + joystick_data->deadzone || unmapped_pos_y < joystick_data->center_y - joystick_data->deadzone)
    {
        joystick_data->pos_y = map(unmapped_pos_y, 0, 4096, joystick_data->pos_min, joystick_data->pos_max);
    }
    else
    {
        joystick_data->pos_y = 0;
    }
}
