#ifndef NOTE_CONTROL_POINT_H
#define NOTE_CONTROL_POINT_H

#include"ControlPoint.h"

namespace Base {
namespace Schedulers {
namespace Events {
namespace ControlPoints {

	class NoteControlPoint : public ControlPoint {

		Pitch pitch;

	public:

		NoteControlPoint(Pitch p, MTO_FLOAT s, MTO_FLOAT l);

		virtual ControlPointType GetControlPointType();

		Pitch GetPitch();

	};


}}}}





#endif