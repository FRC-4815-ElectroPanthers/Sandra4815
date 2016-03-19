#ifndef DriveStraight_H
#define DriveStraight_H

#include "CommandBase.h"
#include "WPILib.h"

class DriveStraight: public CommandBase
{
private:
	bool finished,
	     timed = false;
public:
	DriveStraight();
	DriveStraight(double, double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
