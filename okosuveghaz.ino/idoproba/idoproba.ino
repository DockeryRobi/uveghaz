unsigned long utIdo = 0;
unsigned long idozito = 60000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("adatblabla");

  if((millis() - utIdo) > idozito){
    Serial.println("Percenkénti.");
    utIdo = millis();
  }

  delay(10000);
}
