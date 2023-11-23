#include "attitude_controller.h"
#include "utils/parameters.h"

AttitudeController::AttitudeController()
{
    tau_phi = 0;
    tau_theta = 0;
    tau_psi = 0;
}

void AttitudeController::control(float phi_r, float theta_r, float psi_r, float phi, float theta, float psi, float p, float q, float r)
{
    tau_phi = I_xx * control_siso(phi_r, phi, p, kp_pt, kd_pt);
    tau_theta = I_yy * control_siso(theta_r, theta, q, kp_pt, kd_pt);
    tau_psi = I_zz * control_siso(psi_r, psi, r, kp_psi, kd_psi);
}

float  AttitudeController::control_siso(float angle_r, float angle, float rate, float kp, float kd)
{
    return kp*(angle_r-angle) + kd*(-rate);
}