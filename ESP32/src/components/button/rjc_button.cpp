#include "rjc_button.h"

RJC_BUTTON::RJC_BUTTON(int pin) : pin(pin), prev(LOW)
{
    pinMode(pin, INPUT);
}

bool RJC_BUTTON::clicked()
{
    int current = digitalRead(pin);
    if(current != prev)
    {
        if(current == HIGH)
        {
            delay(200);
            return true;
        }
    }
    prev = current;
    return false;
}

bool RJC_BUTTON::clicked_inv()
{
    int current = digitalRead(pin);
    if(current != prev)
    {
        if(current == LOW)
        {
            delay(200);
            return true;
        }
    }
    prev = current;
    return false;
}