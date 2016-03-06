#include "DriveArmJoystick.h"

DriveArmJoystick::DriveArmJoystick()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::shooter);
}

// Called just before this Command runs the first time
void DriveArmJoystick::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveArmJoystick::Execute()
{
	CommandBase::shooter->MoveArmToJoystick(CommandBase::oi->operate->GetRawAxis(1));
}

// Make this return true when this Command no longer needs to run execute()
bool DriveArmJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveArmJoystick::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveArmJoystick::Interrupted()
{

}
