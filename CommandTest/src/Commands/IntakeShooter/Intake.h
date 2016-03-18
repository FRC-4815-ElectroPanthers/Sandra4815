#ifndef Intake_H
#define Intake_H

#include "CommandBase.h"
#include "WPILib.h"

class Intake: public CommandBase
{
	bool finished;
public:
	Intake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
