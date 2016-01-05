#ifndef arcadeDrive_H
#define arcadeDrive_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Subsystems/driveTrain.h"

class DriveArcade: public CommandBase
{
	float xDirc, yDirc;
public:
	DriveArcade(float, float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
