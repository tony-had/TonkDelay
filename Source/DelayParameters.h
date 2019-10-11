/*
  ==============================================================================

	DelayParameters.h
	Created: 7 Oct 2019 7:35:56pm
	Author:  tonyh

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

enum TremoloFloatParametersEnum
{
	delayTimeParameter = 0,
	delayFeedbackParameter,
	delayMixParameter,
	totalNumFloatParameters
};

struct DelayFloatParameter
{
	String parameterId;
	String parameterName;
	NormalisableRange<float> normalisableRange;
	float defaultValue;
	String parameterLabel;
};

constexpr float delayTimeMax = 2.f;
// TODO: move circularBufferSize to a new file - e.g. audio helpers or somesuch
constexpr int circularBufferSize = delayTimeMax * 192000 + 1; //arbitrarily 192 000 is the largest sample rate this plugin will suppport

static DelayFloatParameter delayFloatParameters[totalNumFloatParameters] =
{
	{"DelayTime", "Delay Time", NormalisableRange<float>(0.f, delayTimeMax), 1.f, "s"},
	{"Feedback", "Feedback", NormalisableRange<float>(0.f, 1.f), 0.5f, ""},
	{"Mix", "Mix", NormalisableRange<float>(0.f, 1.f), 0.5f, ""}
};

