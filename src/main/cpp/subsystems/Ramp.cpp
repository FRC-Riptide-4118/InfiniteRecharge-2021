// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Ramp.h"

Ramp::Ramp() = default;

// This method will be called once per scheduler run
void Ramp::Periodic() {}

void Ramp::StowRamp() {

    pramp.Set(frc::DoubleSolenoid::kReverse);

}

void Ramp::LaunchRamp() {

    pramp.Set(frc::DoubleSolenoid::kForward);

}

void Ramp::StopRamp() {

    pramp.Set(frc::DoubleSolenoid::kOff);

}