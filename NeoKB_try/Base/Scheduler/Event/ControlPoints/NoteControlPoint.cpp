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

string NoteControlPoint::GetTypeName()
{
	return "NoteControlPoint";
}

Pitch NoteControlPoint::GetPitch()
{
	return pitch;
}

bool NoteControlPoint::IsWhiteKey()
{
	switch (int(pitch) % 12) {
	case 0:
	case 2:
	case 4:
	case 5:
	case 7:
	case 9:
	case 11:
		return true;
	case 1:
	case 3:
	case 6:
	case 8:
	case 10:
		return false;
	}
	return false;
}

Event* NoteControlPoint::Clone()
{
	LOG(LogLevel::Finer) << "TODELETE NoteControlPoint::Clone : start time: " << startTime;

	return new NoteControlPoint(pitch, startTime, lifeTime);
}
