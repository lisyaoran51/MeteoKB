#include "MeteorPatternGenerator.h"

#include "../../../Util/MtoType.h"

using namespace Meteor::Sheetmusics::Patterns;
using namespace Meteor::Config;


int MeteorPatternGenerator::load()
{
	MeteorConfigManager * f = GetCache<MeteorConfigManager>("MeteorConfigManager");
	return load(f);
}

int MeteorPatternGenerator::load(MeteorConfigManager * mcf)
{
	fallSpeed			= mcf->Get<MTO_FLOAT>(MeteorSetting::FallSpeed);
	fallBrightness		= mcf->Get<MTO_FLOAT>(MeteorSetting::FallBrightness);
	explodeSpeed		= mcf->Get<MTO_FLOAT>(MeteorSetting::ExplodeSpeed);
	explodeBrightness	= mcf->Get<MTO_FLOAT>(MeteorSetting::ExplodeBrightness);
	glowLineSpeed		= mcf->Get<MTO_FLOAT>(MeteorSetting::GlowLineSpeed);
	glowLineDuration	= mcf->Get<MTO_FLOAT>(MeteorSetting::GlowLineDuration);
	glowLineBrightness	= mcf->Get<MTO_FLOAT>(MeteorSetting::GlowLineBrightness);

	return 0;
}

MeteorPatternGenerator::MeteorPatternGenerator(): RegisterType("MeteorPatternGenerator")
{
	registerLoad(bind(static_cast<int(MeteorPatternGenerator::*)(void)>(&MeteorPatternGenerator::load), this));
}

Pattern * MeteorPatternGenerator::Generate(vector<Event*> es, Event * e)
{
	// 在pattern generator消滅實消滅，或是converter跑完消滅
	Pattern* pattern = new Pattern();


	// TODO: 把pattern裡面的event一個一個加進去es裡

	return nullptr;
}
