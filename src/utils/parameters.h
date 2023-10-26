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
const float a2 = 1.3506e-7;    // a1
const float a1 = 2.3845e-12;    // a2
const float kl = 1.684e-08;    //constante de sustentação
const float kd = 1.1123e-10;   //constante de arrasto

//estimador de atitude
const float dt = 1.0/500.0;
// const float fc = 10;
const float wc = 1.0;
const float alpha = wc*dt/(1.0+wc*dt);

const float Up = 0.005;
const float Ts = 0.3;
const float zeta = abs(log(Up))/sqrt(pow(log(Up),2)+pow(pi, 2));
const float wn = 4.0/(zeta* Ts);
const float kd_control = 2.0* zeta* wn;
const float kp = pow(wn, 2);



#endif