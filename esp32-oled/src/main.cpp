#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <Wire.h>
// Setup the SSD1306 display
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Create an instance of the display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
void setup() {
  // Initialize serial communication for debugging (optional)
  Serial.begin(115200);
  // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC,
                     0x3C)) { // Use SSD1306_SWITCHCAPVCC instead
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }
  // Clear the buffer
  display.clearDisplay();
  // Set text size and color
  display.setTextSize(2);      // Size 1 is small, 2 is medium
  display.setTextColor(WHITE); // Draw white text
  // Set the cursor position
  display.setCursor(0, 0); // Start at top-left corner
  // Print Hello, World! to the display
  display.print(F("Hello, World!"));
  // Display the text on the OLED
  display.display();
}
void loop() {}
// Below is a V2 per say
/*
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <Wire.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int lineX = 0;
int lineDirection = 1;
String messages[] = {"Hello, World!", "Welcome to OLED", "Arduino is fun!",
                     "Let's animate!"};
int messageIndex = 0;

void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print(F("Hello, World!"));
  display.display();
  delay(2000);
}

void loop() {
  display.clearDisplay();

  display.setCursor(0, 0);
  display.print(messages[messageIndex]);

  messageIndex = (messageIndex + 1) % (sizeof(messages) / sizeof(messages[0]));

  display.drawLine(lineX, SCREEN_HEIGHT / 2, lineX + 50, SCREEN_HEIGHT / 2,
                   WHITE);

  display.display();

  lineX += lineDirection;

  if (lineX < 0 || lineX > SCREEN_WIDTH - 50) {
    lineDirection *= -1;
  }

  delay(1000);
}
*/
