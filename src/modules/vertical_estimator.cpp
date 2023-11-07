#include "vertical_estimator.h"

// Class constructor
VerticalEstimator::VerticalEstimator() : range(E_SDA,E_SCL)
{
    // Initialize vertical position and velocity estimates
    z = 0;
    w = 0;
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
}

// Correct vertical position and velocity with measurement
void VerticalEstimator::correct(float phi, float theta) 
{
}