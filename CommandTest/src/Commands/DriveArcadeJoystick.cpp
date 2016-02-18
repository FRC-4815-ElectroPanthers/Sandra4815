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
	if(oi->joy1->GetRawButton(1)){
		drivetrain->ResetEncoder();
	}

	double a = 0.0;

	if(oi->joy1->GetRawButton(8) && a != 1.0){
		a += 0.1;
	}

	if(oi->joy1->GetRawButton(9) && a != 0.0){
		a -= 0.1;
	}

	float xAdjus = a*pow(-oi->joy1->GetRawAxis(1),3) + (1-a)*(-oi->joy1->GetRawAxis(1));
	float yAdjus = a*pow(oi->joy1->GetRawAxis(0),3) + (1-a)*(oi->joy1->GetRawAxis(0));

	drivetrain->ArcadeDrive(xAdjus, yAdjus);

	if(t->HasPeriodPassed(2.0)){
		drivetrain->Report();
	}

	SmartDashboard::PutNumber("DB/Slider 0", a*5);

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
