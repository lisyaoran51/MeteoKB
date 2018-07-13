#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <fstream>
#include <vector>
#include "../../../Util/TemplateConstraint.h"
#include "../../../Util/MtoType.h"



using namespace std;
using namespace Util;

namespace Base {
namespace Schedulers {
namespace Events {
	
	enum class EventStartType;

	class Event
	{

	public:

		Event();
		Event(MTO_FLOAT s, MTO_FLOAT l);
		Event(const Event&);

		int SetStartTime(MTO_FLOAT s);
		int SetLifeTime(MTO_FLOAT l);
		MTO_FLOAT GetStartTime() const;
		MTO_FLOAT GetLifeTime() const;

		bool operator<(const Event &rhs) const;

		// 一定要每次都override!!
		virtual string GetTypeName();

		template<typename T, typename U>
		static bool CanCast(U* e);

		template<typename T>
		bool CanCast();

		template<typename T>
		static T* Cast();

		virtual Event* Clone();

	protected:

		int eid;

		EventStartType startType;

		/// <summary>
		/// 開始時間，如果式即時事件就是-1
		/// </summary>
		MTO_FLOAT startTime;

		/// <summary>
		/// 結束時間 如果是瞬間事件，就是0，如果是由訊號通知開關，就是-1
		/// </summary>
		MTO_FLOAT lifeTime;

		Event(const Event*);
	};

	enum class EventStartType {
		Immediate,
		Reserved
	};

	

}}}



#endif