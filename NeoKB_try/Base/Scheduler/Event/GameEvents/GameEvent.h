#ifndef GAME_EVENT_H
#define GAME_EVENT_H

#include"../Event.h"

using namespace Base::Schedulers::Events;

namespace Base {
namespace Schedulers {
namespace Events {
namespace GameEvents {

	enum class GameEventsType;

	class GameEvent : public Event {

	public:

		GameEvent(MTO_FLOAT s, MTO_FLOAT l);

		virtual GameEventsType GetGameEventsType() = 0;

		// 一定要每次都override!!
		virtual string GetTypeName();

	};

	enum class GameEventsType {
		Start,
		Pause,
		Resume,
		End,
		Stop
	};

}}}}







#endif