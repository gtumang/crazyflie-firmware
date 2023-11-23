#include "vertical_estimator.h"

// Class constructor
VerticalEstimator::VerticalEstimator() : range(E_SDA,E_SCL)
{
    // Initialize vertical position and velocity estimates
    z = 0;
    w = 0;
    z_m = 0;
}

// Initialize class
void VerticalEstimator::init() 
{
    // Initialize range sensor object
    range.init();
}

// Predict vertical position and velocity from model
void VerticalEstimator::predict(float f_t)
{
    z = z + w*dt;
    //if(z>0.05){
    //   w = w + (-g+1/m*f_t)*dt;
    //}
}

// Correct vertical position and velocity with measurement
void VerticalEstimator::correct(float phi, float theta) 
{
    range.read();
    z_m = range.d * cos(theta) * cos(phi);
    w = w + l1*dt_range*(z_m - z);
    z = z + l2*dt_range*(z_m - z);
}