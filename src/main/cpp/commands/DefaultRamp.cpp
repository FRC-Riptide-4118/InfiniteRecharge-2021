// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DefaultRamp.h"

DefaultRamp::DefaultRamp(Ramp* ramp) : m_ramp{ramp} {

    AddRequirements({ramp});

}

void DefaultRamp::Execute() {

    m_ramp->StowRamp();

}