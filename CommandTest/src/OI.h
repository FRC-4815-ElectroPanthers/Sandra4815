#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *joy1;

public:
	float x, y;
	OI();
};

#endif
