#ifndef DriveArmJoystick_H
#define DriveArmJoystick_H

#include "CommandBase.h"
#include "WPILib.h"

class DriveArmJoystick: public CommandBase
{
	enum m_mode{t_intake, t_spit}mode;
public:
	DriveArmJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
