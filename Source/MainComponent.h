#pragma once

#include "../DspHelpers/DspHelpers.hpp"
#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::AudioAppComponent
                      
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    static constexpr int outputs = 2;
    
    // You need one DSP algorithm for each channel of audio
    tap::SynthWave<float>  synthWave1[outputs];
    tap::SynthWave<float>  synthWave2[outputs];
    tap::Tremolo<float>    tremolo   [outputs];
    tap::Distortion<float> distortion[outputs];
    
    tap::Amplitude<float> meter;
    tap::Panner<float> panner;
    
    juce::Slider slider;
    std::atomic<float> sliderValue { 0.0 };
        
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
