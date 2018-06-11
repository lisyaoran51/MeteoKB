#include "Playfield.h"
#include "../Scheduler/Event/Effect/EffectMapper.h"


using namespace Base::Play;
using namespace Base::Schedulers::Events;
using namespace Base::Schedulers;
using namespace Base::Schedulers::Events::Effects;



int Playfield::load()
{
	Scheduler* s = GetCache<Scheduler>("Scheduler");
	if (!s)
		throw runtime_error("int Playfield::load() : Scheduler not found in cache.");

	EventProcessorMaster* e = GetCache<EventProcessorMaster>("EventProcessorMaster");
	if (!e)
		throw runtime_error("int Playfield::load() : EventProcessorMaster not found in cache.");

	FrameworkConfigManager* f = GetCache<FrameworkConfigManager>("FrameworkConfigManager");
	if (!f)
		throw runtime_error("int Playfield::load() : FrameworkConfigManager not found in cache.");

	return load(s, e, f);
}

int Playfield::load(Scheduler* s, EventProcessorMaster* e, FrameworkConfigManager* f) {
	scheduler = s;
	eventProcessorMaster = e;

	int hwVersion = f->Get<int>(FrameworkSetting::HardwareVersion);
	renderer = Renderer::GetRenderer(hwVersion);

	// 根據遊戲大小，建一個map
	int width = f->Get<int>(FrameworkSetting::Width);
	int height = f->Get<int>(FrameworkSetting::Height);
	map = new Map(width, height);

	eventProcessorMaster->RegisterMap(map);
	renderer->RegisterMap(map);

	scheduler->RegisterHandler(e->ReceiveEventProcessor);

}

Playfield::Playfield():RegisterType("Playfield")
{
	// functional裡面的bind不能對overloading問題
	// https://stackoverflow.com/questions/4159487/stdbind-overload-resolution
	registerLoad(bind((int(Playfield::*)())&Playfield::load, this));
}

int Playfield::Add(EventProcessor<Event> * ep)
{
	scheduler->Add(ep);

	// 這邊要判斷這個event是不是effect，式的話就把map加進去
	if (CanCast<EffectMapper<Effect>, EventProcessor<Event>>(ep)) {
		EffectMapper<Effect>* em = Cast<EffectMapper<Effect>, EventProcessor<Event>>(ep);
		em->RegisterMap(map);
	}

	return 0;
}
