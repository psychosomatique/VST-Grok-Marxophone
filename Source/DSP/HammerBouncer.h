#pragma once
#include <JuceHeader.h>

class HammerBouncer
{
public:
    void prepare(double sampleRate);
    void noteOn(float velocity, float baseRateHz);
    void noteOff();
    void setParameters(float rateHz, float randomness, float decayFactor);
    void setPressureMod(float mod);

    std::pair<double, bool> process();
    bool isActive() const { return isGated && energy > 0.001; }

private:
    double sampleRate = 44100.0;
    double phase = 0.0;
    double phaseInc = 0.0;
    double energy = 0.0;
    double randomness = 0.35;
    double decayPerBounce = 0.96;
    double pressureMod = 1.0;
    bool isGated = false;
    juce::Random rng;
    int samplesSinceBounce = 0;
    int minSamplesBetweenBounces = 0;
};