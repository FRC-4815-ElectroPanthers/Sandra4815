#include "driveArcade.h"

driveArcade::driveArcade(float x, float y)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::drivetrain);
	xDirc = x;
	yDirc = y;
}

// Called just before this Command runs the first time
void driveArcade::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void driveArcade::Execute()
{
	CommandBase::drivetrain->arcadeDrive(xDirc, yDirc);
}

// Make this return true when this Command no longer needs to run execute()
bool driveArcade::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void driveArcade::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void driveArcade::Interrupted()
{

}
