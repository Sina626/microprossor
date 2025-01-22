#include <Wire.h>

String command = ""; // فرمان دریافتی از مستر
bool ledState = false; // وضعیت LED

void setup() {
  Wire.begin(8); // آدرس I2C برای اسلیو
  Wire.onReceive(receiveEvent); // تنظیم تابع برای دریافت داده
  Wire.onRequest(requestEvent); // تنظیم تابع برای ارسال داده
  pinMode(13, OUTPUT); // پین متصل به LED
  Serial.begin(9600);
}

void loop() {
  // دریافت فرمان از سریال مانیتور
  if (Serial.available() > 0) {
    String localCommand = Serial.readStringUntil('\n'); // دریافت فرمان

    // ارسال فرمان به مستر
    Wire.beginTransmission(1); // آدرس مستر (در اسلیو به عنوان گیرنده)
    if (localCommand == "on") {
      Wire.write("on");
      ledState = true;
    } else if (localCommand == "off") {
      Wire.write("off");
      ledState = false;
    }
    Wire.endTransmission();
  }

  // کنترل LED اسلیو بر اساس فرمان دریافتی از مستر
  if (command == "on") {
    digitalWrite(13, HIGH);
    Serial.println("LED turned ON by Master");
  } else if (command == "off") {
    digitalWrite(13, LOW);
    Serial.println("LED turned OFF by Master");
  }

  delay(100);
}

// تابع برای دریافت داده از مستر
void receiveEvent() {
  command = "";
  while (Wire.available()) {
    char c = Wire.read();
    command += c;
  }
}

// تابع برای ارسال داده به مستر
void requestEvent() {
  if (ledState) {
    Wire.write("on");
  } else {
    Wire.write("off");
  }
}
