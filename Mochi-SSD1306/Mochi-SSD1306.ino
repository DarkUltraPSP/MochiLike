#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }
  display.clearDisplay();
}

void loop() {

  long rdmCTP = random(1, 5);
  long rdmFace = random(1, 8);

  Serial.println(rdmCTP + "fois repetee");
  Serial.println("Tete n°" + rdmFace);


  switch (rdmFace) {
    case 1:
      normal();
      randomDelay();
      break;
    case 2:
      for (int i; i < rdmCTP; i++) {
        happyWink();
      }
      break;
    case 3:
      knock();
      randomDelay();
      break;
    case 4:
      display.clearDisplay();
      instagram();
      randomDelay();
      break;
    case 5:
      tired();
      randomDelay();
      break;
    case 6:
      for (int i; i < rdmCTP; i++) {
        blinking();
      }
      break;
    case 7:
     smile();
     randomDelay();
     break;
    default:
      break;
  }
}

void smile() {
  display.clearDisplay();
  //Left
  display.drawLine(16, 32, 32, 12, SSD1306_WHITE);
  display.display();
  display.drawLine(32, 12, 48, 32, SSD1306_WHITE);
  display.display();

  //Right
  display.drawLine(112, 32, 96, 12, SSD1306_WHITE);
  display.display();
  display.drawLine(96, 12, 80, 32, SSD1306_WHITE);
  display.display();

  //Mouth
  display.fillRoundRect(49, 54, 30, 6, 2,
                        SSD1306_WHITE);
  display.display();
}

void normal() {
  display.clearDisplay();
  //Eyes
  //Left
  display.fillRoundRect(16, 12,
                        12, 20, 3,
                        SSD1306_WHITE);
  display.display();

  //Right
  display.fillRoundRect(100, 12,
                        12, 20, 3,
                        SSD1306_WHITE);
  display.display();

  //Mouth
  display.fillRoundRect(49, 54, 30, 6, 2,
                        SSD1306_WHITE);
  display.display();
}

void happyWink() {
  display.clearDisplay();

  normal();
  randomDelay();

  display.clearDisplay();
  wink();
}

void wink() {
  display.clearDisplay();
  //Eyes
  //Left
  display.fillRoundRect(16, 12,
                        12, 20, 3,
                        SSD1306_WHITE);
  display.display();

  //Right
  display.fillRoundRect(100, 20,
                        12, 5, 3,
                        SSD1306_WHITE);
  display.display();

  //Mouth
  display.fillRoundRect(54, 50,
                        20, 10, 3,
                        SSD1306_WHITE);
  display.display();
  delay(250);
}

void knock() {
  display.clearDisplay();

  //Eyes
  //Left
  text(16, 12, 3, "X");

  //Right
  text(97, 12, 3, "X");

  //Mouth
  display.fillRoundRect(49, 54,
                        30, 6, 2,
                        SSD1306_WHITE);
  display.display();
}

void instagram() {
  text(2, 27, 2, "@neromiata");
}

void tired() {
  display.clearDisplay();
  //Left
  display.fillRoundRect(16, 20,
                        12, 5, 3,
                        SSD1306_WHITE);
  display.display();
  //Right
  display.fillRoundRect(100, 20,
                        12, 5, 3,
                        SSD1306_WHITE);
  display.display();
  //Mouth
  display.fillRoundRect(49, 54, 30, 6, 2,
                        SSD1306_WHITE);
  display.display();
}

void blinking() {
  normal();
  randomDelay();

  tired();
  delay(100);
}

void randomDelay() {
  long rdm = random(1, 10);
  delay(rdm * 1000);
}

void text(int cursorX, int cursorY, int txtSize, String txt) {
  display.setCursor(cursorX, cursorY);
  display.setTextSize(txtSize);  // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.println(txt);
  display.display();  // Show initial text
  delay(100);
}