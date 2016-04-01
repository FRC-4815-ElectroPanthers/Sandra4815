#include "DriveArmJoystick.h"

DriveArmJoystick::DriveArmJoystick()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::shooter);
	mode = t_intake;
}

// Called just before this Command runs the first time
void DriveArmJoystick::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveArmJoystick::Execute()
{
	//SmartDashboard::PutNumber("Arm Angle", shooter->ArmAngle());
	//SmartDashboard::PutNumber("Left Shooter Wheel Speed", shooter->LeftShooterSpeed());
	//SmartDashboard::PutNumber("Right Shooter Wheel Speed", shooter->RightShooterSpeed());

	//SmartDashboard::PutBoolean("Good To Shoot", shooter->ReadyToShoot());

	if(oi->operate->GetRawButton(6) && mode == t_intake){
		mode = t_spit;
	}else{
		mode = t_intake;
	}

	CommandBase::shooter->MoveArmThrottle(CommandBase::oi->operate->GetRawAxis(1));

	/*
	if(mode == t_spit){
		CommandBase::shooter->ManualLeftSpin(-oi->operate->GetRawAxis(2)*0.25);
	}else{
		CommandBase::shooter->ManualLeftSpin(oi->operate->GetRawAxis(2)*0.25);
	}
	*/

	if(oi->operate->GetRawButton(7)){
		CommandBase::shooter->RightIntakeSpit(false);
	}else if(oi->operate->GetRawButton(8)){
		CommandBase::shooter->RightIntakeSpit(true);
	}else{
		CommandBase::shooter->ManualRightSpin(0);
	}
}
// Make this return true when this Command no longer needs to run execute()
bool DriveArmJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveArmJoystick::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveArmJoystick::Interrupted()
{

}
