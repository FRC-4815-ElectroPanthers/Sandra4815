#include <Commands/DriveArcade.h>
#include "driveTrain.h"
#include "../RobotMap.h"

driveTrain::driveTrain() : Subsystem("Drive Train")
{
	frontRight = new Talon(FRONTRIGHT);
	backRight = new Talon(BACKRIGHT);
	frontLeft = new Talon(FRONTLEFT);
	backLeft = new Talon(BACKLEFT);
}

void driveTrain::arcadeDrive(float x, float y){
	float right = y-x;
	float left = y+x;

	frontRight->Set(right);
	backRight->Set(right);
	frontLeft->Set(left);
	backLeft->Set(left);
}

void driveTrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveArcade(1.0, 1.0));
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
