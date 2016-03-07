#include "SmartDashReport.h"

SmartDashReport::SmartDashReport()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void SmartDashReport::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void SmartDashReport::Execute()
{
	SmartDashboard::PutNumber("Speed", drivetrain->GetSpeed());
	SmartDashboard::PutNumber("Relative Linear Travel", drivetrain->GetDistanceTravel());
	SmartDashboard::PutNumber("Reative Heading Angle", drivetrain->GetYaw());

	SmartDashboard::PutNumber("Arm Angle", shooter->ArmAngle());
	SmartDashboard::PutNumber("Left Shooter Wheel Speed", shooter->LeftShooterSpeed());
	SmartDashboard::PutNumber("Right Shooter Wheel Speed", shooter->RightShooterSpeed());

	SmartDashboard::PutBoolean("Good To Shoot", shooter->ReadyToShoot());
	SmartDashboard::PutBoolean("Has Ball", shooter->HasBall());

}

// Make this return true when this Command no longer needs to run execute()
bool SmartDashReport::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void SmartDashReport::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SmartDashReport::Interrupted()
{

}
