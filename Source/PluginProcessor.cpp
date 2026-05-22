#include "PluginProcessor.h"
#include "PluginEditor.h"

MarxophoneProcessor::MarxophoneProcessor()
    : AudioProcessor(BusesProperties().withOutput("Output", juce::AudioChannelSet::stereo(), true)),
      apvts(*this, nullptr, "PARAMETERS", createParameterLayout())
{
    for (int i = 0; i < 32; ++i)
        synth.addVoice(new MarxophoneVoice(samplePool, apvts));
}

// ... full parameter layout and other methods as previously defined ...