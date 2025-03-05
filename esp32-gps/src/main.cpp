#include <Arduino.h>
#include <TinyGPSPlus.h>

TinyGPSPlus gps;

#define GPS_SERIAL_RX 21
#define GPS_SERIAL_TX 20 

void setup() {
  Serial.begin(115200);
  
  Serial1.begin(9600, SERIAL_8N1, GPS_SERIAL_RX, GPS_SERIAL_TX);
  
  Serial.println("GPS Start, by akramslab");
}

void loop() {
  while (Serial1.available() > 0) {
    char c = Serial1.read();
    //Serial.write(c); // Print raw GPS data
    gps.encode(c);
  }

  if (gps.location.isUpdated()) {
    Serial.print("Location: ");
    Serial.print(gps.location.lat(), 6);
    Serial.print(", ");
    Serial.println(gps.location.lng(), 6);
    
    Serial.print("Altitude: ");
    Serial.println(gps.altitude.meters());
    
    Serial.print("Satellites: ");
    Serial.println(gps.satellites.value());
    
    Serial.print("Time: ");
    Serial.print(gps.time.hour());
    Serial.print(":");
    Serial.print(gps.time.minute());
    Serial.print(":");
    Serial.println(gps.time.second());
  }
}
