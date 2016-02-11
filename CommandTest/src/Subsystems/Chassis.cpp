#include "Chassis.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include "Commands/DriveArcadeJoystick.h"

Chassis::Chassis() :
		PIDSubsystem("Chassis", 1.0, 0.0, 0.0)
{
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.

	frontRight = new Talon(FRONTRIGHT);
	backRight = new Talon(BACKRIGHT);
	frontLeft = new Talon(FRONTLEFT);
	backLeft = new Talon(BACKLEFT);

	LeftFront = new Encoder(FL_ENC_A, FL_ENC_B, false, Encoder::EncodingType::k4X);
	RightBack = new Encoder(BR_ENC_A, BR_ENC_B, false, Encoder::EncodingType::k4X);

	LeftFront->SetDistancePerPulse((1/4096)*(PI*WHEEL_DIA)/12); //Feet per Pulse
	RightBack->SetDistancePerPulse((1/4096)*(PI*WHEEL_DIA)/12);

	LeftFront->SetMinRate(0.001);
	RightBack->SetMinRate(0.001);

	//control = GetPIDController();
	sensor = encoder;

}

void Chassis::ArcadeDrive(float x, float y){ //may want to change to a vector calculation
	float right = y-x;
	float left = y+x;

	frontRight->Set(right);
	backRight->Set(right);
	frontLeft->Set(left);
	backLeft->Set(left);
}

void Chassis::ArcadeDriveThrust(float x, float y, float pedal){
	float x1 = x + pedal;

	float right = x1-y;
	float left = y+x1;

	frontRight->Set(right);
	backRight->Set(right);
	frontLeft->Set(left);
	backLeft->Set(left);
}

double Chassis::GetSpeed(){
	return (LeftFront->GetRate()+RightBack->GetRate())/2; //may need to change to a vector calc
}

void Chassis::SourcePID(PIDSensor sense){
	if (sense == imu && sensor != imu){
		sensor = imu;
	}else{
		sensor = encoder;
	}
}

bool Chassis::PIDdone(){
	return false;//(control->GetError() == 0);
}

double Chassis::ReturnPIDInput()
{
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	double output = 0.0;

	//if (sensor == encoder){
		//output = (LeftFront->GetDistance()+RightBack->GetDistance())/2;
	//}

	return output;
}

void Chassis::UsePIDOutput(double output)
{
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	frontRight->Set(output);
	backRight->Set(output);
	frontLeft->Set(output);
	backLeft->Set(output);
}

void Chassis::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new DriveArcadeJoystick());
}
