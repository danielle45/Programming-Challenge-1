/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"


OI::OI() {
  xbox1 = new frc::Joystick(0);
  // Process operator interface input here.
  // frc::JoystickButton *Buttonx9_LeftJoystick = new frc::JoystickButton(xbox1, 9);
  // frc::JoystickButton *Buttonx10_RightJoystick = new frc::JoystickButton(xbox1, 10);
}
