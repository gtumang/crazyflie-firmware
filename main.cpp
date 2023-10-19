// Example
// #include "programs/examples/ex01_leds.h"
// #include "programs/examples/ex02_motors.h"
// #include "programs/examples/ex03_serial.h"
//#include "programs/examples/ex04_imu.h"
// #include "programs/examples/ex05_range.h"
// #include "programs/examples/ex06_flow.h"

// Chapters
// #include "programs/chapters/ch09.h"

#include "mbed.h"
#include "crazyflie.h"
#include "USBSerial.h"
#include "attitude_estimator.h"

USBSerial serial;

char command;

AttitudeEstimator att_est;

Ticker tic;

bool flag;

void callback(){
    flag = true;
}

int main(){
    att_est.init();

    tic.attach(&callback, dt);

    while(true){
        if(flag){
            flag = false;
            att_est.estimate();
        }
        if(serial.readable()){
            command = serial.getc();
            if(command == 'p'){
                serial.printf("%f,%f,%f\n",att_est.phi,att_est.theta,att_est.psi);
            }
        }
    }
    

    return 0;
}