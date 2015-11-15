#include "OI.h"

OI::OI()
{
	// Process operator interface input here.
	joy1 = new Joystick(1);

	x = joy1->GetRawAxis(1);
	y = joy1->GetRawAxis(2);

}
