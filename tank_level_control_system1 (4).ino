int LevelSensorVal = 0;

int echoPin = 0;

int triggerPin = 0;

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

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  echoPin = 3;
  triggerPin = 2;
  LevelSensorVal = 0.01723 * readUltrasonicDistance(2, 3);
  Serial.println("Level Control System");
  Serial.println(LevelSensorVal);
  if (LevelSensorVal <= 40) {
    Serial.println("Tank is FULL");
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    tone(5, 30, 1000); // play tone 3 (D#0 = 29 Hz)
  }
  if (LevelSensorVal >= 280) {
    Serial.println("Tank is EMPTY");
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    tone(5,29,1000);
  }
  delay(10); // Delay a little bit to improve simulation performance
}