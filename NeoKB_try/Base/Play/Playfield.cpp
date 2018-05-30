#include "playfield.h"
#include "Playfield.h"



using namespace Base::Play;



int Playfield::load()
{
	Scheduler* s = GetCache<Scheduler>("Scheduler");
	if (!s)
		throw runtime_error("int Playfield::load() : Scheduler not found in cache.");

	EventProcessorMaster* e = GetCache<EventProcessorMaster>("EventProcessorMaster");
	if (!e)
		throw runtime_error("int Playfield::load() : EventProcessorMaster not found in cache.");

	Renderer* r = GetCache<Renderer>("Renderer");
	if (!r)
		throw runtime_error("int Playfield::load() : Renderer not found in cache.");

	return load(s, e, r);
}

int Playfield::load(Scheduler* s, EventProcessorMaster* e, Renderer* r) {
	scheduler = s;
	eventProcessorMaster = e;
	renderer = r;

	scheduler->RegisterHandler(e->ReceiveEventProcessor);

}

int Playfield::Add(EventProcessor * ep)
{
	scheduler->Add(ep);
	return 0;
}
