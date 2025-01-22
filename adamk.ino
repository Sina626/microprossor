#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte personDown[8] = {
  B00100,
  B00100,
  B01110,
  B10101,
  B00100,
  B01010,
  B10001,
  B00000
};

byte personUp[8] = {
  B00100,
  B10101,
  B01110,
  B00100,
  B01110,
  B00100,
  B01010,
  B00000
};

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, personDown);
  lcd.createChar(1, personUp);
  lcd.clear();
}

void loop() {
  int positions[32][2] = {
    {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, 
    {8, 0}, {9, 0}, {10, 0}, {11, 0}, {12, 0}, {13, 0}, {14, 0}, {15, 0},
    {15, 1}, {14, 1}, {13, 1}, {12, 1}, {11, 1}, {10, 1}, {9, 1}, {8, 1},
    {7, 1}, {6, 1}, {5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}
  };

  for (int i = 0; i < 32; i++) {
    lcd.clear();
    lcd.setCursor(positions[i][0], positions[i][1]);
    if (i % 2 == 0) {
      lcd.write(byte(0));
    } else {
      lcd.write(byte(1));
    }
    delay(900);
  }
}