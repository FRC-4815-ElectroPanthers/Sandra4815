#ifndef SmartDashReport_H
#define SmartDashReport_H

#include "../CommandBase.h"
#include "WPILib.h"

class SmartDashReport: public CommandBase
{
public:
	SmartDashReport();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
