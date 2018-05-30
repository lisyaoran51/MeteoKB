#include"MeteorSheetmusicConverter.h"

using namespace Meteor::Sheetmusic;


int MeteorSmConverter::convert_event(vector<Event*>* es, Event* e, Sm<Event>* s)
{
	// 如果在讀檔的時候就是處理好的檔案，就直接付智一個然後回傳
	if (e->IsBaseOf<MeteorEffect>()) {
		MeteorEffect* me = new MeteorEffect(me);
		es->push_back(me);
		return 0;
	}

	// 對本來單純的樂譜，生成各種特效，如提示光、落下、其他特效。
	Pattern* newPattern = patternGenerator->Generate(es, e);
	patternGenerator->Add(newPattern);

	return 0;
}
