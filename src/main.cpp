#include <U8x8lib.h>
#include <U8g2lib.h>
 
// Nokia 5110 LCD module connections
// GND, BL, VCC, CLK, DIN, DC, CE, RST
// GND, - , 5V , D5 , D7 , D4, D8, D0             
#define PIN_RES 16 //GPIO16 (D0)
#define PIN_CE  15 //GPIO15 (D8), pull-down 10k to GND
#define PIN_DC  2 //GPIO2 (D4)
// #define PIN_CLOCK = D5 //SCK
// #define PIN_DATA = D7 //MOSI

//U8G2_PCD8544_84X48_1_4W_SW_SPI u8g2 = U8G2_PCD8544_84X48_1_4W_SW_SPI(U8G2_R0, PIN_CLOCK, PIN_DATA, PIN_CE, PIN_DC, PIN_RES);  // SW SPI
// U8G2_PCD8544_84X48_1_4W_HW_SPI u8g2(U8G2_R0, PIN_CE, PIN_DC, PIN_RES);                       // HW SPI
U8X8_PCD8544_84X48_4W_HW_SPI u8x8( PIN_CE, PIN_DC, PIN_RES);

void setup()   {
  u8x8.begin();
  // u8x8.firstPage();
  // do {
  //   u8g2.setFont( u8g2_font_nokiafc22_tr );
  //   u8g2.drawStr(0, 8,  "TestAB123 1");
  //   u8g2.setFont( u8g2_font_profont11_tr );
  //   u8g2.drawStr(0, 16, "Test123 2");
  //   u8g2.setFont( u8g2_font_5x7_tr );
  //   u8g2.drawStr(0, 30, "Test123 4");
  // } while ( u8g2.nextPage() );
}
 
 int number1 = 0;
void loop() {
  u8x8.setFont(u8x8_font_amstrad_cpc_extended_r);
  u8x8.print("eat farts");
  u8x8.println(number1);
  number1++;
  delay(1000);
}
 

 
// end of code.