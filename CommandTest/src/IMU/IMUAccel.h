/*
 * IMUAccel.h
 *
 *  Created on: Jan 3, 2016
 *      Author: Phia
 */

#ifndef IMUACCEL_H_
#define IMUACCEL_H_

#include <interfaces/Accelerometer.h>
#include <I2C.h>
#include <LiveWindow/LiveWindowSendable.h>
#include <PIDSource.h>
#include "WPILib.h"

class IMUAccel: public Accelerometer,
		public I2C,
		public LiveWindowSendable,
		public PIDSource {
public:
	IMUAccel();
	virtual ~IMUAccel();
};

#endif /* IMUACCEL_H_ */
