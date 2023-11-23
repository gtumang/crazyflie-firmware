#include "mbed.h"
#include "crazyflie.h"

VerticalController::VerticalController(){
    f_t = 0;
};

void VerticalController::control(float z_r, float z, float w){
    float acc_z = control_siso(z_r, z, w, kp_ver, kd_ver);
    f_t = m*(g+acc_z);
};

float VerticalController::control_siso(float pos_r, float pos, float vel, float kp, float kd){
    return kp*(pos_r - pos) + kd*(-vel);
};