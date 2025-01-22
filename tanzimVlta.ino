int analogPin = A0; 
float voltage = 0.0; 

void setup() {
  Serial.begin(9600); 
}

void loop() {
  int sensorValue = analogRead(analogPin);

  voltage = sensorValue * (5.0 / 1023.0);

  
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  delay(100); 
}