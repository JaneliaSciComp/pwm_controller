// ----------------------------------------------------------------------------
// Controller.h
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Adafruit_PWMServoDriver.h"
#include "ModularServer.h"
#include "EventController.h"
#include "Constants.h"
#include "Callbacks.h"

class Controller
{
public:
  Controller();
  void setup();
  void update();
  ModularDevice::ModularServer & getModularServer();

  void setServoPosition(size_t channel, size_t servo_position);
  // void saveState(const size_t state);
  // void recallState(const size_t state);
private:
  ModularDevice::ModularServer modular_server_;

  ModularDevice::Field fields_[constants::FIELD_COUNT_MAX];
  ModularDevice::Parameter parameters_[constants::PARAMETER_COUNT_MAX];
  ModularDevice::Method methods_[constants::METHOD_COUNT_MAX];

  Adafruit_PWMServoDriver pwm_driver_;
};

extern Controller controller;

#endif
