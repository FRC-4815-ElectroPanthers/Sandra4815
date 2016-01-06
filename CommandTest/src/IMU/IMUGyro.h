/*
 * IMUGyro.h
 *
 *  Created on: Jan 6, 2016
 *      Author: Phia
 */

#ifndef SRC_IMU_IMUGYRO_H_
#define SRC_IMU_IMUGYRO_H_

#include <I2C.h>
#include <LiveWindow/LiveWindowSendable.h>
#include <PIDSource.h>
#include "WPILib.h"

class IMUGyro: public I2C, public LiveWindowSendable, public PIDSource {
public:
	IMUGyro();
	virtual ~IMUGyro();
};

#endif /* SRC_IMU_IMUGYRO_H_ */
