#include "DriveStraight.h"

DriveStraight::DriveStraight(float driveSpeed, double driveTime)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	speed = driveSpeed;
	time = driveTime;

	Requires(CommandBase::drivetrain);
}

// Called just before this Command runs the first time
void DriveStraight::Initialize()
{
	SetTimeout(time);
}

// Called repeatedly when this Command is scheduled to run
void DriveStraight::Execute()
{
	CommandBase::drivetrain->ArcadeDrive(speed, speed);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraight::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void DriveStraight::End()
{
	CommandBase::drivetrain->ArcadeDrive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraight::Interrupted()
{

}
