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
	Command *autonomousCommand;// *report;
	LiveWindow *lw;
	std::shared_ptr<USBCamera> cam;

	void RobotInit()
	{
		CommandBase::init();
		autonomousCommand = new DriveForward(6, 0.75); //6 ft
		lw = LiveWindow::GetInstance();
		CommandBase::drivetrain->CalibrateGyro();
		CommandBase::drivetrain->ResetEncoder();
		cam = std::make_shared<USBCamera>("cam0", false);

		cam->SetBrightness(50);
		cam->UpdateSettings();
		cam->StopCapture();

		CameraServer::GetInstance()->StartAutomaticCapture(cam);

		//report = new SmartDashReport();
		//report->Start();
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		if (autonomousCommand != NULL)
			autonomousCommand->Start();
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
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);

