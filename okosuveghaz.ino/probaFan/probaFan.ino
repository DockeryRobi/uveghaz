int fan = D7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(fan, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(fan, HIGH);
  delay(5000);
  digitalWrite(fan, LOW);
  delay(5000);
}
