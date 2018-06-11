#include "Effect.h"


using namespace Base::Schedulers::Events::Effects;


Effect::Effect(int xPos, int yPos, MTO_FLOAT s, MTO_FLOAT l): Event(s,l)
{
	x = xPos;
	y = yPos;
	brightness = 1.0;
	speed = 1.0;
}

int Effect::SetBrightness(MTO_FLOAT b)
{
	brightness = b;
	return 0;
}

int Effect::SetSpeed(MTO_FLOAT s)
{
	speed = s;
	return 0;
}
