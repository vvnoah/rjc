// #include <Arduino.h>
// #include <WiFi.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using I2C
#define OLED_RESET     -1 // Reset pin
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
// // #include <WebSocketsServer.h>
// // #include <ArduinoJson.h>

// // #include <joystick/rjc_joystick.h>

// // WiFiClient wifi_client;
// // WebSocketsServer websocket = WebSocketsServer(81);

// // static const char*  SSID           = "BillyTheRobot";
// // static const char*  PASSWORD       = "eloict1234";


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
  delay(2000);
  
//   // WiFi.mode(WIFI_STA);
//   // WiFi.begin(SSID, PASSWORD);
//   // Serial.println("Connecting to WiFi ");
//   // while (WiFi.status() != WL_CONNECTED) {
//   //   delay(500);
//   //   Serial.print(".");
//   // }
//   // Serial.printf("WiFi connected, IP: %s\n", WiFi.localIP().toString().c_str());
//   // websocket.begin();
}

void loop() {
//   // JoystickPosition joystick_position = RJC_JOYSTICK::get_mapped_position(-10, 10);

//   // // Example: Send joystick position over WebSocket when the joystick is moved
//   // if (joystick_position.x != 0 || joystick_position.y != 0) {
//   //   // Create a JSON document
//   //   StaticJsonDocument<100> jsonDocument;

//   //   // Populate the JSON document
//   //   jsonDocument["type"] = "cursor";
//   //   jsonDocument["data"]["x"] = joystick_position.x;
//   //   jsonDocument["data"]["y"] = joystick_position.y;

//   //   // Serialize the JSON document to a String
//   //   String message;
//   //   serializeJson(jsonDocument, message);

//   //   // Send the message to all connected clients
//   //   websocket.broadcastTXT(message);

//   //   Serial.println("Sent joystick position over WebSocket: " + message);
//   // }

//   // websocket.loop();
// delay(20);
}