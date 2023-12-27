#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);

  delay(100);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed")); // Vraag aaan houben "F" "string"
    for(;;);
  }

  delay(100);

  // display.clearDisplay();
  // display.setTextColor(WHITE);
  // display.setCursor(0,10);
  // display.setTextSize(3);
  // display.setTextWrap(0);
  // display.println(F("Hello World!"));
  // display.display();

  int16_t x, y;
  uint16_t w, h;

  display.clearDisplay();
  display.getTextBounds("Media", 0, 0, &x, &y, &w, &h);
  display.setCursor(64-(x/2), 0);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  // display.println("CURSOR");
  // display.println("SCROLL");
  display.println("Media");
  display.display();
  delay(1000);
}