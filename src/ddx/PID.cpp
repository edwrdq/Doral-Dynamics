#include "ddx/PID.hpp"
#include "pros/rtos.hpp"

namespace ddx {

using namespace units;

PID::PID(Number kP, Number kI, Number kD, Number windupRange, bool signFlipReset)
    : m_gains({kP, kI, kD}),
      m_windupRange(windupRange),
      m_signFlipReset(signFlipReset) {}

PID::PID(const Gains& gains, Number windupRange, bool signFlipReset)
    : m_gains(gains),
      m_windupRange(windupRange),
      m_signFlipReset(signFlipReset) {}

Gains PID::getGains() { return m_gains; }

void PID::setGains(ddx::Gains gains) { m_gains = gains; }

Number PID::update(Number error) {
    // find time delta
    const Time now = from_msec(pros::millis());
    // if this is the first iteration, previousTime won't be set
    // if it is not set, then assume dt is 0
    Time dt = (m_previousTime == std::nullopt) ? 0_msec : now - *m_previousTime;
    m_previousTime = now;

    // calculate the derivative (change in error / time passed)
    const Number derivative = (dt != 0_sec) ? (error - m_previousError) / to_sec(dt) : 0;
    m_previousError = error;

    // calculate the integral (change in error * time passed)
    m_integral += error * to_sec(dt);
    // sign flip reset. If the sign of error changes, set the integral to 0
    if (sgn(error) != sgn((m_previousError)) && m_signFlipReset) m_integral = 0;
    // anti windup range. Unless error is small enough, set the integral to 0
    if (abs(error) > m_windupRange && m_windupRange != 0) m_integral = 0;

    // output. error * kP + integral * kP + derivative * kD
    return error * m_gains.kP + m_integral * m_gains.kI + derivative * m_gains.kD;
}

void ddx::PID::reset() {
    m_previousError = 0;
    m_integral = 0;
}

void ddx::PID::setSignFlipReset(bool signFlipReset) { m_signFlipReset = signFlipReset; }

bool ddx::PID::getSignFlipReset() { return m_signFlipReset; }

void ddx::PID::setWindupRange(Number windupRange) { m_windupRange = windupRange; }

Number ddx::PID::getWindupRange() { return m_windupRange; }

} // namespace ddx
