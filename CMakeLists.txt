# cmake_minimum_required(VERSION 3.24)
project(Marxophone VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(JUCE CONFIG REQUIRED)

juce_add_plugin(Marxophone
    COMPANY_NAME "RareTone"
    PLUGIN_MANUFACTURER_CODE "Rtne"
    PLUGIN_CODE "Mrxp"
    FORMATS VST3 AU Standalone
    PRODUCT_NAME "Marxophone"
    IS_SYNTH TRUE
    NEEDS_MIDI_INPUT TRUE
    COPY_PLUGIN_AFTER_BUILD TRUE
)

juce_add_binary_data(MarxophoneData
    SOURCES
        Resources/Images/wood_texture.png
        Resources/Images/hammer_sprite.png
)

target_sources(Marxophone PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp
    Source/DSP/MarxophoneVoice.cpp
    Source/DSP/HammerBouncer.cpp
    Source/DSP/KarplusString.cpp
    Source/DSP/ModalBody.cpp
    Source/DSP/SamplePool.cpp
    Source/UI/HammerAnimation.cpp
    Source/UI/CustomLookAndFeel.cpp
)

target_link_libraries(Marxophone PRIVATE
    MarxophoneData
    juce::juce_audio_basics
    juce::juce_audio_processors
    juce::juce_audio_formats
    juce::juce_dsp
    juce::juce_gui_basics
    juce::juce_gui_extra
)

target_compile_definitions(Marxophone PUBLIC
    JUCE_VST3_CAN_REPLACE_VST2=0
    JUCE_USE_CURL=0
    JUCE_WEB_BROWSER=0
)
