#include "FallEffect.h"

using namespace Meteor::Schedulers::Events::Effects;
using namespace std;

FallEffect::FallEffect(int xPos, int yPos, MTO_FLOAT sTime, MTO_FLOAT l, MTO_FLOAT sp): Effect(xPos, yPos, sTime, l)
{
	SetSpeed(sp);
}

string FallEffect::GetTypeName()
{
	return "FallEffect";
}
