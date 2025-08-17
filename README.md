# I2C Graphics Library for ST7567 128x64 LCD

This is a fast, framebuffer-based graphics library for monochrome 128x64 liquid crystal displays driven by the ST7567 controller over an I2C interface. It is optimized for performance and includes support for advanced features like proportional fonts and dithering.

This code is based on the original SPI library by Pawel A. Hernik.

![ST7567S LCD back view](https://raw.githubusercontent.com/nor24o/ST7567_FB_I2C/main/doc/128X64_I2C_ST7567S_back.png)
![ST7567S LCD working state](https://github.com/nor24o/ST7567_FB_I2C/blob/main/doc/Working.jpg)

## Key Features

- **Full Graphics Control**: Draw pixels, lines, rectangles, circles, and triangles (both outline and filled).
- **Proportional Fonts**: Built-in support for proportional fonts for professional-looking text. (Requires fonts from the [PropFonts library](https://github.com/cbm80amiga/PropFonts)).
- **Fast Dithering**: Includes 17 pre-defined patterns for creating fast, ordered dithering effects to simulate shades of gray.
- **Optimized Drawing**: Contains highly accelerated functions for drawing horizontal and vertical lines.
- **Bitmap Support**: Easily draw monochrome bitmaps on the screen.

## Connections

To use the library, connect your display to your microcontroller as follows. These pins are examples and can be configured in your code.

| LCD Pin | Pin Name | Arduino / ESP32 |
| :------ | :------- | :-------------- |
| #01     | SDA      | A4 / GPIO 21    |
| #02     | SCL      | A5 / GPIO 22    |
| #07     | VCC      | 3.3V            |
| #08     | GND      | GND             |
| *#03* | *RST* | *(Optional)* |

The library has been tested on the ESP32-S3 platform.

## Quick Start

1.  **Install the Library**: Add this library to your PlatformIO project.
2.  **Include the Header**: Add `#include "ST7567_FB_I2C.h"` to your main `.ino` or `.cpp` file.
3.  **Instantiate the Display**: Create an object for your display, providing the reset pin (optional) and I2C address.

    ```cpp
    #include "ST7567_FB_I2C.h"

    // Define your pins and I2C address
    #define LCD_RST   4
    #define I2C_ADDR  0x3F

    ST7567_FB_I2C lcd(LCD_RST, I2C_ADDR);
    ```

4.  **Initialize and Use**: In your `setup()` function, initialize the display. You can then clear it and start drawing.

    ```cpp
    void setup() {
      lcd.init();      // Initialize the display
      lcd.cls();       // Clear the screen buffer
      lcd.printStr(0, 0, "Hello, World!"); // Draw text
      lcd.display();   // Send the buffer to the screen
    }

    void loop() {
      // Your code here
    }
    ```







