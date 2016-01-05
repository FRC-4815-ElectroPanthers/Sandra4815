#ifndef DriveStraight_H
#define DriveStraight_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveStraight: public CommandBase
{
private:
	double setpoint;
public:
	DriveStraight(double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
