#include "sheetmusic_converter.h"


using namespace std;
using namespace Util;
using namespace Base::sheetmusic;


/// <summary>
/// 在遊戲開始前附智一個新的sm，然後把裡面的特效events全部重新轉換一次
/// We always operate on a clone of the original sm, to not modify it game-wide
///	</summary>
sm_t<Event>* sm_converter_t::convert(sm_t<Event>* s)
{
	sm_t<Event>* sm = new sm_t<Event>(s);

	vector<Event*>* original_events = sm->get_events();

	vector<Event*>* new_events = new vector<Event*>();

	for (int i = 0; i < original_events->size(); i++) {
		
		vector<Event*>* temp_events = convert_event(original_events->at(i), s);

		for (int j = 0; j < temp_events->size(); j++) {
			new_events->push_back( temp_events->at(j) );
		}
		delete temp_events;
	}

	sm->set_events(new_events);

	return sm;
}
