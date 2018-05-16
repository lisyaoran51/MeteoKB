#ifndef EVENT_BUILDER_H
#define EVENT_BUILDER_H


#include <string>
#include <fstream>
#include <vector>
#include "../../sheetmusic/sheetmusic.h"
#include "event.h"



using namespace std;
using namespace util;
using namespace base::sheetmusic;

namespace base {
namespace scheduler {
namespace event {

	class event_builder_t {

		sm_t<event_t>* sm;

	public:

		event_builder_t(sm_t<event_t>* s);

		vector<event_t*>* build();

	protected:

		sm_t<event_t>* get_sm();

	};

}}}


#endif