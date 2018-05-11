#pragma once
#include "ofMain.h"
#include "Models.h"
#include "MidiSender.h"
#include "ChannelInfo.h"

class ScoreManager {
public:
	void setup(UCHAR beat, UCHAR barCount, UCHAR pitchCount);
	void loadJson(const string& file) {}

	// for sequencer IF
	void bang(UCHAR barNum, UCHAR beatNum);

	// for UI IF: CRUD
	// return id
	void setBar(UCHAR bar) { currentBar = bar; }
	void setChan(UCHAR ch) { currentChan = ch; }
	void setCurrent(UCHAR bar, UCHAR ch);
	int create(const NoteModel& note);
	NoteModel& get(int id);
	std::unordered_map<int, NoteModel>& get();
	int update(int id, const NoteModel& note);
	void remove(int id);
	
	void drawChannelInfo();

	// setter & getter
	UCHAR getBeat() const { return beat; }
	UCHAR getBarCount() const { return barCount; }
	UCHAR getChannelCount() const { return channelCount; }

	static UCHAR beat;
	static UCHAR barCount;
	static UCHAR channelCount;
	static UCHAR pitchCount;

private:
	std::pair<UCHAR, UCHAR> calcEnd(UCHAR startBeat, UCHAR startBar, UCHAR duration) const;

	UCHAR currentBar;
	UCHAR currentChan;

	// bar:     4 bars
	// channel: 16 instruments
	vector<vector<BarModel>> midis;
	
	// bar:     4 bars
	// channel: 16 instruments
	// (id, note)
	vector<vector<std::unordered_map<int, NoteModel>>> notes;

	vector<ChannelInfo> chanInfos;

	MidiSender sender;

};