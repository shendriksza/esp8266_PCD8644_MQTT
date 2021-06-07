
// #include <Arduino.h>
#include <U8g2lib.h>
#ifdef U8G2_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8G2_HAVE_HW_I2C
#include <Wire.h>
#endif

// u8g2_PCD8544_84X48_F_4W_SW_SPI u8g2(u8g2_R0, /* clock=*/ 13, /* data=*/ 11, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8);  // Nokia 5110 Display
U8G2_PCD8544_84X48_F_4W_HW_SPI u8g2(U8G2_R2, /* cs=*/16, /* dc=*/17, /* reset=*/13); // Nokia 5110 Display

// typedef u8g2_uint_t u8g_uint_t;

#define SECONDS 10
uint8_t flip_color = 0;

#define TOUCH_THRESHOLD 40

#define PIN_TOUCH_UP 4
#define PIN_TOUCH_SELECT 0
#define PIN_TOUCH_DOWN 2

bool touched = false;

void setup()
{
	u8g2.begin();
	// u8g2.setRot180(); // flip screen
	u8g2.setFont(u8g2_font_4x6_tf);
	u8g2.clearBuffer();

	Serial.begin(115200);
	Serial.println("Booted");
}

int count = 0;
void loop()
{
	u8g2.setCursor(0, 6+6*count); // set cursor position
	u8g2.print("Print: ");
	u8g2.println(count);
	
	u8g2.sendBuffer();
	delay(1000);
	count++;

	// uint16_t up_val = touchRead(PIN_TOUCH_UP);
	// uint16_t sl_val = touchRead(PIN_TOUCH_SELECT);
	// uint16_t dw_val = touchRead(PIN_TOUCH_DOWN);

	// if (0 < up_val && up_val < TOUCH_THRESHOLD) {
	// 	if (!touched) {
	// 		Serial.print("UP: ");
	// 		Serial.println(up_val);
	// 		touched = true;
	// 		delay(200);
	// 	}
	// }
	// if (0 < sl_val && sl_val < TOUCH_THRESHOLD) {
	// 	if (!touched) {
	// 		Serial.print("SELECT: ");
	// 		Serial.println(sl_val);
	// 		touched = true;
	// 		delay(200);
	// 	}
	// }
	// if (0 < dw_val && dw_val < TOUCH_THRESHOLD) {
	// 	if (!touched) {
	// 		Serial.print("DOWN: ");
	// 		Serial.println(dw_val);
	// 		touched = true;
	// 		delay(200);
	// 	}
	// }
	// if (touched) {
	// 	touched = false;
	// }
}
