// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <subsystems/Drive.h>

class DefaultDrive
  : public frc2::CommandHelper<frc2::CommandBase, DefaultDrive> {

public: 
  DefaultDrive(Drive* subsystem, std::function<double()> forward, std::function<double()> rotate);
  void Execute();

private:
  Drive* m_subsystem;
  std::function<double()> m_forward;
  std::function<double()> m_rotate;
};