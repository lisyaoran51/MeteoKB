#ifndef CONTROL_POINT_H
#define CONTROL_POINT_H

#include"../Event.h"

using namespace Base::Schedulers::Events;

namespace Base {
namespace Schedulers {
namespace Events {
namespace ControlPoints {

	class ControlPoint : public Event {

	public:

		ControlPoint(MTO_FLOAT s, MTO_FLOAT l);

		virtual ControlPointType GetControlPointType() = 0;

	};

	enum class ControlPointType {
		ControlPointTypeNote,
		ControlPointTypeSound,
		ControlPointTypeEffect
	};

}}}}

#endif