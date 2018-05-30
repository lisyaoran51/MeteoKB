#include"MeteorSheetmusicConverter.h"

using namespace Meteor::Sheetmusic;


int MeteorSmConverter::convert_event(vector<Event*>* es, Event* e, Sm<Event>* s)
{
	// �p�G�bŪ�ɪ��ɭԴN�O�B�z�n���ɮסA�N�����I���@�ӵM��^��
	if (e->IsBaseOf<MeteorEffect>()) {
		MeteorEffect* me = new MeteorEffect(me);
		es->push_back(me);
		return 0;
	}

	// �糧�ӳ�ª����СA�ͦ��U�دS�ġA�p���ܥ��B���U�B��L�S�ġC
	Pattern* newPattern = patternGenerator->Generate(es, e);
	patternGenerator->Add(newPattern);

	return 0;
}
