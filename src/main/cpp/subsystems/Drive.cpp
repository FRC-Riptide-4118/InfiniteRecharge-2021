// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drive.h"

Drive::Drive() {

    left_talon1.ConfigFactoryDefault();
    right_talon1.ConfigFactoryDefault();

    left_talon2.Follow(left_talon1);
    left_victor.Follow(left_talon1);

    right_talon2.Follow(right_talon1);
    right_victor.Follow(right_talon1);

    drive.SetSafetyEnabled(false);
    left_talon1.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative);
    right_talon1.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative);

    left_talon1.Config_kF(0, 0);
    left_talon1.Config_kP(0, 0.03);
    left_talon1.Config_kI(0, 0);
    left_talon1.Config_kD(0, 0);

    right_talon1.Config_kF(0, 0);
    right_talon1.Config_kP(0, 0.03);
    right_talon1.Config_kI(0, 0);
    right_talon1.Config_kD(0, 0);

    left_talon1.SetSensorPhase(false);
    right_talon1.SetSensorPhase(false);

}

// This method will be called once per scheduler run
void Drive::Periodic() {}

void Drive::SetHighGear() {

    pshifter.Set(frc::DoubleSolenoid::kForward);  // check to make sure this is correct

}

void Drive::SetLowGear() {

    pshifter.Set(frc::DoubleSolenoid::kReverse);  // check ^^

}

void Drive::ResetEncoder() {

    left_talon1.SetSelectedSensorPosition(0);
    right_talon1.SetSelectedSensorPosition(0);

}

void Drive::CurvatureDrive(double forward, double rotate) {

    drive.CurvatureDrive(forward, rotate, false);
    this->SetLowGear();

}

void Drive::ArcadeDrive(double forward, double rotate) {

    drive.ArcadeDrive(forward, rotate);
    this->SetLowGear();

}