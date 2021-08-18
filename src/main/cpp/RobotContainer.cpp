// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here
  // frc::Shuffleboard::GetTab("Game").Add("Launcher Setpoint", 12000).WithWidget(frc::BuiltInWidgets::kTextView).GetEntry();
  frc::Shuffleboard::GetTab("Game").AddBoolean("Launcher Ready", [this] {return m_launcher.AtSpeed(counter);});
  frc::Shuffleboard::GetTab("Game").AddNumber("Launcher Velocity", [this] {return m_launcher.GetEncoderCount();});
  frc::Shuffleboard::GetTab("Game").AddNumber("Launcher Setpoint", [this] {return m_launcher.GetSetpoint(counter);});
  frc::Shuffleboard::GetTab("Game").AddString("Zone", [this] {return LauncherConstants::zones[counter];});

  // Configure the button bindings
 ConfigureButtonBindings();

  m_drive.SetDefaultCommand(DefaultDrive{&m_drive, [this] { return -driver_controller.GetY(frc::GenericHID::JoystickHand::kLeftHand); }, [this] { return -0.7*driver_controller.GetX(frc::GenericHID::JoystickHand::kRightHand); } });
  m_launcher.SetDefaultCommand(DefaultLauncher(&m_launcher));
  m_feeder.SetDefaultCommand(DefaultFeeder(&m_feeder));
  m_ramp.SetDefaultCommand(DefaultRamp(&m_ramp));
  m_limelight.SetDefaultCommand(DefaultLimelight(&m_limelight));

}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here

  r_bumper.ToggleWhenPressed(&run_launcher);
  a_button.WhileHeld(&raise_ramp);

  l_trigger.WhileHeld(&run_feeder);
  l_bumper.WhileHeld(&run_feeder_reverse);

  up_button.WhenPressed(&set_zone_up);
  down_button.WhenPressed(&set_zone_down);

  y_button.ToggleWhenPressed(&set_high_gear);

}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous

}
