/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/forward.h"
#include "Robot.h"
#include <frc/Timer.h>

forward::forward(double tp, bool forward) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&globalRobot.driveSystem);
  timer = new frc::Timer();
  timePeriod = tp;
  fw = forward;
}

// Called just before this Command runs the first time
void forward::Initialize() {
  timer->Start();
  if (fw)
  {
    globalRobot.driveSystem.JoystickPercentDrive(0,0.02);
  }
  else
  {
    globalRobot.driveSystem.JoystickPercentDrive(0,-0.02);
  }
}

// Called repeatedly when this Command is scheduled to run
void forward::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool forward::IsFinished() { return timer->HasPeriodPassed(timePeriod); }

// Called once after isFinished returns true
void forward::End() {
globalRobot.driveSystem.JoystickPercentDrive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void forward::Interrupted() {End();}