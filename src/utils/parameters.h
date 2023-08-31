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

#endif