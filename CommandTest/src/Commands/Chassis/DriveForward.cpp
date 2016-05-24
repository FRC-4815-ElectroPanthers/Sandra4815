#include <Commands/Chassis/DriveForward.h>

DriveForward::DriveForward(double distance)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	setpoint = distance;

	Requires(drivetrain);
}

DriveForward::DriveForward(double distance, double timeout){
	setpoint = distance;
	timed = true;
	SetTimeout(timeout);

	Requires(drivetrain);
}

// Called just before this Command runs the first time
void DriveForward::Initialize()
{
	drivetrain->SourcePID(Chassis::encoder_t);
	drivetrain->ResetEncoder();
	drivetrain->SetSetpoint(setpoint);
	drivetrain->Enable();
}

// Called repeatedly when this Command is scheduled to run
void DriveForward::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DriveForward::IsFinished()
{
	//return false;
	
	bool finished;

	if(timed){
		finished = (drivetrain->GetDistanceTravel() == setpoint) || IsTimedOut();
	}else{
		finished = (drivetrain->GetDistanceTravel() == setpoint);
	}

	return finished;
}

// Called once after isFinished returns true
void DriveForward::End()
{
	drivetrain->ArcadeDrive(0,0);
	drivetrain->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForward::Interrupted()
{
	End();
}
