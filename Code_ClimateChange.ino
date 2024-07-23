#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#define DHTPIN 2
#define DHTTYPE DHT11 // DHT 11 (AM2302), AM2321
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);
int M = 9 ;
void setup()
{
Serial.begin(9600);
dht.begin();
lcd.init();
lcd.backlight();
lcd.setCursor(0, 0);
lcd.print("Temp.:");
lcd.setCursor(10, 0);
lcd.print("H:");
lcd.setCursor(0, 1);
lcd.print("Water Level:");
pinMode(M,OUTPUT) ;
}
void loop()
{
int temperature = dht.readTemperature();
int humidity = dht.readHumidity();
int value = analogRead(A0);
Serial.println("Water Level:");
Serial.println(value); .
if (isnan(temperature) || isnan(humidity)) // Check if any reads failed and exit early
{
Serial.println(F("Failed to read from DHT sensor!"));
return;
}
if (value == 0)
{ digitalWrite(M,LOW) ;
Serial.println("empty");
lcd.setCursor(12, 1);
lcd.print("Empty ");
}
else if (value > 1 && value < 300)
{ digitalWrite(M,LOW) ;
Serial.println("low");
lcd.setCursor(12, 1);
lcd.print("LOW ");
}
else if (value > 300 && value < 500)
{ digitalWrite(M,HIGH) ;
Serial.println("medium");
lcd.setCursor(12, 1);
lcd.print("MID");
}
else if (value > 500)
{ digitalWrite(M,HIGH) ;
Serial.println("full");
lcd.setCursor(12, 1);
lcd.print("HIGH ");
}
lcd.setCursor(12, 0);
lcd.print(humidity);
Serial.println("H:");
Serial.println(humidity);
lcd.setCursor(14, 0);
lcd.print("%");
lcd.setCursor(6, 0);
lcd.print(temperature);
Serial.println("Temp.:");
Serial.println(temperature);
lcd.setCursor(8, 0);
lcd.print(F("C"));
// Wait a few seconds between measurements.
delay(500);
} 
