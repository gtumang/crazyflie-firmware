#include "attitude_estimator.h"
#include "math.h"
#include <cmath>

AttitudeEstimator::AttitudeEstimator () : imu(IMU_SDA,IMU_SCL), led(LED_RED_L)
{
    //inicia variáveis com valores zerados
    this->phi = 0;
    this->theta = 0;
    this->psi = 0;
    this->p = 0;
    this->q = 0;
    this->r = 0;
    this->p_bias = 0;
    led.write(1);
}

void AttitudeEstimator::init(){
    //inicia IMU
    imu.init();
    for(int i = 0; i<500; i++){
        imu.read();
        p_bias += 1.0/500*imu.gx;
        q_bias += 1.0/500*imu.gy;
        r_bias += 1.0/500*imu.gz;
        led = !led;
        wait(dt);
    }
    led.write(1);
        //calibrar giroscópio
}

void AttitudeEstimator::estimate(){
    imu.read();
    ////Acelerômetro
    float phi_a = atan2(-imu.ay, -imu.az);
    float theta_a = atan2(imu.ax, -imu.az);
    ////Giroscópio
    p = imu.gx - p_bias;
    float phi_g = phi + p*dt;

    q = imu.gy - q_bias;
    float theta_g = theta + q*dt;

    r = imu.gz - r_bias;
    float psi_g = psi + r*dt;

    phi = (1-alpha)*phi_g+alpha*phi_a;
    theta = (1-alpha)*theta_g+alpha*theta_a;
    psi = psi_g;
}