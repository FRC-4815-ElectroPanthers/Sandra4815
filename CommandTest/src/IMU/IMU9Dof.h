/*
 * IMU9Dof.h
 *
 *  Created on: Jan 3, 2016
 *      Author: Phia
 */

#ifndef IMU9DOF_H_
#define IMU9DOF_H_

#include <interfaces/Accelerometer.h>
#include <I2C.h>
#include <LiveWindow/LiveWindowSendable.h>
#include <PIDSource.h>
#include "WPILib.h"

class IMU9Dof: public Accelerometer,
		public I2C,
		public LiveWindowSendable,
		public PIDSource {
public:
	IMU9Dof();
	virtual ~IMU9Dof();
};

#endif /* IMU9DOF_H_ */
