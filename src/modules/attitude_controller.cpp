#include "attitude_controller.h"
#include "utils/parameters.h"

AttitudeController::AttitudeController()
{
    tau_phi = 0;
    tau_theta = 0;
    tau_psi = 0;

    zeta_pt = abs(log(Up))/(sqrt(pow(log(Up),2)+pow(pi,2)));
    wn_pt = 4.0/(zeta_pt*Ts_pt);

    zeta_psi = abs(log(Up))/(sqrt(pow(log(Up),2)+pow(pi,2)));
    wn_psi = 4.0/(zeta_psi*Ts_psi);
}

void AttitudeController::control(float phi_r, float theta_r, float psi_r, float phi, float theta, float psi, float p, float q, float r)
{
    tau_phi = I_xx * control_siso(phi_r, phi, p, calcula_kp(wn_pt),calcula_kd(zeta_pt, wn_pt));
    tau_theta = I_yy * control_siso(theta_r, theta, q, calcula_kp(wn_pt),calcula_kd(zeta_pt, wn_pt));
    tau_psi = I_zz * control_siso(psi_r, psi, r,calcula_kp(wn_psi),calcula_kd(zeta_psi, wn_psi));
}

float  AttitudeController::control_siso(float angle_r, float angle, float rate, float kp, float kd)
{
    return kp*(angle_r-angle) + kd*(-rate);
}

float AttitudeController::calcula_kp(float wn){
    float kp = pow(wn,2);
    return kp;
}
float AttitudeController::calcula_kd(float zeta, float wn){
    float kd = 2.0*zeta*wn;
    return kd;
}