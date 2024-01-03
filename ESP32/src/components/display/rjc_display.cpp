#include "rjc_display.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void RJC_DISPLAY::begin()
{
    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println("SSD1306 allocation failed");
        for(;;); // Don't proceed, loop forever
    }

    draw_start_screen();

    display.display();
}

void RJC_DISPLAY::draw_start_screen()
{
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setCursor(10, 20);
    display.setTextSize(2);
    display.setTextWrap(1);
    display.println("RJC");
    display.drawLine(10, 42, 50, 42, WHITE);
    display.display();
    delay(2000);
    display.clearDisplay();
    display.display();
}

void RJC_DISPLAY::draw_top_section(String text)
{
    display.setTextColor(WHITE, 0);
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.setTextWrap(0);
    display.printf("%s    \n\r", text);
    display.display();
}

void RJC_DISPLAY::draw_system_page(rjc_joystick_t *joystick_data, String ip, const char* ssid)
{
    display.drawRect(0, 17, 128, 47, WHITE);

    display.setTextColor(WHITE, 0);
    display.setTextSize(1);
    display.setTextWrap(1);

    display.setCursor(3, 20);
    display.printf("WIFI: %s\n\r", ssid);

    display.setCursor(3, 30);
    display.printf("IP: %s\n\r", ip);

    display.setCursor(3, 40);
    display.printf("X: %i  \n\r", joystick_data->pos_x);

    display.setCursor(53, 40);
    display.printf("Y: %i  \n\r", joystick_data->pos_y);

    display.display();
}

void RJC_DISPLAY::draw_loading_animation()
{
    display.drawRect(10, 30, 108, 10, WHITE);
    display.display();
    for(int16_t i = 0; i <= 104; i += 8)
    {
        display.fillRect(12, 32, i, 6, WHITE);
        display.display();
        delay(500);
    }
    display.display();
    display.clearDisplay();
}