#include "Scheduler.h"

#include "../../Util/Log.h"


using namespace Base::Schedulers;
using namespace Util;




int Scheduler::load()
{
	Updater* u = GetCache<Updater>("Updater");
	if (!u)
		throw runtime_error("int EventProcessorMaster::load() : Updater not found in cache.");
	return load(u);
}

int Scheduler::load(Updater * u)
{
	Log(LogLevel::LogINFO) << "Scheduler::load(Updater*) : 將schedule任務註冊至updater";

	u->RegisterTask(bind((int(Scheduler::*)(MTO_FLOAT))&Scheduler::Elapse, this, placeholders::_1));
	return 0;
}

Scheduler::Scheduler(): RegisterType("Scheduler"), ChildAddable()
{
	registerLoad(bind((int(Scheduler::*)())&Scheduler::load, this));
	eventProcessors = new vector<EventProcessor<Event>*>();
}

Scheduler::~Scheduler()
{
	delete eventProcessors;
}

int Scheduler::Add(EventProcessor<Event> * ep)
{
	eventProcessors->push_back(ep);

	return 0;
}

int Scheduler::AddRange(vector<EventProcessor<Event>*>* eps)
{
	for (int i = 0; i < eps->size(); i++) {
		Add(eps->at(i));
	}
	return 0;
}

int Scheduler::RegisterHandler(function<int(EventProcessor<Event>*)> dh)
{
	deliverHandler = dh;
	return 0;
}

int Scheduler::Elapse(MTO_FLOAT elapsedTime) {

	if (elapsedTime == -1) {
		// 遊戲還沒開始時事-1，之後變0代表遊戲開始
		currentTime = 0;
		return 0;
	}
	
	currentTime += elapsedTime;

	while (eventProcessors->back()->GetStartTime() < currentTime) {

		//TODO: 應該先把超過的時間給減回去，避免多扣life time
		deliverHandler(eventProcessors->back());
		eventProcessors->pop_back();
	}
}