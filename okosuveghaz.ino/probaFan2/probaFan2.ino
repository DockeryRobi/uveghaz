#define IN1 D1 // GPIO pin connected to IN1 on the L298N
#define IN2 D2 // GPIO pin connected to IN2 on the L298N

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  digitalWrite(IN1, LOW); // Ensure the fan is off initially
  digitalWrite(IN2, LOW); // Ensure the fan is off initially
}

void loop() {
  // Turn the fan on
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(5000); // Keep the fan on for 5 seconds

  // Turn the fan off
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(5000); // Keep the fan off for 5 seconds
}
