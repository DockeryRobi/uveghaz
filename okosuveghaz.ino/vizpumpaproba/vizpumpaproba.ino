const int pump = 9;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pumppin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pump, HIGH);
  delay(500);
  digitalWrite(pump, LOW);
  delay(500);
}
