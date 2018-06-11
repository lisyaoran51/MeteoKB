#include "NoteControlPoint.h"

using namespace Base::Schedulers::Events::ControlPoints;


NoteControlPoint::NoteControlPoint(Pitch p, MTO_FLOAT s, MTO_FLOAT l): ControlPoint(s,l)
{
	pitch = p;
}

ControlPointType NoteControlPoint::GetControlPointType()
{
	return ControlPointType::ControlPointTypeNote;
}

Pitch NoteControlPoint::GetPitch()
{
	return pitch;
}
