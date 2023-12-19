// C++ code
//
int level_sensorval = 0;

int echopin = 0;

int triggerpin = 0;

int levelsensoval = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(5, OUTPUT);
}

void loop()
{
  echopin = 3;
  triggerpin = 2;
  levelsensoval = 0.01723 * readUltrasonicDistance(2, 3);
  Serial.println("level control system");
  Serial.println(levelsensoval);
  if (levelsensoval < 30) {
    Serial.println("tank is full");
    tone(5, 523, 2000); // play tone 60 (C5 = 523 Hz)
  }
  if (levelsensoval >= 300) {
    Serial.println("tank is empty");
    tone(5, 294, 1000); // play tone 50 (D4 = 294 Hz)
  }
  delay(10); // Delay a little bit to improve simulation performance
}