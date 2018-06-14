#include "SheetmusicConverter.h"


using namespace std;
using namespace Util;
using namespace Base::Sheetmusics;


int SmConverter::load()
{
	PatternGenerator* pg = GetCache<PatternGenerator>("PatternGenerator");

	if (!pg)
		throw runtime_error("int SmConverter::load() : PatternGenerator not found in cache.");

	return load(pg);
}

int SmConverter::load(PatternGenerator * pg)
{
	patternGenerator = pg;
	return 0;
}



/// <summary>
/// 在遊戲開始前附智一個新的sm，然後把裡面的特效events全部重新轉換一次
/// We always operate on a clone of the original sm, to not modify it game-wide
///	</summary>
Sm<Event>* SmConverter::Convert(Sm<Event>* s)
{
	Sm<Event>* sm = new Sm<Event>(s);

	// 從sm讀出來的event
	vector<Event*>* originalEvents = sm->GetEvents();

	// 經過處理轉換的event
	vector<Event*>* newEvents = new vector<Event*>();

	// 轉換中暫存用
	vector<Event*>* tempEvents = new  vector<Event*>();

	for (int i = 0; i < originalEvents->size(); i++) {
		
		convertEvent(tempEvents, originalEvents->at(i));

		for (int j = 0; j < tempEvents->size(); j++) {
			newEvents->push_back( tempEvents->at(j) );
		}
	}

	delete tempEvents;
	patternGenerator->CleanPatterns();

	sm->SetEvents(newEvents);

	return sm;
}

int SmConverter::convertEvent(vector<Event*>* es, Event * e)
{
	// 對本來單純的樂譜，生成各種特效，如提示光、落下、其他特效。
	Pattern* newPattern = patternGenerator->Generate(es, e);
	patternGenerator->Add(newPattern);

	return 0;
}
