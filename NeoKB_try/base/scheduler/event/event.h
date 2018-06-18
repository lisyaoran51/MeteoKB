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
		Event(const Event&);

		MTO_FLOAT GetStartTime() const;
		MTO_FLOAT GetLifeTime() const;

		bool operator<(const Event &rhs) const;

		template<typename T, typename U>
		static bool CanCast(U* e);

		template<typename T, typename U>
		static T* Cast(U* e);

		virtual Event* Clone();

	protected:

		int eid;

		EventStartType start_type;

		/// <summary>
		/// �}�l�ɶ��A�p�G���Y�ɨƥ�N�O-1
		/// </summary>
		MTO_FLOAT startTime;

		/// <summary>
		/// �����ɶ� �p�G�O�����ƥ�A�N�O0�A�p�G�O�ѰT���q���}���A�N�O-1
		/// </summary>
		MTO_FLOAT lifeTime;

		Event(const Event*);
	};

	enum EventStartType {
		Immediate,
		Reserved
	};

	

}}}



#endif