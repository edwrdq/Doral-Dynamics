#include "ddx/driveCurve.hpp"
#include <algorithm>
#include <cmath>

namespace ddx {

static inline int clamp127(int v) { return std::max(-127, std::min(127, v)); }

int ExpoDriveCurve::operator()(int input) const {
    // deadband
    if (input == 0) return 0;
    int s = (input < 0) ? -1 : 1;
    int a = std::abs(input);
    if (a <= m_deadband) return 0;

    // re-scale to [0,127]
    const float range = 127.0f - static_cast<float>(m_deadband);
    float x = (static_cast<float>(a - m_deadband) / range); // [0,1]

    // exponential curve
    float expo = (m_exponent <= 0.0f) ? x : std::pow(x, m_exponent);

    // ensure a minimum output when outside deadband
    float out = static_cast<float>(m_minOutput) + (127.0f - static_cast<float>(m_minOutput)) * expo;
    int result = s * static_cast<int>(std::round(out));
    return clamp127(result);
}

// Sensible default: mild deadband/min output and moderate expo
ExpoDriveCurve defaultDriveCurve(5, 12, 2.2f);

} // namespace ddx

