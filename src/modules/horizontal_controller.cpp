#include "crazyflie.h"

HorizontalController::HorizontalController(){
    phi_r = 0;
    theta_r = 0;
}

void HorizontalController::control(float x_r, float y_r, float x, float y, float u, float v){
    theta_r = 1/g * control_siso(x_r, x, u, kp_hor, kd_hor);
    phi_r = -1/g * control_siso(y_r, y, v, kp_hor, kd_hor);
}

float HorizontalController::control_siso(float pos_r, float pos, float vel, float kp, float kd){
    return kp*(pos_r - pos) + kd*(0 - vel);
}
