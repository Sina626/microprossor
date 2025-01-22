
void setup() {
Serial.begin(9600);
}
void loop() {
int reading = analogRead(A0);
float voltage = reading * (500 / 1024.0);
float tempe = voltage ;
Serial.print(tempe);
Serial.println(" C ");
delay(1000); 
}