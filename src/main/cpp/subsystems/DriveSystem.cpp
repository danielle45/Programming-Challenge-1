/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveSystem.h"
#include "commands/JoystickDrive.h"

DriveSystem::DriveSystem() : Subsystem("DriveSystem"), rightForwardMotor(0), rightBackwardMotor(1), leftForwardMotor(5), leftBackwardMotor(4) {}

void DriveSystem::InitDefaultCommand() {

  SetDefaultCommand(new JoystickDrive());

  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveSystem::PowerDrive(double axis)
{
  float power;
  if(axis > 0)
  {
    power = -0.001;
  }
  else if(axis < 0)
  {
    power = 0.001;
  }
  else
  {
    power = 0;
  }



  rightForwardMotor.Set(ControlMode::PercentOutput, power);
  rightBackwardMotor.Set(ControlMode::PercentOutput, power);
  leftForwardMotor.Set(ControlMode::PercentOutput, power);
  leftBackwardMotor.Set(ControlMode::PercentOutput, power);
  }

  void DriveSystem::JoystickPercentDrive(double x, double y)
{
  double l;
  double r;
  if (y > 0.2)
  {
    y = (y - 0.2  ) * 1 / .8;
  }
  else if (y < -0.2)
  {
    y = (y + 0.2) * 1 / .8;
  }
  else
  {
    y = 0;
  }

  if (x > 0.2)
  {
    x = (x - 0.2) * 1 / .8;
  }
  else if (x < -0.2)
  {
    x = (x + 0.2) * 1 / .8;
  }
  else
  {
    x = 0;
  }

  l = -y - x;
  r = -y + x;

  rightForwardMotor.Set(ControlMode::PercentOutput, r);         //Might be wrong
  rightBackwardMotor.Set(ControlMode::PercentOutput, r);
  leftForwardMotor.Set(ControlMode::PercentOutput, l);
  leftBackwardMotor.Set(ControlMode::PercentOutput, l);
}