#ifndef PLAYFIELD_H
#define PLAYFIELD_H


#include"../scheduler/updatable.h"
#include"../scheduler/event/event.h"

using namespace base::scheduler;
using namespace base::scheduler::event;

namespace base {
namespace play {

	class playfield_t: updatable_t {

		vector<event_t*>* events;

	public:

		int judgement_handler(event_t* judge_event, judgement_t* j);

	protected:


	};

}}











#endif