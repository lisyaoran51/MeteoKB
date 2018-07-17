#include "Playfield.h"
#include "../Scheduler/Event/Effect/EffectMapper.h"
#include "../../Util/Log.h"
#include <functional>


using namespace Base::Play;
using namespace Base::Schedulers::Events;
using namespace Base::Schedulers;
using namespace Base::Schedulers::Events::Effects;
using namespace Util;
using namespace std;


/*
 * 用成員的函數擺進function裡
 * https://zh.cppreference.com/w/cpp/utility/functional/function
 */



int Playfield::load()
{
	Log(LogLevel::LogINFO) << "Playfield::load() : 開始載入遊戲場景";

	Scheduler* s = GetCache<Scheduler>("Scheduler");
	if (!s)
		throw runtime_error("int Playfield::load() : Scheduler not found in cache.");

	EventProcessorMaster* e = GetCache<EventProcessorMaster>("EventProcessorMaster");
	if (!e)
		throw runtime_error("int Playfield::load() : EventProcessorMaster not found in cache.");

	FrameworkConfigManager* f = GetCache<FrameworkConfigManager>("FrameworkConfigManager");
	if (!f)
		throw runtime_error("int Playfield::load() : FrameworkConfigManager not found in cache.");

	Updater* u = GetCache<Updater>("Updater");
	if (!u)
		throw runtime_error("int Playfield::load() : Updater not found in cache.");

	return load(s, e, f, u);
}

int Playfield::load(Scheduler* s, EventProcessorMaster* e, FrameworkConfigManager* f, Updater* u) {

	

	scheduler = s;
	eventProcessorMaster = e;
	updater = u;

	int hwVersion;
	if (f->Get(FrameworkSetting::HardwareVersion, &hwVersion)) {
		renderer = Renderer::GetRenderer(hwVersion);
	}
	else
		throw runtime_error("int Playfield::load() : HardwareVersion not found in Setting.");
	

	// 根據遊戲大小，建一個map
	if (f->Get(FrameworkSetting::Width, &width) &&
		f->Get(FrameworkSetting::Height, &height))
	{
		lightMap = new Map(width, height);
		bufferMap = new Map(width * 2, height * 2);
	}
	else
		throw runtime_error("int Playfield::load() : Width and Height not found in Setting.");
	

	eventProcessorMaster->RegisterMap(lightMap);
	renderer->RegisterMap(lightMap);
	scheduler->RegisterHandler(bind(&EventProcessorMaster::ReceiveEventProcessor, e, placeholders::_1));

	// 這一步是讓他們去抓updater
	AddChild(scheduler);
	AddChild(eventProcessorMaster);
	AddChild(renderer);

	// 最後也要把playfield加進updater裡，但是應該不能寫在這，要寫在繼承的class上
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

	// 這邊要把Map Algo加進去
	if (ep->CanCast<EffectMapper<Event>>()) {

		// 為什麼不用event自己來create? 因為要去搭配不同的mapper，所以要動態調配
		string processorType = ep->GetTypeName();

		MapAlgorithmInterface* mapAlgo = mapAlgorithms[processorType];
		if (mapAlgo)
			ep->Cast<EffectMapperInterface>()->RegisterMapAlgorithm(mapAlgo);

	}

	if (CanCast<EffectMapper<Effect>, EventProcessor<Event>>(ep)) {
		// 這邊要判斷這個event是不是effect，式的話就把map加進去
		EffectMapper<Effect>* em = Cast<EffectMapper<Effect>, EventProcessor<Event>>(ep);
		em->RegisterMap(lightMap);
	}

	return 0;
}

int Playfield::GetWidth()
{
	return width;
}

int Playfield::GetHeight()
{
	return height;
}
