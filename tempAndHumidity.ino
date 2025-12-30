#include "DHT.h"

#include <IRremote.h>

#define Type DHT11
int sensePin = 6;
DHT HT(sensePin, Type);
float humidity;
float tempC;
float tempF;
int setTime = 1000;

#include <LiquidCrystal.h>

int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int IRpin = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  HT.begin();
  delay(setTime);
}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  Serial.println(humidity);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Humidity=");
  lcd.print(humidity);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("Temp=");
  lcd.print(tempC);
  lcd.print("C");
  delay(setTime);

}
