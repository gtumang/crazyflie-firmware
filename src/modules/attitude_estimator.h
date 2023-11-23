#ifndef attitude_estimator_h
#define attitude_estimator_h

#include "mbed.h"
#include "crazyflie.h"

class AttitudeEstimator
{
    public:
        //Construtor
        AttitudeEstimator ();
        //Inicializa classe
        void init();
        //Estima os angulos e velocidades angulares
        void estimate();
        //Angulos
        float phi, theta, psi;
        //Velocidades angulares
        float p, q, r;
        //Pega estado

    private:
        float sec(float angulo);
        float p_bias, q_bias, r_bias;
        DigitalOut led;
        //Objeto da classe de sensores
        MPU9250 imu;
};



#endif