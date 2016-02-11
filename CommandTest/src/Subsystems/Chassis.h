#ifndef Chassis_H
#define Chassis_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

class Chassis: public PIDSubsystem
{
private:
	Talon *frontRight, *backRight, *frontLeft, *backLeft;
	Encoder *LeftFront, *RightBack;
	//PIDController control;
	enum PIDSensor {encoder, imu} sensor;

public:
	Chassis();
	void ArcadeDrive(float, float);
	void ArcadeDriveThrust(float, float, float);
	double GetSpeed();
	void SourcePID(PIDSensor);
	bool PIDdone();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
};

#endif
