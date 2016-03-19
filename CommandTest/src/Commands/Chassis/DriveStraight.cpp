#include <Commands/Chassis/DriveStraight.h>

DriveStraight::DriveStraight()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivetrain);
	finished = false;
}

DriveStraight::DriveStraight(double distance, double timeout){
	SetTimeout(timeout);
	finished = false;

	Requires(drivetrain);
}

// Called just before this Command runs the first time
void DriveStraight::Initialize()
{
	drivetrain->SourcePID(Chassis::gyroAdjust_t);
	//drivetrain->ResetEncoder();
	drivetrain->SetSetpoint(0);
	drivetrain->Enable();
}

// Called repeatedly when this Command is scheduled to run
void DriveStraight::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraight::IsFinished()
{
	return finished || IsTimedOut();
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
	End();
}
