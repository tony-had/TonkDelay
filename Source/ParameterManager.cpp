/*
  ==============================================================================

	ParameterManager.cpp
	Created: 7 Oct 2019 7:35:46pm
	Author:  tonyh

  ==============================================================================
*/

#include "ParameterManager.h"

ParameterManager::ParameterManager(AudioProcessor& p) :
	valueTreeState(p,
		nullptr,
		"TONKDelay",
		createParameterLayout())
{
}

ParameterManager::~ParameterManager()
{
}

AudioProcessorValueTreeState::ParameterLayout ParameterManager::createParameterLayout()
{
	AudioProcessorValueTreeState::ParameterLayout parameterLayout;

	// Add float parameters
	for (int i = 0; i < totalNumFloatParameters; i++)
	{
		parameterLayout.add(std::make_unique<AudioParameterFloat>(delayFloatParameters[i].parameterId,
			delayFloatParameters[i].parameterName,
			delayFloatParameters[i].normalisableRange,
			delayFloatParameters[i].defaultValue,
			delayFloatParameters[i].parameterLabel));
	}

	return parameterLayout;
}
