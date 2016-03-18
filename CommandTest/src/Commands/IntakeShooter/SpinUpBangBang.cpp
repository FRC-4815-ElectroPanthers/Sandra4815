#include "SpinUpBangBang.h"

SpinUpBangBang::SpinUpBangBang()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::shooter);
}

// Called just before this Command runs the first time
void SpinUpBangBang::Initialize()
{
	CommandBase::shooter->ReadyToShoot(false);
}

// Called repeatedly when this Command is scheduled to run
void SpinUpBangBang::Execute()
{
	if(CommandBase::shooter->RightShooterSpeed() != 18000){
		CommandBase::shooter->RightSpinUP(false);
	}else{
		CommandBase::shooter->RightSpinStop();
	}

	if(CommandBase::shooter->LeftShooterSpeed() != 18000){
		CommandBase::shooter->LeftSpinUP(true);
	}else{
		CommandBase::shooter->LeftSpinStop();
	}

	if(CommandBase::shooter->RightShooterSpeed() == CommandBase::shooter->LeftShooterSpeed()){
		CommandBase::shooter->ReadyToShoot(true);
	}

}

// Make this return true when this Command no longer needs to run execute()
bool SpinUpBangBang::IsFinished()
{
	return false;//!(CommandBase::shooter->HasBall());
}

// Called once after isFinished returns true
void SpinUpBangBang::End()
{
	CommandBase::shooter->RightSpinStop();
	CommandBase::shooter->LeftSpinStop();
	CommandBase::shooter->ReadyToShoot(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpinUpBangBang::Interrupted()
{
	End();
}
