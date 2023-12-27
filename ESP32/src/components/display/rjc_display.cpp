#include "rjc_display.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void RJC_DISPLAY::begin()
{
    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println("SSD1306 allocation failed");
        for(;;); // Don't proceed, loop forever
    }

    draw_start_screen();    
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