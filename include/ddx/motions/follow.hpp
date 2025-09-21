#pragma once

#include "ddx/config.hpp"
#include "hot-cold-asset/asset.hpp"

namespace ddx {
struct FollowParams {
        bool reversed = false;
        Number lateralSlew = lateral_slew;
};

struct FollowSettings {
        Length trackWidth = track_width;
        std::function<units::Pose()> poseGetter = pose_getter;
        ddx::MotorGroup& leftMotors = left_motors;
        ddx::MotorGroup& rightMotors = right_motors;
};

void follow(const asset& path, Length lookaheadDistance, Time timeout, FollowParams params, FollowSettings settings);
} // namespace ddx
