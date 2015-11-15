#ifndef driveTrain_H
#define driveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class driveTrain: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon *frontRight, *backRight, *frontLeft, *backLeft;
public:
	driveTrain();
	void arcadeDrive(float, float);
	void InitDefaultCommand();
};

#endif
