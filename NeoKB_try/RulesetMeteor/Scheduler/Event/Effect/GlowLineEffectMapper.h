#ifndef GLOW_LINE_EFFECT_MAPPER_H
#define GLOW_LINE_EFFECT_MAPPER_H

#include "../../../../Base/Scheduler/Event/Effect/EffectMapper.h"
#include "GlowLineEffect.h"


using namespace Base::Schedulers::Events::Effects;


namespace Meteor {
namespace Schedulers {
namespace Events {
namespace Effects {

	class GlowLineEffectMapper :public EffectMapper<GlowLineEffect> {

	public:

		GlowLineEffectMapper(int w, int h);

	};



}}}}





#endif