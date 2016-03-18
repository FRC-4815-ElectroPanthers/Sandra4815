#ifndef DriveForward_H
#define DriveForward_H

#include "CommandBase.h"
#include "WPILib.h"

class DriveForward: public CommandBase
{
private:
	double setpoint;
	bool timed = false;
public:
	DriveForward(double);
	DriveForward(double, double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
