#include "Shoot.h"

Shoot::Shoot()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::shooter);
}

// Called just before this Command runs the first time
void Shoot::Initialize()
{
	CommandBase::shooter->JustShot(false);
}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute()
{
	CommandBase::shooter->Shoot();
}

// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished()
{
	return CommandBase::shooter->DidShoot();
}

// Called once after isFinished returns true
void Shoot::End()
{
	CommandBase::shooter->Retract();
	CommandBase::shooter->JustShot(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted()
{

}
