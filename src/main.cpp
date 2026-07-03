#include <HardwareSerial.h>
const int TDS_PIN = 34;  // Change to your ADC pin

void setup() {
  Serial.begin(115200);
}

void loop() {
  int raw = analogRead(TDS_PIN);

  Serial.print("Raw ADC: ");
  Serial.println(raw);

  delay(500);
}