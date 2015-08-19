/*
  PluginEditor.h - This file is part of Roboverb

  Roboverb: robotic voice and ambience audio effect
  Copyright (C) 2015  Kushview, LLC.  All rights reserved.

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "JuceHeader.h"
#include "PluginProcessor.h"

class PluginView;

class RoboverbAudioProcessorEditor  : public AudioProcessorEditor,
                                      private Timer
{
public:
    RoboverbAudioProcessorEditor (RoboverbAudioProcessor&);
    ~RoboverbAudioProcessorEditor();

    void paint (Graphics&) override;
    void resized() override;

private:
    LookAndFeel_V3 lookAndFeel;
    RoboverbAudioProcessor& processor;
    ScopedPointer<PluginView> view;

    friend class Timer;
    void timerCallback() override;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RoboverbAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED