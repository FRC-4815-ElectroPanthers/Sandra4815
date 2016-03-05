#ifndef DriveArmJoystick_H
#define DriveArmJoystick_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveArmJoystick: public CommandBase
{
public:
	DriveArmJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
