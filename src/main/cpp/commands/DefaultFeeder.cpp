// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DefaultFeeder.h"

DefaultFeeder::DefaultFeeder(Feeder* feeder) : m_feeder{feeder} {

    AddRequirements({feeder});

}

void DefaultFeeder::Execute() {

    m_feeder->StopFeeder();

}