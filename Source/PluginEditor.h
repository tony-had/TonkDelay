/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class TonkDelayAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    TonkDelayAudioProcessorEditor (TonkDelayAudioProcessor&);
    ~TonkDelayAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    TonkDelayAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TonkDelayAudioProcessorEditor)
};
