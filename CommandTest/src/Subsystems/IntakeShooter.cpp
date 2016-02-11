#include "IntakeShooter.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

IntakeShooter::IntakeShooter() :
		PIDSubsystem("IntakeShooter", 1.0, 0.0, 0.0)
{
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
}

double IntakeShooter::ReturnPIDInput()
{
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
}

void IntakeShooter::UsePIDOutput(double output)
{
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
}

void IntakeShooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
}
