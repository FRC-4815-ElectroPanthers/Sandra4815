#include "SpitOut.h"

SpitOut::SpitOut()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::shooter);
	finished = false;
}

// Called just before this Command runs the first time
void SpitOut::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void SpitOut::Execute()
{
	if(CommandBase::shooter->RightShooterSpeed() != 4500){
			CommandBase::shooter->RightIntakeSpit(false);
	}else{
		CommandBase::shooter->RightSpinStop();
	}

	if(CommandBase::shooter->LeftShooterSpeed() != 4500){
		CommandBase::shooter->LeftIntakeSpit(true);
	}else{
		CommandBase::shooter->LeftSpinStop();
	}

	if(oi->operate->GetRawAxis(6)){
		finished = true;
	}

}

// Make this return true when this Command no longer needs to run execute()
bool SpitOut::IsFinished()
{
	return finished;
}

// Called once after isFinished returns true
void SpitOut::End()
{
	CommandBase::shooter->RightSpinStop();
	CommandBase::shooter->LeftSpinStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpitOut::Interrupted()
{

}
