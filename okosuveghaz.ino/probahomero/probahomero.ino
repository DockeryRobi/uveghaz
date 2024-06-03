#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN,DHTTYPE);

void setup()
{
    Serial.begin(9600);
    dht.begin();
}

void loop()
{
  float h = dht.readHumidity();
  float tc = dht.readTemperature();
  float tf = dht.readTemperature(true); //nem szükséges
  if (isnan(h) || isnan(tc) || isnan(tf)){
    Serial.println("Nem tudok mérni,");
    delay(1000);
  } else {
    Serial.print("Páratartalom: ");
    Serial.print(h);
    Serial.print("%");
    Serial.print(" || ");
    Serial.print("Hőmérséklet: ");
    Serial.print(tc);
    Serial.print("C / ");
    Serial.print(tf);
    Serial.println("F");
    delay(1000);
  }
}