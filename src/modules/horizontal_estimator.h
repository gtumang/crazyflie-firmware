#ifndef horizontal_estimator_h
#define horizontal_estimator_h

#include "mbed.h"
#include "crazyflie.h"

class HorizontalEstimator{
    public:
        HorizontalEstimator();
        void init();
        void predict(float phi, float theta);
        void correct(float phi, float theta, float p, float q, float z);
        float x, y, u, v;

    private:
        PMW3901 flow;
};

#endif