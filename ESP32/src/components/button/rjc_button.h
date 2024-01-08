#ifndef RJC_BUTTON_H
#define RJC_BUTTON_H

#include <Arduino.h>

class RJC_BUTTON {
    public:
    RJC_BUTTON(int pin);
    bool clicked();
    bool clicked_inv();
    
    private:
    int pin;
    int prev;
};

#endif //RJC_BUTTON_H