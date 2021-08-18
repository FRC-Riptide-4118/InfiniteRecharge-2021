// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */


namespace FeederConstants {

    const int feeder_motor = 7; 
    const double feeder_forward_speed = 0.975;  // requires testing
    const double feeder_reverse_speed = -0.975;  // requires testing

}

namespace RampConstants {

    const int pramp_fw = 2;
    const int pramp_rv = 3;

}

namespace LauncherConstants {

    // copied from last year's code - requires testing & checking ports
    const int launcher_motor = 6;
    const double kP = 0.44;
    const double kI = 2.25e-5;
    const double kD = 3e-6;
    const double setp[4] = {2000, 13100, 11700, 11400};
    const std::string zones[4] = {"Zone 1", "Zone 2", "Zone 3", "Zone 4"};

    //const int setpoints[4] = {0, 13000, 13000, 0};
    //std::string zones[4] = {"Zone 1", "Zone 2", "Zone 3", "Zone 4"};
    //int selectedSetpoint;
    //double setpoint = setpoints[selectedSetpoint];


}

namespace DriveConstants {

    // copied from last year's code - requires testing & checking ports
    const int left_talon1 = 0;
    const int left_talon2 = 1;
    const int left_victor = 2;

    const int right_talon1 = 3;
    const int right_talon2 = 4;
    const int right_victor = 5;

    const int pshifter_fw = 0;
    const int pshifter_rv = 1;

}