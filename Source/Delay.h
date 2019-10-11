/*
  ==============================================================================

	Delay.h
	Created: 7 Oct 2019 7:35:28pm
	Author:  tonyh

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "DelayParameters.h"

class Delay
{
public:
	Delay();
	~Delay();

	void reset();
	void setSampleRate(double inputSampleRate);
	void process(float* inBuffer, float delayTime, float feedback, float dryWetMix, float* outBuffer, int numberOfSamplesToProcess);

private:
	double sampleRate;
	float delayTimeSmoothed;
	int delayWriteHead;
	std::vector<double> circularBuffer;

	double getInterpolatedSample(float delayTimeInSamples);
};