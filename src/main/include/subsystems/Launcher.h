// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <Constants.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"

class Launcher : public frc2::SubsystemBase {
 public:
  Launcher(double kP, double kI, double kD);

  void Stop();
  void Run(int);
  void RaiseSetPoint();
  void LowerSetPoint();
  bool AtSpeed(int);
  double GetEncoderCount();
  double GetSetpoint(int);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:

  TalonFX launcher{LauncherConstants::launcher_motor};
  double m_kP;
  double m_kI;
  double m_kD;
  //std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("Shuffleboard")->GetTable("Game");

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
