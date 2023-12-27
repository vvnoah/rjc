#include "rjc_display.h"

#define LAY_IMPLEMENTATION
#include "layout.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void RJC_DISPLAY::begin()
{
    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println("SSD1306 allocation failed");
        for(;;); // Don't proceed, loop forever
    }

    draw_start_screen();

    lay_context ctx;
    lay_init_context(&ctx);
    lay_reserve_items_capacity(&ctx, 1024);
    lay_id root = lay_item(&ctx);
    lay_set_size_xy(&ctx, root, SCREEN_WIDTH, SCREEN_HEIGHT);
    lay_set_contain(&ctx, root, LAY_COLUMN);

    lay_id top_bar = lay_item(&ctx);
    lay_set_size_xy(&ctx, top_bar, 128, 16);
    lay_insert(&ctx, root, top_bar);
    lay_set_contain(&ctx, top_bar, LAY_ROW);

    lay_id top_bar_text = lay_item(&ctx);
    lay_set_size_xy(&ctx, top_bar_text, 64, 16);
    lay_insert(&ctx, top_bar, top_bar_text);

    lay_id content_view = lay_item(&ctx);
    lay_insert(&ctx, root, content_view);
    lay_set_behave(&ctx, content_view, LAY_HFILL | LAY_VFILL);
    lay_set_contain(&ctx, content_view, LAY_COLUMN);

    lay_id content_item_1 = lay_item(&ctx);
    lay_set_size_xy(&ctx, content_item_1, 128, 8);
    lay_insert(&ctx, content_view, content_item_1);

    lay_run_context(&ctx);

    lay_vec4 content_view_rect = lay_get_rect(&ctx, content_view);
    lay_vec4 top_bar_text_rect = lay_get_rect(&ctx, top_bar_text);
    lay_vec4 content_item_1_rect = lay_get_rect(&ctx, content_item_1);

    display.setTextColor(WHITE);
    display.setCursor(top_bar_text_rect[0], top_bar_text_rect[1]);
    display.setTextSize(2);
    display.setTextWrap(0);
    display.println("Info");

    display.setCursor(content_item_1_rect[0], content_item_1_rect[1]);
    display.setTextSize(1);
    display.println("IP: 192.168.69.420");

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