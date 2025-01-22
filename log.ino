int ledpin = 9;
int analogpin = A0;
int val = 0;

void setup() {
  
  pinMode(ledpin, OUTPUT);
}

void loop() {
  
  val = analogRead(analogpin);
  
  analogWrite(ledpin, val / 4);
}