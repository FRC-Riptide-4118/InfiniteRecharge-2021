// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <subsystems/Ramp.h>

class DefaultRamp
  : public frc2::CommandHelper<frc2::CommandBase, DefaultRamp> {
    
public:
  DefaultRamp(Ramp* ramp);
  void Execute() override;

private:
  Ramp* m_ramp;
};
