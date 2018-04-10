/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.2.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <string>

//[/Headers]



//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginEditor::PluginEditor (TestPlugin1AudioProcessor& p)
	: AudioProcessorEditor(&p), processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
	startTimer(0, 1000 / dtFFTdata);
	startTimer(1, 1000 / dtSetFilters);
    //[/Constructor_pre]
	
	addAndMakeVisible (attackSlider = new Slider ("attackSlider"));
    attackSlider->setTooltip (TRANS("Setting the speed of the filter movement when basic frequency changes."));
    attackSlider->setRange (1, 30, 1);
    attackSlider->setSliderStyle (Slider::RotaryHorizontalDrag);
    attackSlider->setTextBoxStyle (Slider::TextBoxRight, false, 25, 20);
    attackSlider->setColour (Slider::rotarySliderFillColourId, Colours::white);
    attackSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    attackSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x002a2a2a));
    attackSlider->setColour (Slider::textBoxOutlineColourId, Colour (0xff5c5c5c));
    attackSlider->addListener (this);
	attackSlider->setValue(processor.attack);


    //[UserPreSize]
    //[/UserPreSize]

    setSize(400, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PluginEditor::~PluginEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    attackSlider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PluginEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff2b2b2b));

    g.setColour (Colours::white);
    g.setFont (Font ("Bebas Neue", 63.40f, Font::plain));
    g.drawText (TRANS("Synceq"),
                12, 12, 388, 52,
                Justification::centredLeft, true);

    g.setColour (Colour (0xff8e8e8e));
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("V:d0.1"),
                12, 60, 68, 12,
                Justification::topLeft, true);

    g.setColour (Colours::white);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("Attack"),
                28, 116, 200, 30,
                Justification::bottomLeft, true);

    g.setColour (Colours::white);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("Accuracy:"),
                180, 20, 84, 12,
                Justification::topLeft, true);

    g.setColour (Colours::white);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("LowEnd position:"),
                180, 68, 116, 12,
                Justification::topLeft, true);

    g.setColour (Colours::white);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("Basic frequency:"),
                180, 44, 124, 12,
                Justification::topLeft, true);

    g.setColour (Colours::white);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText ((String)processor.offset << " Hz" , // df
                308, 20, 84, 12,
                Justification::topLeft, true);

    g.setColour (Colours::white);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText ((String)processor.lowEnd << " Hz", //lowEnd
                308, 44, 84, 12,
                Justification::topLeft, true);

    g.setColour (Colours::white);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText ((String)processor.AVGF << " Hz", //AVGF
                308, 68, 84, 12,
                Justification::topLeft, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    attackSlider->setBounds (72, 104, 112, 72);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PluginEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == attackSlider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
		Slider* attackSliderP = attackSlider.get();
		int attackNewVal = (int) attackSliderP->getValue();
		processor.setAttack(attackNewVal);
        //[/UserSliderCode_slider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}


//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void PluginEditor::timerCallback(int id)
{
	switch (id)
	{
	case 0: {processor.makeFFTData();  break;}
	case 1: {repaint(); processor.smoothSetFilters(); break;}
	}
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginEditor" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="400" initialHeight="400">
  <BACKGROUND backgroundColour="ff2b2b2b">
    <TEXT pos="12 12 388 52" fill="solid: ffffffff" hasStroke="0" text="Synceq"
          fontname="Bebas Neue" fontsize="63.399999999999999" bold="0"
          italic="0" justification="33"/>
    <TEXT pos="12 60 68 12" fill="solid: ff8e8e8e" hasStroke="0" text="V:d0.1"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="9"/>
    <TEXT pos="28 116 200 30" fill="solid: ffffffff" hasStroke="0" text="Attack"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="17"/>
    <TEXT pos="180 20 84 12" fill="solid: ffffffff" hasStroke="0" text="Accuracy:"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="9"/>
    <TEXT pos="180 68 116 12" fill="solid: ffffffff" hasStroke="0" text="LowEnd position:"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="9"/>
    <TEXT pos="180 44 124 12" fill="solid: ffffffff" hasStroke="0" text="Basic frequency:"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="9"/>
    <TEXT pos="308 20 84 12" fill="solid: ffffffff" hasStroke="0" text="df"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="9"/>
    <TEXT pos="308 44 84 12" fill="solid: ffffffff" hasStroke="0" text="lowEnd"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="9"/>
    <TEXT pos="308 68 84 12" fill="solid: ffffffff" hasStroke="0" text="AVGF"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="9"/>
  </BACKGROUND>
  <SLIDER name="attackSlider" id="11f6748d093c1de" memberName="slider"
          virtualName="" explicitFocusOrder="0" pos="72 104 112 72" tooltip="Setting the speed of the filter movement when basic frequency changes."
          rotarysliderfill="ffffffff" textboxtext="ffffffff" textboxbkgd="2a2a2a"
          textboxoutline="ff5c5c5c" min="1" max="30" int="1" style="RotaryVerticalDrag"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="25"
          textBoxHeight="20" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
