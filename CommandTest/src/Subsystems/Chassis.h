#ifndef Chassis_H
#define Chassis_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

class Chassis: public PIDSubsystem
{
private:
	Talon *frontRight, *backRight, *frontLeft, *backLeft;
	Encoder *LeftFront, *RightBack;
	PIDController *control;
	enum PIDSensor {encoder, imu} *sensor;

public:
	Chassis();
	void ArcadeDrive(float, float);
	double GetSpeed();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
};

#endif
