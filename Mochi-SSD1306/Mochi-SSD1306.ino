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

  miata();
  delay(3000);
  wakeUp();
}


void loop() {
  long rdmCTP = random(1, 5);
  long rdmFace = random(1, 9);

  Serial.println(rdmFace);

  switch (rdmFace) {
    case 1:
      for (int i = 0; i < rdmCTP; i++) {
        happyWink();
      }
      break;

    case 2:
      for (int i = 0; i < rdmCTP; i++) {
        blinking();
      }
      break;

    case 3:
      for (int i = 0; i < rdmCTP; i++) {
        blushing();
      }
      break;

    case 4:
      smile();
      randomDelay();
      break;

    case 5:
      knock();
      randomDelay();
      break;

    case 6:
      excited();
      randomDelay();
      break;

    case 7:
      stars();
      randomDelay();
      break;

    case 8:
      display.clearDisplay();
      instagram();
      randomDelay();
      break;

    default:
      break;
  }
}

//Others
void miata() {
  display.clearDisplay();

  //Miata logo
  static const unsigned char PROGMEM miata[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x7f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x01, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x1f, 0xf9, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x3f, 0xf1, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0xff, 0xe1, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 
    0x03, 0xff, 0x01, 0xf8, 0x1f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 
    0x03, 0xfe, 0x03, 0xf0, 0x3f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x7e, 0x00, 0x00, 0x00, 0x00, 
    0x0b, 0xfe, 0x03, 0xd0, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 
    0x3f, 0xfc, 0x07, 0xa3, 0xff, 0xc0, 0x00, 0x7e, 0x00, 0x3f, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 
    0x3f, 0xf8, 0x07, 0x87, 0xef, 0xc0, 0x00, 0xfe, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 
    0x3f, 0xe0, 0x0f, 0x8f, 0xcf, 0xc0, 0x00, 0xff, 0x00, 0x3f, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 
    0x3f, 0xe0, 0x1f, 0xff, 0x0f, 0xcf, 0xe0, 0x3f, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 
    0x3f, 0xc0, 0x1e, 0x7f, 0x1f, 0xdf, 0xf0, 0x17, 0x00, 0x70, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 
    0x1f, 0x80, 0x3e, 0xfc, 0x3f, 0xff, 0xf8, 0x03, 0x00, 0xfc, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 
    0x0f, 0x00, 0x7f, 0xfc, 0x3f, 0xbf, 0xf8, 0x00, 0x01, 0xfc, 0xe0, 0x7e, 0x0f, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x7f, 0xe0, 0x3f, 0xff, 0xfc, 0x1f, 0x03, 0xff, 0xf8, 0x7c, 0x3f, 0xe0, 0x00, 0x00, 
    0x00, 0x00, 0x7f, 0xe0, 0x3f, 0xf9, 0xfe, 0x1f, 0x07, 0xfd, 0xf8, 0x7e, 0x7f, 0xfc, 0x00, 0x00, 
    0x00, 0x00, 0xff, 0xc0, 0x3f, 0xf9, 0xfe, 0x1f, 0x8f, 0xf9, 0xf8, 0x7e, 0x7f, 0xde, 0x00, 0x00, 
    0x00, 0x01, 0xff, 0x80, 0x3f, 0xf1, 0xfe, 0x1f, 0xdf, 0xf1, 0xfc, 0x7f, 0xfe, 0x0f, 0x80, 0x00, 
    0x00, 0x01, 0xff, 0x80, 0x3f, 0xf1, 0xfe, 0x0f, 0xff, 0xe0, 0xfc, 0x7f, 0xfe, 0x0f, 0xc0, 0x00, 
    0x00, 0x01, 0xff, 0x00, 0x3f, 0xf1, 0xfe, 0x0f, 0xff, 0xc0, 0xfe, 0x7f, 0xfc, 0x0f, 0xc0, 0x00, 
    0x00, 0x03, 0xfe, 0x00, 0x1f, 0xe1, 0xfe, 0x3f, 0xff, 0x80, 0xff, 0xff, 0xfc, 0x0f, 0xe0, 0x00, 
    0x00, 0x07, 0xfc, 0x00, 0x0f, 0xc1, 0xfe, 0x7f, 0xff, 0xc1, 0xff, 0xff, 0xfc, 0x07, 0xf0, 0x00, 
    0x00, 0x07, 0xf8, 0x00, 0x05, 0xc1, 0xff, 0xff, 0xff, 0xe3, 0xff, 0xff, 0xfc, 0x07, 0xfc, 0x00, 
    0x00, 0x1f, 0xf0, 0x00, 0x00, 0x00, 0xff, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xff, 0x80, 
    0x00, 0x1f, 0xe0, 0x00, 0x00, 0x00, 0xff, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x18, 
    0x00, 0x1f, 0xe0, 0x00, 0x00, 0x00, 0x7f, 0xe0, 0x0f, 0xff, 0x87, 0xff, 0xff, 0xf0, 0xff, 0xb8, 
    0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x03, 0xff, 0x00, 0x00, 0x3f, 0xc0, 0x07, 0xf0, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };
  display.drawBitmap(0, 0, miata, 128, 64, SSD1306_WHITE);
  display.display();
}

void loadingBar() {
  //Loading bar
  display.drawRect(14, 50, 100, 10, SSD1306_WHITE);
  display.display();

  for (int i = 1; i < 101; i++) {
    Serial.println(i);
    display.drawLine(14 + i, 50, 14 + i, 60, SSD1306_WHITE);
    display.display();
  }
}

void wakeUp() {
  display.clearDisplay();
  text(12, 21, 3, "MISHI!");
  delay(1000);

  display.clearDisplay();
  text(0, 21, 3, "WAKE UP");
  delay(1000);
}

