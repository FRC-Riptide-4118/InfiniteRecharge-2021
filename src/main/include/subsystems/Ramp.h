// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DoubleSolenoid.h>
#include <Constants.h>

class Ramp : public frc2::SubsystemBase {
 public:
  Ramp();
  void StowRamp();
  void LaunchRamp();
  void StopRamp();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:

  frc::DoubleSolenoid pramp{RampConstants::pramp_fw, RampConstants::pramp_rv};

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
