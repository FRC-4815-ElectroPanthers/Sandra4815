#ifndef DriveArmAngle_H
#define DriveArmAngle_H

#include "CommandBase.h"
#include "WPILib.h"

class DriveArmAngle: public CommandBase
{
	double m_angle;
public:
	DriveArmAngle(double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
