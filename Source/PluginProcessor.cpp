/*
  ==============================================================================

	This file was auto-generated!

	It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TonkDelayAudioProcessor::TonkDelayAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
	: AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
		.withInput("Input", AudioChannelSet::stereo(), true)
#endif
		.withOutput("Output", AudioChannelSet::stereo(), true)
#endif
	),
#endif
	parameterManager(*this)
{
}

TonkDelayAudioProcessor::~TonkDelayAudioProcessor()
{
}

//==============================================================================
const String TonkDelayAudioProcessor::getName() const
{
	return JucePlugin_Name;
}

bool TonkDelayAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
	return true;
#else
	return false;
#endif
}

bool TonkDelayAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
	return true;
#else
	return false;
#endif
}

bool TonkDelayAudioProcessor::isMidiEffect() const
{
#if JucePlugin_IsMidiEffect
	return true;
#else
	return false;
#endif
}

double TonkDelayAudioProcessor::getTailLengthSeconds() const
{
	return 0.0;
}

int TonkDelayAudioProcessor::getNumPrograms()
{
	return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
				// so this should be at least 1, even if you're not really implementing programs.
}

int TonkDelayAudioProcessor::getCurrentProgram()
{
	return 0;
}

void TonkDelayAudioProcessor::setCurrentProgram(int index)
{
}

const String TonkDelayAudioProcessor::getProgramName(int index)
{
	return {};
}

void TonkDelayAudioProcessor::changeProgramName(int index, const String& newName)
{
}

//==============================================================================
void TonkDelayAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
}

void TonkDelayAudioProcessor::releaseResources()
{
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool TonkDelayAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
#if JucePlugin_IsMidiEffect
	ignoreUnused(layouts);
	return true;
#else
	if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
		&& layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
		return false;
#if ! JucePlugin_IsSynth
	if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
		return false;
#endif

	return true;
#endif
}
#endif

void TonkDelayAudioProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
	ScopedNoDenormals noDenormals;
	auto totalNumInputChannels = getTotalNumInputChannels();
	auto totalNumOutputChannels = getTotalNumOutputChannels();

	// In case we have more outputs than inputs, this code clears any output
	// channels that didn't contain input data, (because these aren't
	// guaranteed to be empty - they may contain garbage).
	// This is here to avoid people getting screaming feedback
	// when they first compile a plugin, but obviously you don't need to keep
	// this code if your algorithm always overwrites all the output channels.
	for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
		buffer.clear(i, 0, buffer.getNumSamples());

	// This is the place where you'd normally do the guts of your plugin's
	// audio processing...
	// Make sure to reset the state if your inner loop is processing
	// the samples and the outer loop is handling the channels.
	// Alternatively, you can process the samples with the channels
	// interleaved by keeping the same state.
	for (int channel = 0; channel < totalNumInputChannels; ++channel)
	{
		auto* channelData = buffer.getWritePointer(channel);

		// ..do something to the data...
	}
}

//==============================================================================
bool TonkDelayAudioProcessor::hasEditor() const
{
	return false;
}

AudioProcessorEditor* TonkDelayAudioProcessor::createEditor()
{
	return new TonkDelayAudioProcessorEditor(*this);
}

//==============================================================================
void TonkDelayAudioProcessor::getStateInformation(MemoryBlock& destData)
{
}

void TonkDelayAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
	return new TonkDelayAudioProcessor();
}
