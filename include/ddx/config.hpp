#pragma once

// this file is used to configure default values used by motion algorithms used in LemLib

#include "ExitCondition.hpp"
#include "PID.hpp"
#include "hardware/Motor/MotorGroup.hpp"
#include "units/Pose.hpp"
#include <functional>

extern const ddx::PID angular_pid;
extern const ddx::PID lateral_pid;

extern const std::function<units::Pose()> pose_getter;

extern ddx::MotorGroup left_motors;
extern ddx::MotorGroup right_motors;

extern const ddx::ExitConditionGroup<AngleRange> angular_exit_conditions;
extern const ddx::ExitConditionGroup<Length> lateral_exit_conditions;

extern const Length track_width;

extern const Number drift_compensation;

extern const Number angular_slew;
extern const Number lateral_slew;
