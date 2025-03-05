#include <MPU6050.h>
#include <Wire.h>

MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  Wire.begin(6, 7); // SDA = GPIO6, SCL = GPIO7 for XIAO C3

  Serial.println("Initialize MPU6050");

  mpu.initialize();

  if (mpu.testConnection()) {
    Serial.println("MPU6050 connection successful");
  } else {
    Serial.println("MPU6050 connection failed");
  }

  mpu.setFullScaleGyroRange(MPU6050_GYRO_FS_250); // ±250 °/s
  mpu.setFullScaleAccelRange(MPU6050_ACCEL_FS_2); // ±2g

  Serial.println("MPU6050 initialized!");
}

void loop() {
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  // Read raw accelerometer and gyroscope values
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Convert to readable format
  float accel_x = ax / 16384.0; // For ±2g range
  float accel_y = ay / 16384.0;
  float accel_z = az / 16384.0;

  float gyro_x = gx / 131.0; // For ±250 °/s range
  float gyro_y = gy / 131.0;
  float gyro_z = gz / 131.0;

  // Calculate pitch and roll (basic)
  float pitch = atan2(accel_x, sqrt(accel_y * accel_y + accel_z * accel_z)) *
                180.0 / M_PI;
  float roll = atan2(accel_y, accel_z) * 180.0 / M_PI;

  // Print values
  Serial.print("Accel (g): X=");
  Serial.print(accel_x);
  Serial.print(" Y=");
  Serial.print(accel_y);
  Serial.print(" Z=");
  Serial.print(accel_z);

  Serial.print(" | Gyro (deg/s): X=");
  Serial.print(gyro_x);
  Serial.print(" Y=");
  Serial.print(gyro_y);
  Serial.print(" Z=");
  Serial.print(gyro_z);

  Serial.print(" | Pitch=");
  Serial.print(pitch);
  Serial.print(" Roll=");
  Serial.println(roll);

  delay(100);
}
