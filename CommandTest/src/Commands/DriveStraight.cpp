#include "DriveStraight.h"

DriveStraight::DriveStraight(double distance)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	setpoint = distance;

	Requires(CommandBase::drivetrain);
}

// Called just before this Command runs the first time
void DriveStraight::Initialize()
{
	drivetrain->SetSetpoint(setpoint);
	drivetrain->Enable();
}

// Called repeatedly when this Command is scheduled to run
void DriveStraight::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraight::IsFinished()
{
	return drivetrain->PIDdone();
}

// Called once after isFinished returns true
void DriveStraight::End()
{
	drivetrain->ArcadeDrive(0,0);
	drivetrain->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraight::Interrupted()
{

}
