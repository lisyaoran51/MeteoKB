#include"MeteorSheetmusicConverter.h"
#include "../../Base/Scheduler/Event/Effect/Effect.h"
#include "../../Base/Scheduler/Event/ControlPoints/NoteControlPoint.h"

using namespace Meteor::Sheetmusics;
using namespace Base::Schedulers::Events::Effects;
using namespace Base::Schedulers::Events::ControlPoints;




MeteorSmConverter::MeteorSmConverter(PatternGenerator * pg): SmConverter(pg)
{
}

int MeteorSmConverter::convertEvent(vector<Event*>* es, Event* e)
{
	// 如果在讀檔的時候就是處理好的檔案，就直接付智一個然後回傳
	// 但如果是多型的狀況，沒辦法這樣複製，要用clone
	if (Event::CanCast<Effect>(e)) {
		Event* effect = e->Clone();
		es->push_back(effect);
		return 0;
	}

	if (Event::CanCast<NoteControlPoint>(e)) {
		// 對本來單純的樂譜，生成各種特效，如提示光、落下、其他特效。
		Pattern* newPattern = patternGenerator->Generate(es, e);
		patternGenerator->Add(newPattern);




	}


	

	return 0;
}
