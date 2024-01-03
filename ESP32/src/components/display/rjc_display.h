#ifndef RJC_DISPLAY_H
#define RJC_DISPLAY_H

#include <Arduino.h>
#include <string.h>
#include <SPI.h> 
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "../joystick/rjc_joystick.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3C

extern Adafruit_SSD1306 display;

class RJC_DISPLAY
{
    private:
    void draw_start_screen();

    public:
    void begin();
    void draw_top_section(String text);
    void draw_system_page(rjc_joystick_t *joystick_data, String ip, const char* ssid);
    void draw_loading_animation();
};

#endif //RJC_DISPLAY_H