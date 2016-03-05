#ifndef SpinUpBangBang_H
#define SpinUpBangBang_H

#include "../CommandBase.h"
#include "WPILib.h"

class SpinUpBangBang: public CommandBase
{
public:
	SpinUpBangBang();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
