#ifndef IntakeShooter_H
#define IntakeShooter_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

class IntakeShooter: public PIDSubsystem
{
public:
	IntakeShooter();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
};

#endif
