#ifndef mixer_h
#define mixer_h
//#include "../crazyflie.h"
#include "mbed.h"


class Mixer {
public:
  //construtor
  Mixer();
  void actuate(float f_t, float tau_phi, float tau_theta, float tau_psi);
  void arm();
  void disarm();

private:
  bool armed = 0;
  PwmOut motor_1, motor_2, motor_3, motor_4;
  DigitalOut led_armado, led_aviso;
  float omega_1, omega_2, omega_3, omega_4;

  void mixer(float f_t, float tau_phi, float tau_theta, float thau_psi);
  float control_motor(float omega);
};

#endif