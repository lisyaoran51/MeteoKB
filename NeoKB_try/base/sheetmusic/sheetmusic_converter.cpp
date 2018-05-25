#include "sheetmusic_converter.h"


using namespace std;
using namespace Util;
using namespace base::sheetmusic;


/// <summary>
/// 在遊戲開始前附智一個新的sm，然後把裡面的特效events全部重新轉換一次
/// We always operate on a clone of the original sm, to not modify it game-wide
///	</summary>
sm_t<event_t>* sm_converter_t::convert(sm_t<event_t>* s)
{
	sm_t<event_t>* sm = new sm_t<event_t>(s);

	vector<event_t*>* original_events = sm->get_events();

	vector<event_t*>* new_events = new vector<event_t*>();

	for (int i = 0; i < original_events->size(); i++) {
		
		vector<event_t*>* temp_events = convert_event(original_events->at(i), s);

		for (int j = 0; j < temp_events->size(); j++) {
			new_events->push_back( temp_events->at(j) );
		}
		delete temp_events;
	}

	sm->set_events(new_events);

	return sm;
}
