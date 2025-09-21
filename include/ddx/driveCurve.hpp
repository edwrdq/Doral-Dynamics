#pragma once

namespace ddx {

// Abstract drive curve interface
class DriveCurve {
    public:
        virtual ~DriveCurve() = default;
        // Map an input in [-127, 127] to an output in [-127, 127]
        virtual int operator()(int input) const = 0;
};

// Exponential drive curve, parameters mirror typical LemLib stable usage.
class ExpoDriveCurve : public DriveCurve {
    public:
        // deadband out of 127, min output out of 127, exponent > 0
        constexpr ExpoDriveCurve(int deadband = 0, int minOutput = 0, float exponent = 1.0f)
            : m_deadband(deadband), m_minOutput(minOutput), m_exponent(exponent) {}

        // Declaration only; definition may be provided elsewhere.
        int operator()(int input) const override;

    private:
        int m_deadband;
        int m_minOutput;
        float m_exponent;
};

// Provided by implementation in consumers or separate object file in full distribution
extern ExpoDriveCurve defaultDriveCurve;

} // namespace ddx

