/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TonkDelayAudioProcessorEditor::TonkDelayAudioProcessorEditor (TonkDelayAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setSize (400, 300);
}

TonkDelayAudioProcessorEditor::~TonkDelayAudioProcessorEditor()
{
}

//==============================================================================
void TonkDelayAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void TonkDelayAudioProcessorEditor::resized()
{
}
