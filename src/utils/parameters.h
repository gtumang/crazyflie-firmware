#ifndef parameters_h
#define parameters_h

#include <cmath>
// Physical constants
const float pi = 3.1416;
const float g = 9.81;       // m/s^2

// Quadcopter dimensions
const float m = 30.0e-3;    // kg
const float I_xx = 16.0e-6; // kg.m^2
const float I_yy = 16.0e-6; // kg.m^2
const float I_zz = 29.0e-6; // kg.m^2
const float l = 33.0e-3;    // m

const float a2 = 1.3506e-7;    // a2
const float a1 = 2.3845e-12;    // a1

const float kl = 1.684e-08;    //constante de sustentação
const float kd = 1.1123e-10;   //constante de arrasto

//estimador de atitude
const float dt = 1.0/500.0;
const float wc = 1.0;
const float alpha = wc*dt/(1.0+wc*dt);

//Controlador de atitude
const float Up = 0.005;
const float Ts_pt = 0.3;
const float Ts_psi = 0.6;
const float zeta_pt = abs(log(Up))/(sqrt(pow(log(Up),2)+pow(pi,2)));
const float wn_pt = 4.0/(zeta_pt*Ts_pt);
const float zeta_psi = abs(log(Up))/(sqrt(pow(log(Up),2)+pow(pi,2)));
const float wn_psi = 4.0/(zeta_psi*Ts_psi);
const float kp_pt = pow(wn_pt,2);
const float kd_pt = 2.0*zeta_pt*wn_pt;
const float kp_psi = pow(wn_psi,2);
const float kd_psi= 2.0*zeta_psi*wn_psi;

//Estimador vertical
const float dt_range = 1.0/20.0;
const float wc_ve = 10.0;
const float zeta_ve = sqrt(2.0)/2.0;
const float l1 = wc_ve*wc_ve;
const float l2 = 2.0*wc_ve*zeta_ve;

//Controlador vertical
const float Ts_ver = 2.0;
const float Up_ver = 0.005;
const float zeta_ver = abs(log(Up_ver))/(sqrt(pow(log(Up_ver),2)+pow(pi,2)));
const float wn_ver = 4.0/(zeta_ver*Ts_ver);
const float kp_ver = pow(wn_ver,2);
const float kd_ver = 2.0*wn_ver*zeta_ver;
// const float kp_ver = 5.8567;
// const float kd_ver = 3.4225;

//Propriedades do sensor de fluxo óptico
const float gamma = 42.0*pi/180.0;
const float W = 420.0;
const float sigma = 2.0*tan(gamma/2.0)/(W*dt);

//Estimador horizontal
const float wc_hoz = 50.0;
const float l3 = wc_hoz;

//Controlador horizontal
const float Ts_hor = 2.0;
const float Up_hor = 0.005;
const float zeta_hor = abs(log(Up_hor))/(sqrt(pow(log(Up_hor),2)+pow(pi,2)));
const float wn_hor = 4.0/(zeta_hor*Ts_hor);
const float kp_hor = pow(wn_hor,2);
const float kd_hor = 2.0*wn_hor*zeta_hor;

#endif