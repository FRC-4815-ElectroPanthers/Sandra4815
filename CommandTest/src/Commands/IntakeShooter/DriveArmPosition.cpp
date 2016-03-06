#include "DriveArmPosition.h"
#include "../../RobotMap.h"

DriveArmPosition::DriveArmPosition(IntakeShooter::Position pos)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::shooter);
	position = pos;
}

// Called just before this Command runs the first time
void DriveArmPosition::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveArmPosition::Execute()
{
	CommandBase::shooter->MoveArmTo(position);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveArmPosition::IsFinished()
{
	switch(position){
	case IntakeShooter::kStow:
		if(CommandBase::shooter->ArmAngle() == STOW_ANGLE){
			return true;
		}
		break;
	case IntakeShooter::kFrontShot:
		if(CommandBase::shooter->ArmAngle() == FRONT_SHOT_ANGLE){
			return true;
		}
		break;
	case IntakeShooter::kBackShot:
		if(CommandBase::shooter->ArmAngle() == BACK_SHOT_ANGLE){
			return true;
		}
		break;
	case IntakeShooter::kInOutTake:
		if(CommandBase::shooter->ArmAngle() == INOUTTAKE_ANGLE){
			return true;
		}
		break;
	default:
		return false;
	}
	return false;
}

// Called once after isFinished returns true
void DriveArmPosition::End()
{
	CommandBase::shooter->MoveThrottle(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveArmPosition::Interrupted()
{
	End();
}
