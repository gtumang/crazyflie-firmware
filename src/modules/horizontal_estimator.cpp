#include "mbed.h"
#include "crazyflie.h"

HorizontalEstimator::HorizontalEstimator() : flow(PA_7, PA_6, PA_5, PB_4){
    x = 0;
    y = 0;
    u = 0;
    v = 0;
}

void HorizontalEstimator::init(){
    //inicia PMW3901
    flow.init();
}

void HorizontalEstimator::predict(float phi, float theta){
    x = x + u*dt;
    y = y + v*dt;
    //u = u + g * theta * dt;
    //v = v - g * phi * dt;
}

void HorizontalEstimator::correct(float phi, float theta, float p, float q, float z){
    float den = cos(phi)*cos(theta);
    if(den>0.5){
        flow.read();
        float d = z/den;
        float u_m = (sigma * flow.px + q)*d;
        float v_m = (sigma * flow.py - p)*d;
        u = u + l3*dt*(u_m - u);
        v = v + l3*dt*(v_m - v);
        
    }
}