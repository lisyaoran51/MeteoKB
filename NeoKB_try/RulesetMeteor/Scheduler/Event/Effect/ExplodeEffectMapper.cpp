#include "ExplodeEffectMapper.h"



using namespace Meteor::Schedulers::Events::Effects;
using namespace std;


ExplodeEffectMapper::ExplodeEffectMapper(int w, int h) : EffectMapper<ExplodeEffect>(w, h)
{
}

string ExplodeEffectMapper::GetTypeName()
{
	return string("ExplodeEffectMapper");
}
