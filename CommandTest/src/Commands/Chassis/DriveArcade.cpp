#include <Commands/Chassis/DriveArcade.h>

DriveArcade::DriveArcade(float x, float y)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::drivetrain);
	xDirc = x;
	yDirc = y;
}

DriveArcade::DriveArcade(float x, float y, float timeout)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::drivetrain);
	xDirc = x;
	yDirc = y;

	SetTimeout(timeout);
}

// Called just before this Command runs the first time
void DriveArcade::Initialize()
{
	//There's nothing to initialize here, just a comment
	//Oh so you have to commit and push!
}

// Called repeatedly when this Command is scheduled to run
void DriveArcade::Execute()
{
	CommandBase::drivetrain->ArcadeDrive(xDirc, yDirc);
	CommandBase::drivetrain->ReportSmartDash();
	//drivetrain->SetPIDSmartDash();
}

// Make this return true when this Command no longer needs to run execute()
bool DriveArcade::IsFinished()
{
	return false || IsTimedOut();
}

// Called once after isFinished returns true
void DriveArcade::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveArcade::Interrupted()
{

}
