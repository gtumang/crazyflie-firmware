# include "mbed.h"
# include "crazyflie.h"
# include "USBSerial.h"

// Define serial object
USBSerial serial;

// Crazyfire controler object
AttitudeEstimator att_est;
VerticalEstimator ver_est;

// Define ticker
Ticker tic, tic_range;

//Define interrupt flags
bool flag, flag_range;

// Define callback functions
void callback(){flag = true;}
void callback_range(){flag_range = true;}

// Main program
int main()
{
    // Initialize estimators
    att_est.init();
    ver_est.init();
    
    // Initialize interrupts
    tic.attach(&callback, dt);
    tic_range.attach(&callback_range, dt_range);

    while(true)
    {  
        if(flag)
        {
            // Reset flag
            flag = false;

            // Update estimators
            att_est.estimate();
            ver_est.predict(0.0);

            if(flag_range)
            {
                // Reset flag
                flag_range = false;

                // Update estimators
                ver_est.correct(att_est.phi, att_est.theta);
                serial.printf("z_m(m): %6.2f | z (m): %6.2f | w (m/s): %6.2f \n",ver_est.z_m , ver_est.z, ver_est.w);
            }
        }
    }
}