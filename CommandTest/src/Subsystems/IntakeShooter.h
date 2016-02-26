#ifndef IntakeShooter_H
#define IntakeShooter_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

class IntakeShooter: public PIDSubsystem
{
	VictorSP *rightWheel, *leftWheel;
	CanTalonSRX *arm;
	Servo *push;
	Encoder *LSEnc, *RSEnc;
	double const DISTANCE_PER_PULSE = 360/1024; //360 Degrees Per 1024 Pulses
public:
	IntakeShooter();
	void Shoot();
	void Retract();
	void RightSpinUP();
	void LeftSpinUP();
	void Intake();
	void SpitOut();
	void MoveArmTo();
	double RightShooterSpeed();
	double LeftShooterSpeed();
	double ArmAngle();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
};

#endif
