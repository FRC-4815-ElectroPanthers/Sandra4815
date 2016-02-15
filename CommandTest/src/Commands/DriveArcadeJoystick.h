#ifndef DriveArcadeJoystick_H
#define DriveArcadeJoystick_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveArcadeJoystick: public CommandBase
{
	Timer *t;
public:
	DriveArcadeJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
