#ifndef crazyflie_h
#define crazyflie_h

// Crazyflie utility variables
#include "utils/parameters.h"
#include "utils/pin_names.h"


// Crazyflie hardware abstraction layer
#include "drivers/bmi088.h" // IMU sensor

// Flow deck hardware abstraction layer
#include "drivers/pmw3901.h" // Optical flow sensor
#include "drivers/vl53l1x.h" // Range sensor


// Modules
#include "modules/mixer.h"
#include "modules/attitude_controller.h"
#include "modules/attitude_estimator.h"
#include "modules/vertical_estimator.h"
#include "modules/vertical_controller.h"
#include "modules/horizontal_estimator.h"
#endif