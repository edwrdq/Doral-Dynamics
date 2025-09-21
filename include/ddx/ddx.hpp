#pragma once

#ifndef LEMLIB_NO_MACROS
#include "ddx/macros.hpp" // IWYU pragma: keep
#endif

#include "ddx/motions/follow.hpp" // IWYU pragma: keep
#include "ddx/motions/moveToPoint.hpp" // IWYU pragma: keep
#include "ddx/motions/moveToPose.hpp" // IWYU pragma: keep
#include "ddx/motions/turnTo.hpp" // IWYU pragma: keep
#include "ddx/tracking/TrackingWheelOdom.hpp" // IWYU pragma: keep
#include "ddx/MotionHandler.hpp" // IWYU pragma: keep

// Chassis high-level API (from stable)
#include "ddx/chassis/trackingWheel.hpp" // IWYU pragma: keep
#include "ddx/chassis/chassis.hpp" // IWYU pragma: keep
#include "ddx/chassis/odom.hpp" // IWYU pragma: keep

#ifndef LEMLIB_NO_ALIAS
namespace ll = ddx;
namespace mh = ddx::motion_handler;
#endif
