#ifndef DriveArmPosition_H
#define DriveArmPosition_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveArmPosition: public CommandBase
{
	IntakeShooter::Position position;
public:
	DriveArmPosition(IntakeShooter::Position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
