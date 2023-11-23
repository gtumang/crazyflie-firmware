#ifndef horizontal_crontroller_h
#define horizontal_crontroller_h

#include "mbed.h"
#include "crazyflie.h"

class HorizontalController{
    public:
        HorizontalController();
        void control(float x_r, float y_r, float x, float y, float u, float v);
        float phi_r, theta_r;
    private:
        float control_siso(float pos_r, float pos, float vel, float kp, float kd);
};

#endif

