const int SW_pin = 8;  
const int X_pin = A0;  
const int Y_pin = A1;  
const int LED_pin = 9; 

void setup() {
  pinMode(SW_pin, INPUT_PULLUP);  
  pinMode(LED_pin, OUTPUT);       
  Serial.begin(9600);            
}

void loop() {
  int xValue = analogRead(X_pin);  
  int brightness = map(xValue, 0, 1023, 0, 255); 
  analogWrite(LED_pin, brightness);  
  
  
  Serial.print("Switch: ");
  Serial.print(digitalRead(SW_pin));
  Serial.print(" | X-axis: ");
  Serial.print(xValue);
  Serial.print(" | Brightness: ");
  Serial.print(brightness);
  Serial.print(" | Y-axis: ");
  Serial.println(analogRead(Y_pin));
  
  delay(200);
}
