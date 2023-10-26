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
    float alpha_phi = control_siso(phi_r,phi, p);
    float alpha_theta = control_siso(theta_r, theta, q);
    float alpha_psi = control_siso(psi_r, psi, r);
    tau_phi = I_xx* alpha_phi;
    tau_theta = I_yy* alpha_theta;
    tau_psi = I_zz * alpha_psi;
}

float  AttitudeController::control_siso(float angle_r, float angle, float rate)
{

    float alpha= kp*(angle_r-angle) * kd_control*(-rate);
    return alpha;
}