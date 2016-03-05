#ifndef DriveArmPosition_H
#define DriveArmPosition_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveArmPosition: public CommandBase
{
public:
	DriveArmPosition();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
