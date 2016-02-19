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
public:
	IntakeShooter();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
};

#endif
