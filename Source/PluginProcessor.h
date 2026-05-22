#pragma once
#include <JuceHeader.h>
#include "DSP/MarxophoneVoice.h"
#include "DSP/SamplePool.h"

class MarxophoneProcessor : public juce::AudioProcessor,
                            private juce::ValueTree::Listener
{
public:
    MarxophoneProcessor();
    ~MarxophoneProcessor() override;

    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override { return true; }

    const juce::String getName() const override { return "Marxophone"; }
    bool acceptsMidi() const override { return true; }
    bool producesMidi() const override { return false; }
    double getTailLengthSeconds() const override { return 8.0; }

    int getNumPrograms() override { return 1; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram(int) override {}
    const juce::String getProgramName(int) override { return {}; }
    void changeProgramName(int, const juce::String&) override {}

    void getStateInformation(juce::MemoryBlock&) override;
    void setStateInformation(const void*, int) override;

    juce::AudioProcessorValueTreeState apvts;
    juce::Synthesiser synth;

private:
    SamplePool samplePool;
    juce::dsp::Gain<double> outputGain;
    juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout() const;
    void valueTreePropertyChanged(juce::ValueTree&, const juce::Identifier&) override {}
};