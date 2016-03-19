#include "IntakeShooter.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include "../Commands/IntakeShooter/DriveArmJoystick.h"

IntakeShooter::IntakeShooter() :
		PIDSubsystem("IntakeShooter", 1.0, 0.0, 0.0)
{
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.

	rightWheel = new VictorSP(RIGHTSHOOTER);
	leftWheel = new VictorSP(LEFTSHOOTER);
	arm = new CANTalon(ARM);//TODO: Go into RIO Webdash and change Talon ID
	push = new Servo(SERVO);

	RSEnc = new Encoder(RS_ENC_A, RS_ENC_B, false, Encoder::EncodingType::k4X);
	LSEnc = new Encoder(LS_ENC_A, LS_ENC_B, false, Encoder::EncodingType::k4X);

	rangefinder = new AnalogInput(RANGEFINDER);

	shot = false;
	shoot = false;

	RSEnc->SetDistancePerPulse(DISTANCE_PER_PULSE);
	LSEnc->SetDistancePerPulse(DISTANCE_PER_PULSE);

	arm->SetPosition(arm->GetPulseWidthPosition());

	arm->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	arm->SetSensorDirection(false);

	arm->SetAllowableClosedLoopErr(0);
	arm->SetP(0.25);
	arm->SetI(0.0);
	arm->SetD(0.0);
}

void IntakeShooter::Shoot(){
	push->SetAngle(150);
}

void IntakeShooter::Retract(){
	push->SetAngle(90);
}

void IntakeShooter::RightSpinUP(bool reverse){
	if(reverse){
		rightWheel->Set(-1.0);
	}else{
		rightWheel->Set(1.0);
	}
}

void IntakeShooter::LeftSpinUP(bool reverse){
	if(reverse){
		leftWheel->Set(-1.0);
	}else{
		leftWheel->Set(1.0);
	}
}

void IntakeShooter::RightSpinStop(){
	rightWheel->Set(0.0);
}

void IntakeShooter::LeftSpinStop(){
	leftWheel->Set(0.0);
}

void IntakeShooter::ManualLeftSpin(float input){
	leftWheel->Set(input);
}

void IntakeShooter::ManualRightSpin(float input){
	rightWheel->Set(input);
}

void IntakeShooter::JustShot(bool status){
	shot = status;
}

void IntakeShooter::ReadyToShoot(bool status){
	shoot = status;
}


void IntakeShooter::LeftIntakeSpit(bool reverse){
	if(reverse){
		leftWheel->Set(-0.25);
	}else{
		leftWheel->Set(0.25);
	}
}


void IntakeShooter::RightIntakeSpit(bool reverse){
	if(reverse){
		leftWheel->Set(-0.25);
	}else{
		leftWheel->Set(0.25);
	}
}


void IntakeShooter::MoveArmTo(Position k){
	if(arm->GetControlMode() != CANSpeedController::kPosition){
		arm->SetControlMode(CANSpeedController::kPosition);
	}

	switch(k){
	case kStow:
		arm->Set(STOW_ANGLE);
		break;
	case kBackShot:
		arm->Set(FRONT_SHOT_ANGLE);
		break;
	case kFrontShot:
		arm->Set(BACK_SHOT_ANGLE);
		break;
	case kInOutTake:
		arm ->Set(INOUTTAKE_ANGLE);
		break;
	}
}

void IntakeShooter::MoveArmTo(double angle){
	if(arm->GetControlMode() != CANSpeedController::kPosition){
			arm->SetControlMode(CANSpeedController::kPosition);
		}
	arm->Set(angle);
}

void IntakeShooter::MoveArmToJoystick(double input){
	if(arm->GetControlMode() != CANSpeedController::kPosition){
		arm->SetControlMode(CANSpeedController::kPosition);
	}
	arm->Set(input*360); //map joystick to degrees of rotation
}

void IntakeShooter::MoveThrottle(double throttle){
	if(arm->GetControlMode() != CANSpeedController::kPercentVbus){
		arm->SetVoltageRampRate(RAMP_UP_RATE);
		arm->SetControlMode(CANSpeedController::kPercentVbus);
	}
	arm->Set(throttle);
}

double IntakeShooter::RightShooterSpeed(){
	return RSEnc->GetRate();
}

double IntakeShooter::LeftShooterSpeed(){
	return LSEnc->GetRate();
}

double IntakeShooter::ArmAngle(){
	return arm->GetPosition()*360;
}

double IntakeShooter::RangeFinderDistance(){
	return (rangefinder->GetValue() >> 2)*5.0/10/2.54;
	//return rangefinder distance in Inches
}

double IntakeShooter::ReturnPIDInput()
{
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	return (RightShooterSpeed() + LeftShooterSpeed())/2;
}

bool IntakeShooter::DidShoot(){
	if(push->GetAngle() == 90){
		shot = true;
	}
	return shot;
}

bool IntakeShooter::ReadyToShoot(){
	return shoot;
}

bool IntakeShooter::HasBall(){
	if (RangeFinderDistance() < 16){
		return true;
	}
	return false;
}

void IntakeShooter::UsePIDOutput(double output)
{
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	rightWheel->Set(output);
	leftWheel->Set(output);
}

void IntakeShooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveArmJoystick());
}
