#include <Wire.h>
#include "ST7567_FB_I2C.h"
// from PropFonts library
#include "c64enh_font.h"
// Include a font file if you are using one.
// Fonts can be found here: https://github.com/cbm80amiga/PropFonts
// #include <Arial_14.h>


// ---- PIN DEFINITIONS ----
// The only pin you need for the I2C version is the RESET pin.
// Connect SCL to A5 and SDA to A4 on an Arduino Uno.
#define RST_PIN 255
// I2C pins (adjust based on your board)
#define I2C_SDA 9
#define I2C_SCL 8
// ---- I2C ADDRESS ----
// The I2C address for these displays is often 0x3F or 0x3C.
// Use an I2C scanner sketch if you are unsure.
#define I2C_ADDR 0x3F

// Create an instance of the library
ST7567_FB_I2C lcd(RST_PIN, I2C_ADDR);

// from PropFonts library
#include "c64enh_font.h"

void setup() 
{
  Wire.setPins(I2C_SDA, I2C_SCL);
  Serial.begin(9600);
  Serial.println("ST7567 I2C Test");
  Wire.begin();
  // Initialize the display. You can optionally pass a contrast value from 0-31.
  lcd.init(3);
  lcd.cls();
  lcd.setFont(c64enh);
  lcd.printStr(ALIGN_CENTER, 28, "Hello World!");
  lcd.drawRectD(0,0,128,64,1);
  lcd.drawRect(18,20,127-18*2,63-20*2,1);
  lcd.display();
}

void loop() 
{
}

