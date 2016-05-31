#include <Commands/Chassis/DriveTurn.h>

DriveTurn::DriveTurn(double angle)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::drivetrain);
	driveTo = angle;
}

DriveTurn::DriveTurn(double angle, double timeout){
	Requires(CommandBase::drivetrain);
	timed = true;
	driveTo = angle;
	SetTimeout(timeout);
}

// Called just before this Command runs the first time
void DriveTurn::Initialize()
{
	drivetrain->SourcePID(Chassis::gyro_t);
	drivetrain->ResetGyro();
	drivetrain->SetSetpoint(driveTo);
	drivetrain->Enable();

}

// Called repeatedly when this Command is scheduled to run
void DriveTurn::Execute()
{
	drivetrain->ReportSmartDash();
	drivetrain->SetPIDSmartDash();
}

// Make this return true when this Command no longer needs to run execute()
bool DriveTurn::IsFinished()
{
	bool finished;

	if(timed){
		finished = (drivetrain->GetYaw()==driveTo) || IsTimedOut();
	}else{
		finished =(drivetrain->GetYaw()==driveTo);
	}

	return finished;
}

// Called once after isFinished returns true
void DriveTurn::End()
{
	drivetrain->ArcadeDrive(0,0);
	drivetrain->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveTurn::Interrupted()
{
	End();
}
