#include <Commands/Chassis/DriveArcadeJoystick.h>
#include "Chassis.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

Chassis::Chassis():
		PIDSubsystem("Chassis", 0.1, 0.0, 0.0)
{
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.

	frontRight = new Talon(FRONTRIGHT);
	backRight = new Talon(BACKRIGHT);
	frontLeft = new Talon(FRONTLEFT);
	backLeft = new Talon(BACKLEFT);

	//drive = new RobotDrive(frontLeft, backLeft, frontRight, backRight);

	//left = new Encoder(FL_ENC_A, FL_ENC_B, false, Encoder::EncodingType::k4X);
	right = new Encoder(BR_ENC_A, BR_ENC_B, false, Encoder::EncodingType::k4X);

	gyro = new ADXRS450_Gyro();

	//left->SetDistancePerPulse(DISTANCE_PER_PULSE); //Feet per Pulse
	right->SetDistancePerPulse(DISTANCE_PER_PULSE);

	right->SetSamplesToAverage(56);
	//left->SetSamplesToAverage(56);

	//left->SetMinRate(0.001);
	right->SetMinRate(0.0001);

	sensor = encoder_t;

	LiveWindow::GetInstance()->AddActuator("Chassis", "PID Tuning", GetPIDController());
}

void Chassis::ArcadeDrive(float x, float y){ //may want to change to a vector calculation
	float right = y-x;
	float left = y+x;

	frontRight->Set(right);
	backRight->Set(right);
	frontLeft->Set(left);
	backLeft->Set(left);

	//drive->Drive(y, x);
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
	return (right->GetRate()); //+ left->GetRate()); //may need to change to a vector calc
}

double Chassis::GetDistanceTravel(){
	return (right->GetRaw()*DISTANCE_PER_PULSE) ;//+ left->GetRaw()*DISTANCE_PER_PULSE)/2;
	//rightBack->GetDistance() has weird scaling issues
}

void Chassis::ResetEncoder(){
	right->Reset();
	//left->Reset();
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
		frontRight->Set(-output);
		backRight->Set(-output);
		frontLeft->Set(output);
		backLeft->Set(output);
		//drive->Drive(output, 0);
	//}else if (sensor == gyroAdjust_t){
		//drive->Drive(0.5, output);
	}else{
		frontRight->Set(output);
		backRight->Set(output);
		frontLeft->Set(output);
		backLeft->Set(output);
		//drive->Drive(0, output);
	}
}

void Chassis::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new DriveArcadeJoystick());
}
