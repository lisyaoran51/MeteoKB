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
/// �b�C���}�l�e�����@�ӷs��sm�A�M���̭����S��events�������s�ഫ�@��
/// We always operate on a clone of the original sm, to not modify it game-wide
///	</summary>
Sm<Event>* SmConverter::convert(Sm<Event>* s)
{
	Sm<Event>* sm = new Sm<Event>(s);

	// �qsmŪ�X�Ӫ�event
	vector<Event*>* original_events = sm->get_events();

	// �g�L�B�z�ഫ��event
	vector<Event*>* new_events = new vector<Event*>();

	// �ഫ���Ȧs��
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
	// �糧�ӳ�ª����СA�ͦ��U�دS�ġA�p���ܥ��B���U�B��L�S�ġC
	Pattern* newPattern = patternGenerator->Generate(es, e);
	patternGenerator->Add(newPattern);

	return 0;
}
