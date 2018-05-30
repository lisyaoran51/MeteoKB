#include "SheetmusicConverter.h"


using namespace std;
using namespace Util;
using namespace Base::Sheetmusic;


int Base::Sheetmusic::SmConverter::load()
{
	PatternGenerator* pg = GetCache<PatternGenerator>("PatternGenerator");

	if (!pg)
		throw runtime_error("int MeteorSmConverter::load() : PatternGenerator not found in cache.");

	return load(pg);
}

int Base::Sheetmusic::SmConverter::load(PatternGenerator * pg)
{
	patternGenerator = pg;
	return 0;
}



/// <summary>
/// 在遊戲開始前附智一個新的sm，然後把裡面的特效events全部重新轉換一次
/// We always operate on a clone of the original sm, to not modify it game-wide
///	</summary>
Sm<Event>* SmConverter::convert(Sm<Event>* s)
{
	Sm<Event>* sm = new Sm<Event>(s);

	// 從sm讀出來的event
	vector<Event*>* original_events = sm->get_events();

	// 經過處理轉換的event
	vector<Event*>* new_events = new vector<Event*>();

	// 轉換中暫存用
	vector<Event*>* temp_events = new  vector<Event*>();

	for (int i = 0; i < original_events->size(); i++) {
		
		convert_event(temp_events, original_events->at(i), s);

		for (int j = 0; j < temp_events->size(); j++) {
			new_events->push_back( temp_events->at(j) );
		}
	}

	delete temp_events;
	patternGenerator->CleanPatterns();

	sm->set_events(new_events);

	return sm;
}

int Base::Sheetmusic::SmConverter::convert_event(vector<Event*>* es, Event * e, Sm<Event>* s)
{
	// 對本來單純的樂譜，生成各種特效，如提示光、落下、其他特效。
	Pattern* newPattern = patternGenerator->Generate(es, e);
	patternGenerator->Add(newPattern);

	return 0;
}
