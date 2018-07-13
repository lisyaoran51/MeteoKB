#include "ExplodeEffect.h"

using namespace Meteor::Schedulers::Events::Effects;
using namespace std;

ExplodeEffect::ExplodeEffect(int xPos, int yPos, MTO_FLOAT sTime, MTO_FLOAT l, MTO_FLOAT sp): Effect(xPos, yPos, sTime, l)
{
	SetSpeed(sp);
}

string ExplodeEffect::GetTypeName()
{
	return "ExplodeEffect";
}
