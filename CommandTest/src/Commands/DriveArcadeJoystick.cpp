#include "DriveArcadeJoystick.h"

DriveArcadeJoystick::DriveArcadeJoystick()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::drivetrain);
	t = new Timer();

}

// Called just before this Command runs the first time
void DriveArcadeJoystick::Initialize()
{
	t->Start();
}

// Called repeatedly when this Command is scheduled to run
void DriveArcadeJoystick::Execute()
{
	drivetrain->ArcadeDrive(-oi->joy1->GetRawAxis(1), oi->joy1->GetRawAxis(0));

	if(t->HasPeriodPassed(2.0)){
		drivetrain->Report();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveArcadeJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveArcadeJoystick::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveArcadeJoystick::Interrupted()
{

}
