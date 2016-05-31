#ifndef Chassis_H
#define Chassis_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"

class Chassis: public PIDSubsystem
{
private:
	Talon *frontRight, *backRight, *frontLeft, *backLeft;
	//RobotDrive *drive; //Added RobotDrive class to expirement for better driving?
	Encoder *right;//, *left;
	ADXRS450_Gyro *gyro;
	double const DISTANCE_PER_PULSE = (PI)/6144; //6144 came from conversion factor

public:
	enum PIDSensor {encoder_t, gyro_t, gyroAdjust_t} sensor;

	Chassis();
	void ArcadeDrive(float, float);
	void ArcadeDriveThrust(float, float, float);
	double GetSpeed();
	double GetDistanceTravel();
	void ResetEncoder();
	void CalibrateGyro();
	void ResetGyro();
	double GetYaw();
	void SourcePID(PIDSensor);
	void Report();
	void ReportSmartDash();
	void SetPIDSmartDash(double, double, double);
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
};

#endif
