#ifndef PLAYFIELD_H
#define PLAYFIELD_H


#include"../../Util/Update/updatable.h"
#include"../Scheduler/Event/Event.h"
#include"../Scheduler/Event/EventProcessor.h"
#include"../Scheduler/Event/EventProcessorMaster.h"
#include"../Scheduler/Scheduler.h"
#include "../../Util/Hierachal/ChildAddable.h"
#include "../Graphic/Renderer/renderer.h"



using namespace Util::Hierachal;
using namespace Util::Update;
using namespace Base::Schedulers::Events;
using namespace Base::Schedulers;
using namespace Base::Graphic::Renderers;

namespace Base {
namespace Play {

	/// <summary>
	/// when playfield start, it should connect Scheduler, master, renderer with updater.
	/// So that these objects could be updated on each frame.
	/// should they be connected in this class????
	/// </summary>
	class Playfield: public Updatable, public ChildAddable {

		int load();

		int load(Scheduler* s, EventProcessorMaster* e, FrameworkConfigManager* f);

	public:

		Playfield();

		virtual int OnJudgement(Event* judge_event, Judgement* j);

		/// <summary>
		/// add events to scheuler
		/// </summary>
		virtual int Add(EventProcessor<Event>* ep);

	protected:

		Scheduler* scheduler;

		EventProcessorMaster* eventProcessorMaster;

		Renderer* renderer;

		Map* map;
	};


}}











#endif