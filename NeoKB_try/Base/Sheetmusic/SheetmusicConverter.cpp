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
/// �b�C���}�l�e�����@�ӷs��sm�A�M���̭����S��events�������s�ഫ�@��
/// We always operate on a clone of the original sm, to not modify it game-wide
///	</summary>
Sm<Event>* SmConverter::Convert(Sm<Event>* s)
{
	Sm<Event>* sm = new Sm<Event>(s);

	// �qsmŪ�X�Ӫ�event
	vector<Event*>* originalEvents = sm->GetEvents();

	// �g�L�B�z�ഫ��event
	vector<Event*>* newEvents = new vector<Event*>();

	// �ഫ���Ȧs��
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
	// �糧�ӳ�ª����СA�ͦ��U�دS�ġA�p���ܥ��B���U�B��L�S�ġC
	Pattern* newPattern = patternGenerator->Generate(es, e);
	patternGenerator->Add(newPattern);

	return 0;
}
