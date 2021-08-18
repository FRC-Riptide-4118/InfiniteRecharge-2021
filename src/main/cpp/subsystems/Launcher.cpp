// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Launcher.h"
#include <frc/shuffleboard/Shuffleboard.h>

Launcher::Launcher(double kP, double kI, double kD) : m_kP{kP}, m_kI{kI}, m_kD{kD} {

    launcher.SetInverted(true);
    launcher.ConfigSupplyCurrentLimit( SupplyCurrentLimitConfiguration(true, 40, 35, 1.0));
    launcher.ConfigClosedloopRamp(5);
    launcher.ConfigSelectedFeedbackSensor(TalonFXFeedbackDevice::IntegratedSensor);

    launcher.Config_kF(0, 0);
    launcher.Config_kP(0, m_kP);
    launcher.Config_kI(0, m_kI);
    launcher.Config_kD(0, m_kD);
    //m_setpoint = table->GetNumber("Launcher Setpoint", 0.0);

}

// This method will be called once per scheduler run
void Launcher::Periodic() {}

void Launcher::Stop() {

    launcher.Set(ControlMode::PercentOutput, 0);

}

void Launcher::Run(int counter) {

    launcher.Set(ControlMode::Velocity, LauncherConstants::setp[counter]);
    std::cout << launcher.GetSelectedSensorVelocity() << std::endl;
    //std::cout << (bool)table->ContainsKey("Launcher Setpoint") << std::endl;

}

// void Launcher::RaiseSetPoint() {

   //  LauncherConstants::selectedSetpoint += 1;

// }

// void Launcher::LowerSetPoint() {

   //  LauncherConstants::selectedSetpoint -= 1;


// }

bool Launcher::AtSpeed(int counter) {

    return (launcher.GetSelectedSensorVelocity() >= LauncherConstants::setp[counter] - 500);

}

double Launcher::GetEncoderCount() {

    return launcher.GetSelectedSensorVelocity();

}

double Launcher::GetSetpoint(int counter) {

    return LauncherConstants::setp[counter];

}