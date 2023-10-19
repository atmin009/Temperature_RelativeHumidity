#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

DHT dht(D4, DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);
float temp, hum;

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("T :    ");  
  lcd.setCursor(0, 1);
  lcd.print("RH:      %"); 
}

void loop() {
  hum = dht.readHumidity();
  temp = dht.readTemperature();

  Serial.print("T: ");
  Serial.print(temp);
  Serial.print(" C  RH: ");
  Serial.print(hum);
  Serial.println(" %");

  lcd.setCursor(4, 0);  
  lcd.print(temp);
  lcd.print((char)223); 
  lcd.setCursor(4, 1); 
  lcd.print(hum);

  delay(500);
}
