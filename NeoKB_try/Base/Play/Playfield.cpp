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

	// �ھڹC���j�p�A�ؤ@��map
	int width = f->Get<int>(FrameworkSetting::Width);
	int height = f->Get<int>(FrameworkSetting::Height);
	map = new Map(width, height);

	eventProcessorMaster->RegisterMap(map);
	renderer->RegisterMap(map);

	scheduler->RegisterHandler(e->ReceiveEventProcessor);

}

Playfield::Playfield():RegisterType("Playfield")
{
	// functional�̭���bind�����overloading���D
	// https://stackoverflow.com/questions/4159487/stdbind-overload-resolution
	registerLoad(bind((int(Playfield::*)())&Playfield::load, this));
}

int Playfield::Add(EventProcessor<Event> * ep)
{
	scheduler->Add(ep);

	// �o��n�P�_�o��event�O���Oeffect�A�����ܴN��map�[�i�h
	if (CanCast<EffectMapper<Effect>, EventProcessor<Event>>(ep)) {
		EffectMapper<Effect>* em = Cast<EffectMapper<Effect>, EventProcessor<Event>>(ep);
		em->RegisterMap(map);
	}

	return 0;
}
