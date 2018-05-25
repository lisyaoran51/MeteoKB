#ifndef PLAYFIELD_H
#define PLAYFIELD_H


#include"../../Util/Hierachal/updatable.h"
#include"../scheduler/event/event.h"
#include"../scheduler/event/event_processor_master.h"
#include"../scheduler/scheduler.h"



using namespace Util::Hierachal;
using namespace base::scheduler::event;
using namespace base::scheduler;


namespace base {
namespace play {

	/// <summary>
	/// when playfield start, it should connect scheduler, master, renderer with updater.
	/// So that these objects could be updated on each frame.
	/// should they be connected in this class????
	/// </summary>
	class Playfield: Updatable {

		int privateLoad(int argc, char** argv);

	public:

		virtual int on_judgement(event_t* judge_event, judgement_t* j);

		/// <summary>
		/// add events to scheuler
		/// </summary>
		virtual int add(event_t*);



	protected:

		scheduler_t* scheduler;

		event_processor_master_t* event_process_master;

		renderer_t* renderer;

	};

}}











#endif