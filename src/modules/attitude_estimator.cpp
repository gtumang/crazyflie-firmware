#include "attitude_estimator.h"
#include "math.h"
#include <cmath>

AttitudeEstimator::AttitudeEstimator () : imu(IMU_SDA,IMU_SCL), led(LED_RED_L)
{
    //inicia variáveis com valores zerados
    phi = 0;
    theta = 0;
    psi = 0;
    p = 0;
    q = 0;
    r = 0;
    p_bias = 0;
    led.write(1);
}

void AttitudeEstimator::init(){
    wait(3);
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
    float theta_a = atan2(imu.ax, -((imu.az > 0)-(imu.az < 0))*sqrt(imu.ay*imu.ay + imu.az*imu.az) );

    ////Giroscópio
    p = imu.gx - p_bias;
    float phi_g = phi + (p + sin(phi)*tan(theta)*q + cos(phi)*tan(theta)*r)*dt;

    q = imu.gy - q_bias;
    float theta_g = theta + (cos(phi)*q - sin(phi)*r)*dt;

    r = imu.gz - r_bias;
    float psi_g = psi + (sin(phi)*sec(theta)*q + cos(phi)*sec(theta)*r)*dt;

    phi = (1-alpha)*phi_g+alpha*phi_a;
    theta = (1-alpha)*theta_g+alpha*theta_a;
    psi = psi_g;
}

float AttitudeEstimator::sec(float angulo){
    if(cos(angulo)!=0){
        return 1/cos(angulo);
    }
    return 0;
}