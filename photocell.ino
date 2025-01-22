int sensor;
int ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  sensor = analogRead(A0);
  Serial.print("sensorValue=");
  Serial.println(sensor);
  delay(300);
  if (sensor > 800) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }
}