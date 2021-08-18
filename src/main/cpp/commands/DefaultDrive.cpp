// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DefaultDrive.h"

DefaultDrive::DefaultDrive(Drive* subsystem, std::function<double()> forward, std::function<double()> rotate) : m_subsystem{subsystem}, m_forward{forward}, m_rotate{rotate} {

  AddRequirements({subsystem});

}

void DefaultDrive::Execute() {

  m_subsystem->ArcadeDrive(m_forward(), m_rotate());

}