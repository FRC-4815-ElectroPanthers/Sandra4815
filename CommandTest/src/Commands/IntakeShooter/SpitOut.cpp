#include "SpitOut.h"

SpitOut::SpitOut()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void SpitOut::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void SpitOut::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SpitOut::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void SpitOut::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpitOut::Interrupted()
{

}
