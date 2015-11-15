#ifndef arcadeDrive_H
#define arcadeDrive_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Subsystems/driveTrain.h"

class driveArcade: public CommandBase
{
	float xDirc, yDirc;
public:
	driveArcade(float, float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
