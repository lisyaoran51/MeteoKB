#include "MeteorPatternGenerator.h"

#include "../../../Util/MtoType.h"
#include "../../../Base/Scheduler/Event/ControlPoints/NoteControlPoint.h"
#include "../../Scheduler/Event/Effect/FallEffect.h"
#include "../../Scheduler/Event/Effect/GlowLineEffect.h"


using namespace Meteor::Sheetmusics::Patterns;
using namespace Meteor::Config;
using namespace Base::Schedulers::Events::ControlPoints;
using namespace Meteor::Schedulers::Events::Effects;



int MeteorPatternGenerator::load()
{
	MeteorConfigManager * f = GetCache<MeteorConfigManager>("MeteorConfigManager");
	return load(f);
}

int MeteorPatternGenerator::load(MeteorConfigManager * mcf)
{
	// TODO: throw error
	if( mcf->Get<MTO_FLOAT>(MeteorSetting::FallSpeed, &fallSpeed));
	if( mcf->Get<MTO_FLOAT>(MeteorSetting::FallBrightness, &fallBrightness));
	if( mcf->Get<MTO_FLOAT>(MeteorSetting::ExplodeSpeed, &explodeSpeed));
	if( mcf->Get<MTO_FLOAT>(MeteorSetting::ExplodeBrightness, &explodeBrightness));
	if( mcf->Get<MTO_FLOAT>(MeteorSetting::GlowLineSpeed, &glowLineSpeed));
	if( mcf->Get<MTO_FLOAT>(MeteorSetting::GlowLineDuration, &glowLineDuration));
	if( mcf->Get<MTO_FLOAT>(MeteorSetting::GlowLineBrightness, &glowLineBrightness));

	return 0;
}

MeteorPatternGenerator::MeteorPatternGenerator(): RegisterType("MeteorPatternGenerator")
{
	registerLoad(bind(static_cast<int(MeteorPatternGenerator::*)(void)>(&MeteorPatternGenerator::load), this));
}

Pattern* MeteorPatternGenerator::Generate(vector<Event*>* es, Event * e)
{
	// 在pattern generator消滅實消滅，或是converter跑完消滅
	Pattern* pattern = new Pattern();

	// 所有的event都要複製一個新的來用，才不會動到原本讀好的譜
	NoteControlPoint* note = (NoteControlPoint*)e->Cast<NoteControlPoint>()->Clone();
	Pitch pitch = note->GetPitch();

	// 公式： (鍵盤高度-打擊點高度) / 速度
	MTO_FLOAT fallTime = MTO_FLOAT(
		note->IsWhiteKey() ?
		(height - targetHeight) : (blackKeyHeight - blackKeyTargetHeight)
	) / fallSpeed;

	MTO_FLOAT glowLineTime = fallTime + MTO_FLOAT(1) / glowLineSpeed + glowLineDuration;

	MTO_FLOAT noteLifeTime = MTO_FLOAT(
		note->IsWhiteKey() ?
		(targetHeight) : (blackKeyTargetHeight)
	) / glowLineSpeed;

	GlowLineEffect* glow = new GlowLineEffect(
		(int)pitch, 
		0, 
		e->GetStartTime() - glowLineTime, 
		fallTime + glowLineDuration,
		glowLineSpeed);

	FallEffect* fall = new FallEffect(
		(int)pitch, 
		0, 
		e->GetStartTime() - fallTime,
		0,
		fallSpeed);

	note->SetLifeTime(noteLifeTime);

	pattern->Add(glow);
	pattern->Add(fall);
	pattern->Add(note);

	// 把pattern裡面的event一個一個加進去es裡
	es->push_back(glow);
	es->push_back(fall);
	es->push_back(note);

	return pattern;

}