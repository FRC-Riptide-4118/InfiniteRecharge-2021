// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>

#include <frc/smartdashboard/SendableChooser.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/BuiltInWidgets.h>
#include <wpi/StringMap.h>

#include <Constants.h>

#include <subsystems/Drive.h>
#include <subsystems/Feeder.h>
#include <subsystems/Launcher.h>
#include <subsystems/Ramp.h>
#include <subsystems/Limelight.h>

#include <commands/DefaultDrive.h>
#include <commands/DefaultFeeder.h>
#include <commands/DefaultLauncher.h>
#include <commands/DefaultRamp.h>
#include <commands/DefaultLimelight.h>

#include <frc/XboxController.h> 

#include <frc2/command/button/Button.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/InstantCommand.h>


/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  Drive m_drive;
  Feeder m_feeder;
  Launcher m_launcher{LauncherConstants::kP, LauncherConstants::kI, LauncherConstants::kD};
  Ramp m_ramp;
  Limelight m_limelight;
  int counter = 0;

  frc2::RunCommand run_feeder{[this] {m_feeder.RunFeeder();}, {&m_feeder}};
  frc2::RunCommand run_feeder_reverse{[this] {m_feeder.RunFeederReverse();}, {&m_feeder}};
  frc2::RunCommand run_launcher{[this] {m_launcher.Run(counter);}, {&m_launcher}};
  frc2::RunCommand raise_ramp{[this] {m_ramp.LaunchRamp();}, {&m_ramp}};
  frc2::RunCommand lower_ramp{[this] {m_ramp.StowRamp();}, {&m_ramp}};
  frc2::RunCommand set_high_gear{[this] {m_drive.SetHighGear();}, {&m_drive}};
  frc2::RunCommand set_low_gear{[this] {m_drive.SetLowGear();}, {&m_drive}};
  frc2::InstantCommand set_zone_up{[this] {counter++; counter=abs(counter); counter%=4; std::cout << counter << std::endl;}};
  frc2::InstantCommand set_zone_down{[this] {counter=(counter-1+4)%4; counter=abs(counter); counter%=4; std::cout << counter << std::endl;}};


  frc::XboxController driver_controller{0};
  frc2::Button r_bumper{[&] { return driver_controller.GetBumper(frc::GenericHID::JoystickHand::kRightHand); }};
  frc2::Button l_bumper{[&] { return driver_controller.GetBumper(frc::GenericHID::JoystickHand::kLeftHand); }};
  frc2::Button up_button{[&] { return driver_controller.GetPOV() == 0; }};
  frc2::Button down_button{[&] { return driver_controller.GetPOV() == 180; }};
  frc2::Button right_button{[&] { return driver_controller.GetPOV() == 90; }};
  frc2::Button left_button{[&] { return driver_controller.GetPOV() == 270; }};
  frc2::Button r_trigger{[&] { return driver_controller.GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand) != 0; }};
  frc2::Button l_trigger{[&] { return driver_controller.GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand) != 0; }};
  frc2::Button a_button{[&] { return driver_controller.GetAButton(); }};
  frc2::Button y_button{[&] { return driver_controller.GetYButton(); }};
  frc2::Button x_button{[&] { return driver_controller.GetXButton(); }};

  void ConfigureButtonBindings();};
