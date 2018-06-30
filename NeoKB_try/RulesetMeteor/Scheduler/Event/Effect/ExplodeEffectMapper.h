#ifndef EXPLODE_EFFECT_MAPPER_H
#define EXPLODE_EFFECT_MAPPER_H

#include "../../../../Base/Scheduler/Event/Effect/EffectMapper.h"


using namespace Base::Schedulers::Events::Effects;


namespace Meteor {
namespace Schedulers {
namespace Events {
namespace Effects {

	class ExplodeEffectMapper :public EffectMapper<ExplodeEffect> {

		ExplodeEffectMapper(int w, int h);

	};



}}}}





#endif