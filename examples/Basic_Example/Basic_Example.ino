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



void setup() {
  Wire.setPins(I2C_SDA, I2C_SCL);
  Serial.begin(9600);
  Serial.println("ST7567 I2C Test");
  Wire.begin();
  // Initialize the display. You can optionally pass a contrast value from 0-31.
  lcd.init(3);

  // Clear the framebuffer
  lcd.cls();

  // Set a font (optional, if you have included a font file)
  // lcd.setFont(Arial_14);
  lcd.setFont(c64enh);
  // Draw some text in the framebuffer
  // The coordinates can be ALIGN_LEFT, ALIGN_CENTER, or ALIGN_RIGHT
  lcd.drawRect(5, 5, 118, 54, SET);

  lcd.printStr(ALIGN_CENTER, 10, "Hello, I2C!");
  lcd.printStr(ALIGN_CENTER, 30, "This is the");
  lcd.printStr(ALIGN_CENTER, 45, "modified library.");

  // Draw a rectangle

  // Send the framebuffer contents to the display
  lcd.display();
}

void loop() {
  // The display is static, no need to refresh in the loop
  // unless the content is changing.
  delay(1000);
}