// Talajnedvesség érzékelő analóg bemeneti pinje
#define SENSOR_PIN A0

// Analóg bemeneti értékekhez tartozó száraz és nedves kalibrációs értékek
#define DRY_VALUE 1024   // Száraz talajhoz tartozó analóg érték
#define WET_VALUE 562      // Nedves talajhoz tartozó analóg érték

void setup() {
  Serial.begin(9600); // Soros kommunikáció indítása 9600 baud sebességgel
}

void loop() {
  // Talajnedvesség olvasása
  int sensorValue = analogRead(SENSOR_PIN);

  // Talajnedvesség értékének százalékká alakítása
  int moisturePercent = map(sensorValue, DRY_VALUE, WET_VALUE, 0, 100);

  // Az értékek megjelenítése a Serial monitoron
  Serial.print("Talajnedvesség: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  delay(1000); // 1 másodperc várakozás a következő mérés előtt
}
