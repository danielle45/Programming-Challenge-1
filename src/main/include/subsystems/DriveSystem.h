/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "ctre/phoenix.h"

class DriveSystem : public frc::Subsystem {
 private:
  TalonSRX rightForwardMotor;
  TalonSRX rightBackwardMotor;
  TalonSRX leftForwardMotor;
  TalonSRX leftBackwardMotor;

  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  DriveSystem();
  void InitDefaultCommand() override;
  void PowerDrive(double axis);
  void JoystickPercentDrive(double x, double y);
};
