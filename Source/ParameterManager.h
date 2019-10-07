/*
  ==============================================================================

	ParameterManager.h
	Created: 7 Oct 2019 7:35:46pm
	Author:  tonyh

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "DelayParameters.h"

class ParameterManager
{
public:
	ParameterManager(AudioProcessor&);
	~ParameterManager();

	AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

	AudioProcessorValueTreeState valueTreeState;
};