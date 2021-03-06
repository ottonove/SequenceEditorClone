#pragma once
#include "ofMain.h"
#include "ofxMidi.h"

class MidiSender {
public:
	MidiSender() {
		//midiOut.listPorts();
		/// LoopMidi = 1
		midiOut.openPort(0);
	}

	~MidiSender() {
		midiOut.closePort();
	}

	void sendMidiOn(unsigned char ch, unsigned char midiNum, unsigned char velocity) {
		ofLogNotice() << "ch: " << +ch << " note: " << +midiNum;;
		midiOut.sendNoteOn(ch, midiNum, velocity);
	}

	void sendMidiOff(unsigned char ch, unsigned char midiNum) {
		midiOut.sendNoteOff(ch, midiNum);
	}
	
private:
	ofxMidiOut midiOut;
};