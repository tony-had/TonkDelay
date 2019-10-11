/*
  ==============================================================================

	Delay.cpp
	Created: 7 Oct 2019 7:35:28pm
	Author:  tonyh

  ==============================================================================
*/

#include "Delay.h"

Delay::Delay() :
	sampleRate(-1),
	delayTimeSmoothed(0.f),
	delayWriteHead(0)
{
	circularBuffer.resize(circularBufferSize, 0.f);
	std::fill(circularBuffer.begin(), circularBuffer.end(), 0.f);
}

Delay::~Delay()
{
}

void Delay::setSampleRate(double inputSampleRate)
{
	sampleRate = inputSampleRate;
}

void Delay::reset()
{
	delayTimeSmoothed = 0.f;
	std::fill(circularBuffer.begin(), circularBuffer.end(), 0.f);
}


void Delay::process(float* inBuffer, float delayTime, float feedback, float dryWetMix, float* outBuffer, int numberOfSamplesToProcess)
{
	const float wet = dryWetMix;
	const float dry = 1.f - dryWetMix;

	for (int i = 0; i < numberOfSamplesToProcess; i++)
	{
		delayTimeSmoothed = delayTimeSmoothed - 0.002 * (delayTimeSmoothed - delayTime);
		const double delayTimeInSamples = delayTimeSmoothed * sampleRate;

		// get the delayed sample
		const double delayedSample = getInterpolatedSample(delayTimeInSamples);

		// feed back the delayed sample into the circular buffer
		circularBuffer[delayWriteHead] = inBuffer[i] + (delayedSample * feedback);

		// move the write head
		delayWriteHead++;
		if (delayWriteHead >= circularBufferSize)
			delayWriteHead -= circularBufferSize;

		// fill the output buffer
		outBuffer[i] = (inBuffer[i] * dry) + (delayedSample * wet);
	}
}

double Delay::getInterpolatedSample(float delayTimeInSamples)
{
	double readPosition = delayWriteHead - delayTimeInSamples;
	if (readPosition < 0)
		readPosition += circularBufferSize;
	
	// readPosition may be a non-integer
	// calculate two adjacent whole number indexes
	int index0 = (int)readPosition;
	int index1 = index0 + 1;
	if (index1 >= circularBufferSize)
		index1 -= circularBufferSize;

	const float sample0 = circularBuffer[index0];
	const float sample1 = circularBuffer[index1];
	const float readPositionFraction = readPosition - (int)readPosition;

	// use linear interpolation
	const double interpolatedSample = (1.f - readPositionFraction) * sample0 + readPositionFraction * sample1;

	return interpolatedSample;
}

