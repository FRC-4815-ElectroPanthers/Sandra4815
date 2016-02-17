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

	//LeftFront = new Encoder(FL_ENC_A, FL_ENC_B, false, Encoder::EncodingType::k4X);
	rightBack = new Encoder(BR_ENC_A, BR_ENC_B, false, Encoder::EncodingType::k4X);

	gyro = new ADXRS450_Gyro();

	//LeftFront->SetDistancePerPulse(distancePerPulse); //Feet per Pulse
	rightBack->SetDistancePerPulse(distancePerPulse); //try dividing by 1024 instead

	rightBack->SetSamplesToAverage(56);

	//LeftFront->SetMinRate(0.001);
	rightBack->SetMinRate(0.0001);

	sensor = encoder_t;
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
	return rightBack->GetRate(); //may need to change to a vector calc
	//(LeftFront->GetRate()+
}

double Chassis::GetDistanceTravel(){
	return rightBack->GetRaw()*distancePerPulse;
	//rightBack->GetDistance() has weird scaling issues
}

void Chassis::ResetEncoder(){
	rightBack->Reset();
}

void Chassis::CalibrateGyro(){
	gyro->Reset();
	gyro->Calibrate();
}

void Chassis::ResetGyro(){
	gyro->Reset();
}

double Chassis::GetYaw(){
	return gyro->GetAngle();
}

void Chassis::SourcePID(PIDSensor sense){
	if (sense == gyro_t && sensor != gyro_t){
		sensor = gyro_t;
	}else{
		sensor = encoder_t;
	}
}

bool Chassis::PIDdone(){
	return ((GetSetpoint()-GetPosition()) < 0.001 && (GetSetpoint()-GetPosition()) > -0.001);
}

void Chassis::Report(){
	std::cout << "Speed: " << GetSpeed() << " ft/s \n"
			  << "Distance Traveled: " << GetDistanceTravel() << " ft\n"
			  << "Relative Heading Angle: " << GetYaw() << " degrees\n\n";
}

double Chassis::ReturnPIDInput()
{
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	double output = 0.0;

	if (sensor == encoder_t){
		output = GetDistanceTravel();
	}else{
		output = gyro->GetAngle();
	}

	return output;
}

void Chassis::UsePIDOutput(double output)
{
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	if(sensor == encoder_t){
		frontRight->Set(output);
		backRight->Set(output);
		frontLeft->Set(output);
		backLeft->Set(output);
	}else{
		frontRight->Set(output);
		backRight->Set(output);
		frontLeft->Set(-output);
		backLeft->Set(-output);
	}
}

void Chassis::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new DriveArcadeJoystick());
}
