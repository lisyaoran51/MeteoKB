#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <fstream>
#include <vector>
#include "../../Util/TemplateConstraint.h"
#include "../../Util/MtoType.h"



using namespace std;
using namespace Util;

namespace Base {
namespace Schedulers {
namespace Events {
	

	class Event
	{

	public:

		Event(MTO_FLOAT s, MTO_FLOAT l);

		MTO_FLOAT GetStartTime();
		MTO_FLOAT GetLifeTime();

	protected:

		int eid;

		EventStartType start_type;

		/// <summary>
		/// 開始時間，如果式即時事件就是-1
		/// </summary>
		MTO_FLOAT startTime;

		/// <summary>
		/// 結束時間 如果是瞬間事件，就是0，如果是由訊號通知開關，就是-1
		/// </summary>
		MTO_FLOAT lifeTime;

	};

	enum EventStartType {
		Immediate,
		Reserved
	};

	

}}}



#endif