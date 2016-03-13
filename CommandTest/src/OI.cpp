#include "OI.h"
#include "Buttons/JoystickButton.h"
#include "Commands/Chassis/DriveArcadeRampUp.h"
#include "Commands/IntakeShooter/Shoot.h"
#include "Commands/IntakeShooter/DriveArmPosition.h"
#include "Commands/IntakeShooter/Intake.h"
#include "Commands/IntakeShooter/SpitOut.h"
#include "Commands/IntakeShooter/SpinUpBangBang.h"

OI::OI()
{
	// Process operator interface input here.
	drive = new Joystick(0);
	operate = new Joystick(1);

	JoystickButton *drive1 = new JoystickButton(drive, 1),
				   *drive2 = new JoystickButton(drive, 2),
				   *drive3 = new JoystickButton(drive, 3),
				   *drive4 = new JoystickButton(drive, 4),
				   *drive5 = new JoystickButton(drive, 5),
				   *drive6 = new JoystickButton(drive, 6),
				   *drive7 = new JoystickButton(drive, 7),
				   *drive8 = new JoystickButton(drive, 8);

	drive5->WhenPressed(new DriveArcadeRampUp());
	drive6->CancelWhenPressed(new DriveArcadeRampUp());
	drive8->WhenPressed(new Shoot());

	JoystickButton *operate1 = new JoystickButton(operate, 1),
				   *operate2 = new JoystickButton(operate, 2),
				   *operate3 = new JoystickButton(operate, 3),
				   *operate4 = new JoystickButton(operate, 4),
				   *operate5 = new JoystickButton(operate, 5),
				   *operate6 = new JoystickButton(operate, 6),
				   *operate7 = new JoystickButton(operate, 7),
				   *operate8 = new JoystickButton(operate, 8);

	operate1->WhenPressed(new DriveArmPosition(IntakeShooter::kInOutTake));
	operate2->WhenPressed(new DriveArmPosition(IntakeShooter::kBackShot));
	operate3->WhenPressed(new DriveArmPosition(IntakeShooter::kFrontShot));
	operate4->WhenPressed(new DriveArmPosition(IntakeShooter::kStow));
	operate5->WhenPressed(new Intake());
	operate6->WhenPressed(new SpitOut());
	operate7->WhenPressed(new SpinUpBangBang());
}