void instagram() {
  text(2, 27, 2, "@neromiata");
}

void randomDelay() {
  long rdm = random(1, 10);
  delay(rdm * 1000);
}

void text(int cursorX, int cursorY, int txtSize, String txt) {
  display.setCursor(cursorX, cursorY);
  display.setTextSize(txtSize);
  display.setTextColor(SSD1306_WHITE);
  display.println(txt);
  display.display();
  delay(100);
}

//Static Faces
void cute() {
  display.clearDisplay();

  //Generated at : http://javl.github.io/image2cpp/
  //Eyes
  static const unsigned char PROGMEM eyeBMP[] = {
    0x1f, 0x80, 0x3f, 0xc0, 0x7f, 0xe0, 0x79, 0xe0, 0xf0, 0xf0, 0xe0, 0x70, 0xe0, 0x70, 0xe0, 0x70, 0xe0,
    0x70, 0xe0, 0x70, 0xe0, 0x70, 0xe0, 0x70, 0xe0, 0x70, 0xe0, 0x70, 0xe0, 0x70, 0xe0, 0x70, 0xe0, 0x70
  };

  //Mouth
  static const unsigned char PROGMEM happyMouthBMP[] = {
    0xf8, 0x00, 0x00, 0x01, 0xf0, 0xfe, 0x00, 0x00, 0x07, 0xf0, 0xff, 0x00, 0x00, 0x0f, 0xf0,
    0x7f, 0xff, 0xff, 0xff, 0xe0, 0x1f, 0xff, 0xff, 0xff, 0x80, 0x0f, 0xff, 0xff, 0xff, 0x00
  };

  //Left
  display.drawBitmap(16, 12, eyeBMP, 12, 17, SSD1306_WHITE);
  display.display();
  //Right
  display.drawBitmap(100, 12, eyeBMP, 12, 17, SSD1306_WHITE);
  display.display();

  //Mouth
  display.drawBitmap(46, 54, happyMouthBMP, 36, 6, SSD1306_WHITE);
  display.display();
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

void blush() {
  cute();

  display.drawLine(4, 44, 13, 37, SSD1306_WHITE);
  display.drawLine(15, 44, 24, 37, SSD1306_WHITE);
  display.drawLine(26, 44, 35, 37, SSD1306_WHITE);

  display.drawLine(88, 44, 97, 37, SSD1306_WHITE);
  display.drawLine(99, 44, 108, 37, SSD1306_WHITE);
  display.drawLine(110, 44, 119, 37, SSD1306_WHITE);

  display.display();
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

void excited() {
  display.clearDisplay();

  static const unsigned char PROGMEM leyeBMP[] = {
    0xc0, 0x00, 0x60, 0x00, 0x30, 0x00, 0x18, 0x00, 0x0c, 0x00, 0x06, 0x00, 0x03, 0x00, 0x01, 0x80, 
    0x00, 0xc0, 0x00, 0x60, 0x00, 0x30, 0x00, 0x18, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x18, 0x00, 0x30, 
    0x00, 0x60, 0x00, 0xc0, 0x01, 0x80, 0x03, 0x00, 0x06, 0x00, 0x0c, 0x00, 0x18, 0x00, 0x30, 0x00, 
    0x60, 0x00, 0xc0, 0x00
  };

  static const unsigned char PROGMEM reyeBMP[] = {
    0x00, 0x0c, 0x00, 0x18, 0x00, 0x30, 0x00, 0x60, 0x00, 0xc0, 0x01, 0x80, 0x03, 0x00, 0x06, 0x00, 
    0x0c, 0x00, 0x18, 0x00, 0x30, 0x00, 0x60, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0x60, 0x00, 0x30, 0x00, 
    0x18, 0x00, 0x0c, 0x00, 0x06, 0x00, 0x03, 0x00, 0x01, 0x80, 0x00, 0xc0, 0x00, 0x60, 0x00, 0x30, 
    0x00, 0x18, 0x00, 0x0c
  };

  //Left
  display.drawBitmap(20, 12, leyeBMP, 14, 26, SSD1306_WHITE);
  display.display();

  //Right
  display.drawBitmap(94, 12, reyeBMP, 14, 26, SSD1306_WHITE);
  display.display();

  //Mouth
  display.fillRoundRect(49, 54, 30, 6, 2,
                        SSD1306_WHITE);
  display.display();
}

void stars() {
  static const unsigned char PROGMEM star[] = {
    0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 
    0x00, 0x07, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 
    0x00, 0x0f, 0x80, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x1f, 0xc0, 0x00, 
    0x00, 0x3f, 0xe0, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xff, 0x00, 0x3f, 0xff, 0xff, 0xe0, 
    0xff, 0xff, 0xff, 0xf8, 0x3f, 0xff, 0xff, 0xe0, 0x0f, 0xff, 0xff, 0x80, 0x01, 0xff, 0xfc, 0x00, 
    0x00, 0x3f, 0xe0, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x1f, 0xc0, 0x00, 
    0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x0f, 0x80, 0x00, 
    0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 
    0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };

  //Eyes
  //Left
  display.drawBitmap(14, 4, star, 29, 34, SSD1306_WHITE);
  display.display();

  //Right
  display.drawBitmap(85, 4, star, 29, 34, SSD1306_WHITE);
  display.display();

  //Mouth
  display.fillRoundRect(49, 54, 30, 6, 2, SSD1306_WHITE);
  display.display();
}

//Animated Faces

void happyWink() {
  normal();
  randomDelay();

  wink();

  normal();
  delay(500);
}

void blinking() {
  normal();
  randomDelay();

  tired();
  delay(100);

  normal();
  delay(500);
}

void blushing() {
  cute();
  randomDelay();

  blush();
  randomDelay();

  cute();
  delay(500);
}