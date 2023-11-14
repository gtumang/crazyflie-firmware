#ifndef vertical_controller_h
#define vertical_controller_h

#include "mbed.h"
#include "crazyflie.h"

class VerticalController{
    public:
        VerticalController();
        void control(float z_r, float z, float w);
        float f_t;
    
    private:
        float control_siso(float pos_r, float pos, float vel, float kp, float kd);

};

#endif