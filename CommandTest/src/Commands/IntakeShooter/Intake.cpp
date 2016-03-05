#include "Intake.h"

Intake::Intake()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::shooter);
}

// Called just before this Command runs the first time
void Intake::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Intake::Execute()
{
	if(CommandBase::shooter->RightShooterSpeed() != 4500){
			CommandBase::shooter->RightSpinUP(true);
	}else{
		CommandBase::shooter->RightSpinStop();
	}

	if(CommandBase::shooter->LeftShooterSpeed() != 4500){
		CommandBase::shooter->LeftSpinUP(false);
	}else{
		CommandBase::shooter->LeftSpinStop();
	}

}

// Make this return true when this Command no longer needs to run execute()
bool Intake::IsFinished()
{
	return CommandBase::shooter->HasBall();
}

// Called once after isFinished returns true
void Intake::End()
{
	CommandBase::shooter->RightSpinStop();
	CommandBase::shooter->LeftSpinStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Intake::Interrupted()
{

}
