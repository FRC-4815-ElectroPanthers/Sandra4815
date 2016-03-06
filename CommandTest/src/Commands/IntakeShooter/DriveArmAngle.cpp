#include "DriveArmAngle.h"

DriveArmAngle::DriveArmAngle(double angle)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::shooter);
	m_angle = angle;
}

// Called just before this Command runs the first time
void DriveArmAngle::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveArmAngle::Execute()
{
	CommandBase::shooter->MoveArmTo(m_angle);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveArmAngle::IsFinished()
{
	if(CommandBase::shooter->ArmAngle() == m_angle){
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void DriveArmAngle::End()
{
	CommandBase::shooter->MoveThrottle(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveArmAngle::Interrupted()
{
	End();
}
