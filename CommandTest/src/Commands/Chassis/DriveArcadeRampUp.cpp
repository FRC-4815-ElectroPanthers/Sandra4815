#include "DriveArcadeRampUp.h"

DriveArcadeRampUp::DriveArcadeRampUp()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(chassis);

	CurrentXVal = 0;
	PrevXVal = 0;
	DeltaX = 0;
	Xout = 0;

	CurrentYVal = 0;
	PrevYVal = 0;
	DeltaY = 0;
	Yout = 0;
}

// Called just before this Command runs the first time
void DriveArcadeRampUp::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveArcadeRampUp::Execute()
{
	CurrentXVal = oi->drive->GetRawAxis(0);
	CurrentYVal = oi->drive->GetRawAxis(1);

	DeltaX = CurrentXVal - PrevXVal;
	DeltaY = CurrentYVal - PrevYVal;

	if(DeltaX >= 0){
		Xout += DeltaX/RAMP;
	}else{
		Xout -= DeltaX/RAMP;
	}

	if(DeltaY >= 0){
		Yout += DeltaY/RAMP;
	}else{
		Yout -= DeltaY/RAMP;
	}

	drivetrain->ArcadeDrive(Xout, Yout);

	PrevXVal = CurrentXVal;
	PrevYVal = CurrentYVal;
}

// Make this return true when this Command no longer needs to run execute()
bool DriveArcadeRampUp::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveArcadeRampUp::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveArcadeRampUp::Interrupted()
{

}
