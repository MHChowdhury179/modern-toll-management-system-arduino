#include <LiquidCrystal.h>

const int IRsensor1 = 3;
const int IRsensor2 = 4;

int z = 0;  // Wheel count / sensor trigger count

const int rs = 7, en = 8, d4 = 12, d5 = 11, d6 = 10, d7 = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);

  pinMode(IRsensor1, INPUT);
  pinMode(IRsensor2, INPUT);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Toll System");
  delay(2000);
  lcd.clear();
}

void loop() {
  int value1 = digitalRead(IRsensor1);
  int value2 = digitalRead(IRsensor2);

  Serial.println();
  Serial.print("Sensor Value1 = ");
  Serial.print(value1);
  Serial.println();
  Serial.print("Sensor Value2 = ");
  Serial.print(value2);

  if (value1 == 0) {
    z = z + 1;
    delay(300);
  }

  if (value2 == 0) {
    z = z + 1;
    delay(300);
  }

  Serial.println();
  Serial.print("Wheel Count = ");
  Serial.print(z);

  lcd.setCursor(0, 0);
  lcd.print("Toll Fee:       ");

  if (z == 2) {
    lcd.setCursor(0, 1);
    lcd.print("200 TAKA        ");
  } else if (z == 3) {
    lcd.setCursor(0, 1);
    lcd.print("250 TAKA        ");
  } else if (z == 4) {
    lcd.setCursor(0, 1);
    lcd.print("400 TAKA        ");
  } else if (z == 6) {
    lcd.setCursor(0, 1);
    lcd.print("800 TAKA        ");
  } else if (z == 8) {
    lcd.setCursor(0, 1);
    lcd.print("1000 TAKA       ");
  }

  delay(2000);
}
