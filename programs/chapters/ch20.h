#include "mbed.h"
#include "crazyflie.h"

Mixer mixer;
AttitudeEstimator att_est;
AttitudeController att_cont;
VerticalEstimator ver_est;
VerticalController ver_cont;

Ticker tic, tic_range;

bool flag, flag_range;

void callback(){flag = true;};
void callback_range(){flag_range = true;};

int main(){
    float z_r = 0.1;
    float phi_r = 0.0;
    float theta_r = 0.0;
    float psi_r = 0.0;

    att_est.init();
    ver_est.init();

    tic.attach(&callback, dt);
    tic_range.attach(&callback_range, dt_range);

    mixer.arm();
    while(abs(att_est.phi)<= pi/4.0 && abs(att_est.theta) <= pi/4.0 && abs(att_est.p)<= 4.0*pi && abs(att_est.q)<=4.0*pi && abs(att_est.r) <=4.0*pi){
        if(flag){
            flag = false;
            att_est.estimate();
            ver_est.predict(ver_cont.f_t);
            if (flag_range) {
                flag_range = false;
                ver_est.correct(att_est.phi, att_est.theta);
            }
            ver_cont.control(z_r, ver_est.z, ver_est.w);
            att_cont.control(phi_r, theta_r, psi_r, att_est.phi, att_est.phi, att_est.psi, att_est.p, att_est.q, att_est.r);
            mixer.actuate(ver_cont.f_t/(cos(att_est.phi)*cos(att_est.theta)), att_cont.tau_phi, att_cont.tau_theta, att_cont.tau_psi);
        }
    }
    mixer.disarm();
    while (true);
}