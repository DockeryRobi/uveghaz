int motor = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(motor, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(motor, HIGH);
  delay(5000);
  digitalWrite(motor, LOW);
  delay(5000);
}
