/*
 * IMUGyro.cpp
 *
 * This is a class designed in order to use the Adafruit 9-DOF IMU Breakout board that contains
 * the L3GD20H Gyro and LSM303 Accelerometer/Compass for FRC applications with the WPI Libraries
 * and National Instruments roboRIO. Portions of the following code contains open source
 * code copied from the library for the L3GD20 GYROSCOPE provided by Adafruit Industries.
 *
 * The following was put together by Houssen Yang on FRC Team 4815 The ElectroPanthers.
 *
 * LEGAL STUFF
 * This is a library for the L3GD20 GYROSCOPE
 *
 * Designed specifically to work with the Adafruit L3GD20 Breakout
 * ----> https://www.adafruit.com/products/1032
 *
 * These sensors use I2C or SPI to communicate, 2 pins (I2C)
 * or 4 pins (SPI) are required to interface.
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * Written by Kevin "KTOWN" Townsend for Adafruit Industries.
 * BSD license, all text above must be included in any redistribution
 */

#include <IMU/IMUGyro.h>

IMUGyro::IMUGyro():I2C(I2C::kOnboard, 0x6B) {
	// TODO Auto-generated constructor stub


}

IMUGyro::~IMUGyro() {
	// TODO Auto-generated destructor stub
}

void IMUGyro::Calibrate(){

}

void IMUGyro::Reset(){

}

float IMUGyro::GetAngle() const{
	return 0.0;
}

double IMUGyro::GetRate() const{
	return 0.0;
}

double IMUGyro::PIDGet(){
	return GetAngle();
}


