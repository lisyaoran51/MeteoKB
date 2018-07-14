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
	// �p�G�bŪ�ɪ��ɭԴN�O�B�z�n���ɮסA�N�����I���@�ӵM��^��
	// ���p�G�O�h�������p�A�S��k�o�˽ƻs�A�n��clone
	if (e->CanCast<Effect>()) {
		Event* effect = e->Clone();
		es->push_back(effect);
		return 0;
	}

	if (e->CanCast<NoteControlPoint>()) {
		// �糧�ӳ�ª����СA�ͦ��U�دS�ġA�p���ܥ��B���U�B��L�S�ġC
		Pattern* newPattern = patternGenerator->Generate(es, e);
		patternGenerator->Add(newPattern);




	}


	

	return 0;
}
