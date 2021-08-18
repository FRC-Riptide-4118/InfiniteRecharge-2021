// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Feeder.h"

Feeder::Feeder() = default;

// This method will be called once per scheduler run
void Feeder::Periodic() {}

void Feeder::RunFeeder() {

    feeder.Set(FeederConstants::feeder_forward_speed);

}

void Feeder::RunFeederReverse() {

    feeder.Set(FeederConstants::feeder_reverse_speed);

}

void Feeder::StopFeeder() {

    feeder.Set(0);
    
}