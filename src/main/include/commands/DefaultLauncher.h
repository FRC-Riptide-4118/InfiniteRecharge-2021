// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <subsystems/Launcher.h>

class DefaultLauncher 
  : public frc2::CommandHelper<frc2::CommandBase, DefaultLauncher> {

 public:
  DefaultLauncher(Launcher* launcher);
  void Execute() override;

private:
  Launcher* m_launcher;
};
