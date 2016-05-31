#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "IterativeRobot.h"
#include "Commands/Chassis/DriveForward.h"
//#include "Commands/Chassis/DriveArcade.h"
//#include "Commands/SmartDashReport.h"
#include "Commands/Chassis/DriveForward.h"
#include <USBCamera.h>
#include <CameraServer.h>

class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	std::shared_ptr<USBCamera> cam;
	Preferences *pref = Preferences::GetInstance();

	void RobotInit()
	{
		CommandBase::init();
		CommandBase::drivetrain->CalibrateGyro();
		CommandBase::drivetrain->ResetEncoder();

		autonomousCommand = new DriveForward(6, 0.75); //6 ft

		lw = LiveWindow::GetInstance();

		SmartDashboard::PutData(Scheduler::GetInstance());

		cam = std::make_shared<USBCamera>("cam0", false);
		cam->SetBrightness(50);
		cam->UpdateSettings();
		cam->StopCapture();

		CameraServer::GetInstance()->StartAutomaticCapture(cam);

		CommandBase::drivetrain->SetPIDSmartDash(pref->GetDouble("P", 0.1),
						        pref->GetDouble("I", 0),
								pref->GetDouble("D", 0));
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		if (autonomousCommand != NULL)
			autonomousCommand->Start();

		CommandBase::drivetrain->CalibrateGyro();
		CommandBase::drivetrain->ResetEncoder();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();

		CommandBase::drivetrain->CalibrateGyro();
		CommandBase::drivetrain->ResetEncoder();

		CommandBase::drivetrain->SetPIDSmartDash(pref->GetDouble("P", 0.1),
								        pref->GetDouble("I", 0),
										pref->GetDouble("D", 0));
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();

		/*
		brightness = (int)SmartDashboard::GetNumber("DB/Sider 1", 0.0);
		cam->SetBrightness(brightness);
		if(SmartDashboard::GetBoolean("DB/Button 0", false)){
			cam->UpdateSettings();
		}
		*/
	}

	void TestPeriodic()
	{
		Scheduler::GetInstance()->Run();
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);

