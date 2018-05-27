#ifndef PLAYFIELD_H
#define PLAYFIELD_H


#include"../../Util/Hierachal/updatable.h"
#include"../Scheduler/Event/Event.h"
#include"../Scheduler/Event/EventProcessorMaster.h"
#include"../Scheduler/Scheduler.h"



using namespace Util::Hierachal;
using namespace Base::Scheduler::Event;
using namespace Base::Scheduler;


namespace Base {
namespace Play {

	/// <summary>
	/// when playfield start, it should connect Scheduler, master, renderer with updater.
	/// So that these objects could be updated on each frame.
	/// should they be connected in this class????
	/// </summary>
	class Playfield: Updatable {

		int privateLoad(int argc, char** argv);

	public:

		virtual int on_judgement(Event* judge_event, judgement_t* j);

		/// <summary>
		/// add events to scheuler
		/// </summary>
		virtual int Add(EventProcessor* ep);

	protected:

		Scheduler* scheduler;

		EventProcessorMaster* event_process_master;

		Renderer* renderer;

	};

}}











#endif