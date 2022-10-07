#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

#define TFT_CS 10
#define TFT_RST 8 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC 9

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("Hello! ST77xx TFT Test"));

  tft.initR(INITR_BLACKTAB);

  tft.fillScreen(ST77XX_BLACK);
  Serial.println("Initialized");
  loading();
}

void loop()
{
  randomTextFaces();
}

void randomTextFaces()
{
  // Random Faces
  int randomNum = random(0, 6);
  Serial.println(randomNum);
  switch (randomNum)
  {
  case 0:
    emojiSize("-_-");
    break;

  case 1:
    emojiSize("O_O");
    break;
  case 2:
    emojiSize("O_o");
    break;
  case 3:
    emojiSize("o_O");
    break;
  case 4:
    text("Instagram", 50, 2);
    text("@neromiata", 70, 2);
    delay(4000);
    break;
  case 5:
    happy();
    break;

  default:
    break;
  }
}

void emojiSize(String text)
{
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(10, 65);
  tft.setTextColor(ST7735_WHITE);
  tft.setTextSize(6);
  tft.setTextWrap(1);
  tft.print(text);
  int rand = random(1500, 4000);
  Serial.println(rand);
  delay(rand);
}

void text(String text, int screenHeight, int fontSize)
{
  tft.setCursor(5, screenHeight);
  tft.setTextColor(ST7735_CYAN);
  tft.setTextSize(fontSize);
  tft.setTextWrap(1);
  tft.print(text);
  tft.fillScreen(ST77XX_BLACK);
}

void line(uint16_t color)
{
  tft.fillScreen(ST77XX_BLACK);
  // Point de depart, point d'arrivée et couleur
  tft.drawLine(0, 0, 50, tft.height() - 0, color);
  tft.drawLine(1, 1, 51, tft.height() - 0, color);
}

void drawCircles()
{
  tft.fillScreen(ST77XX_BLACK);
  for (int i = 10; i < 70; i++)
  {
    tft.drawCircle(64, 64, i, ST77XX_WHITE);
  }
}

void DrawAngledLine(int x, int y, int x1, int y1, int size, uint16_t color)
{
  float dx = (size / 2.0) * (y - y1) / sqrt(sq(x - x1) + sq(y - y1));
  float dy = (size / 2.0) * (x - x1) / sqrt(sq(x - x1) + sq(y - y1));
  tft.fillTriangle(x + dx, y - dy, x - dx, y + dy, x1 + dx, y1 - dy, color);
  tft.fillTriangle(x - dx, y + dy, x1 - dx, y1 + dy, x1 + dx, y1 - dy, color);
}

void drawArc()
{
  float start_angle = 0.5, end_angle = 1.5;
  int x = 50, y = 100, r = 30;
  for (float i = start_angle; i < end_angle; i = i + 0.05)
  {
    tft.drawPixel(x + cos(i) * r, y + sin(i) * r, ST7735_BLUE); // center point is (50,100)
  }
}

void happy()
{
  tft.fillScreen(ST77XX_BLACK);
  // Eyes
  tft.drawLine(25, 70, 40, 40, ST77XX_WHITE);
  tft.drawLine(40, 40, 55, 70, ST77XX_WHITE);
  tft.drawLine(70, 70, 85, 40, ST77XX_WHITE);
  tft.drawLine(85, 40, 100, 70, ST77XX_WHITE);
  // Mouth
  tft.drawLine(45, 100, 80, 100, ST77XX_WHITE);
  tft.drawLine(45, 101, 80, 101, ST77XX_WHITE);
  tft.drawLine(45, 102, 80, 102, ST77XX_WHITE);
  tft.fillCircle(45, 101, 1, ST77XX_WHITE);
  tft.fillCircle(80, 101, 1, ST77XX_WHITE);
  delay(4000);
}

void loading()
{
  littleGuySleeping();
  // Loading
  tft.setCursor(25, 50);
  tft.setTextColor(ST7735_WHITE);
  tft.setTextSize(2);
  tft.setTextWrap(1);
  tft.print("Loading");

  // Dessin barre chargement
  // drawLine((XY), (XY), Couleur)
  // Horizontal
  tft.drawLine(16, 70, 112, 70, ST77XX_WHITE);
  tft.drawLine(16, 71, 112, 71, ST77XX_WHITE);

  tft.drawLine(16, 90, 112, 90, ST77XX_WHITE);
  tft.drawLine(16, 91, 112, 91, ST77XX_WHITE);

  // Vertical
  tft.drawLine(16, 70, 16, 90, ST77XX_WHITE);
  tft.drawLine(17, 70, 17, 90, ST77XX_WHITE);

  tft.drawLine(112, 70, 112, 90, ST77XX_WHITE);
  tft.drawLine(113, 70, 113, 90, ST77XX_WHITE);

  // Chargement
  for (int i = 0; i < 96; i++)
  {
    tft.drawLine(17 + i, 71, 17 + i, 89, ST77XX_GREEN);
    delay(30);
  }

  for (int i = 0; i < 160; i++)
  {
    tft.drawLine(0, i, 128, i, ST77XX_BLACK);
    delay(2);
  }

  tft.setCursor(45, 50);
  tft.setTextColor(ST7735_WHITE);
  tft.setTextSize(8);
  tft.setTextWrap(1);
  tft.print("!");
  delay(500);

  for (int i = 0; i < 160; i++)
  {
    tft.drawLine(0, i, 128, i, ST77XX_BLACK);
    delay(5);
  }

  tft.setCursor(20, 60);
  tft.setTextColor(ST7735_WHITE);
  tft.setTextSize(5);
  tft.setTextWrap(1);
  tft.print("Hi!");
  delay(500);
  tft.fillScreen(ST77XX_BLACK);
}

void littleGuySleeping()
{
  // Eyes
  // Left
  tft.drawLine(94, 140, 98, 140, ST77XX_WHITE);

  tft.drawPixel(93, 139, ST77XX_WHITE);
  tft.drawPixel(92, 138, ST77XX_WHITE);
  tft.drawPixel(99, 139, ST77XX_WHITE);
  tft.drawPixel(100, 138, ST77XX_WHITE);
  // Right
  tft.drawLine(104, 140, 108, 140, ST77XX_WHITE);

  tft.drawPixel(103, 139, ST77XX_WHITE);
  tft.drawPixel(102, 138, ST77XX_WHITE);
  tft.drawPixel(109, 139, ST77XX_WHITE);
  tft.drawPixel(110, 138, ST77XX_WHITE);

  // Mouth
  tft.drawLine(96, 147, 106, 147, ST77XX_WHITE);

  tft.drawPixel(95, 146, ST77XX_WHITE);
  tft.drawPixel(107, 146, ST77XX_WHITE);

  // zzzzz
  tft.drawLine(112, 136, 115, 136, ST77XX_WHITE);
  tft.drawLine(115, 132, 112, 136, ST77XX_WHITE);
  tft.drawLine(112, 132, 115, 132, ST77XX_WHITE);

  tft.drawLine(117, 132, 120, 132, ST77XX_WHITE);
  tft.drawLine(120, 128, 117, 132, ST77XX_WHITE);
  tft.drawLine(117, 128, 120, 128, ST77XX_WHITE);
}