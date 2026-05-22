cmake_minimum_required(VERSION 3.24)
project(Marxophone VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

find_package(JUCE CONFIG REQUIRED)

juce_add_plugin(Marxophone
    COMPANY_NAME "RareTone"
    PLUGIN_MANUFACTURER_CODE Rtne
    PLUGIN_CODE Mrxp
    FORMATS VST3 AU Standalone
    PRODUCT_NAME "Marxophone"
    IS_SYNTH TRUE
    NEEDS_MIDI_INPUT TRUE
)

target_sources(Marxophone PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp
    # Add all DSP and UI files here
)

target_link_libraries(Marxophone PRIVATE
    MarxophoneData
    juce::juce_audio_basics
    juce::juce_dsp
)