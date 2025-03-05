#include <Arduino.h>
#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>

TinyGPSPlus gps;
// RX, TX (Connect GPS TX to pin 4, GPS RX to pin 3)
SoftwareSerial gpsSerial(4, 3);

// For tracking when to print
unsigned long lastPrint = 0;
const unsigned long PRINT_INTERVAL = 1000;

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
  Serial.println("GPS Start");
}

void loop() {
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
  }

  if (millis() - lastPrint >= PRINT_INTERVAL) {
    lastPrint = millis();

    if (gps.location.isValid()) {
      Serial.print("Location: ");
      Serial.print(gps.location.lat(), 6);
      Serial.print(", ");
      Serial.println(gps.location.lng(), 6);

      Serial.print("Satellites: ");
      Serial.println(gps.satellites.value());

      Serial.print("Altitude: ");
      Serial.print(gps.altitude.meters());
      Serial.println("m");

      Serial.print("Time: ");
      if (gps.time.hour() < 10)
        Serial.print("0");
      Serial.print(gps.time.hour());
      Serial.print(":");
      if (gps.time.minute() < 10)
        Serial.print("0");
      Serial.print(gps.time.minute());
      Serial.print(":");
      if (gps.time.second() < 10)
        Serial.print("0");
      Serial.println(gps.time.second());

      Serial.println("--------------------");
    } else {
      Serial.println("Waiting for valid GPS data...");
    }
  }
}
