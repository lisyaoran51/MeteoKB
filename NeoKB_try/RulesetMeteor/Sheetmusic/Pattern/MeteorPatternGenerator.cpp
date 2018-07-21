#include "MeteorPatternGenerator.h"

#include "../../../Util/MtoType.h"
#include "../../../Base/Scheduler/Event/ControlPoints/NoteControlPoint.h"
#include "../../Scheduler/Event/Effect/FallEffect.h"
#include "../../Scheduler/Event/Effect/GlowLineEffect.h"


using namespace Meteor::Sheetmusics::Patterns;
using namespace Meteor::Config;
using namespace Base::Schedulers::Events;
using namespace Base::Schedulers::Events::ControlPoints;
using namespace Meteor::Schedulers::Events::Effects;



int MeteorPatternGenerator::load()
{

	MeteorConfigManager * m = GetCache<MeteorConfigManager>("MeteorConfigManager");

	if (!m)
		throw runtime_error("int MeteorPatternGenerator::load() : MeteorConfigManager not found in cache.");

	return load(m);
}

int MeteorPatternGenerator::load(MeteorConfigManager * mcf)
{
	// TODO: throw error
	if( !mcf->Get(MeteorSetting::FallSpeed, &fallSpeed))
		throw runtime_error("int MeteorPatternGenerator::load(MeteorConfigManager*) : FallSpeed not found in Setting.");

	if( !mcf->Get(MeteorSetting::FallBrightness, &fallBrightness))
		throw runtime_error("int MeteorPatternGenerator::load(MeteorConfigManager*) : FallBrightness not found in Setting.");

	if (!mcf->Get(MeteorSetting::FallLength, &fallLength))
		throw runtime_error("int MeteorPatternGenerator::load(MeteorConfigManager*) : FallLength not found in Setting.");

	if( !mcf->Get(MeteorSetting::ExplodeSpeed, &explodeSpeed))
		throw runtime_error("int MeteorPatternGenerator::load(MeteorConfigManager*) : ExplodeSpeed not found in Setting.");

	if( !mcf->Get(MeteorSetting::ExplodeBrightness, &explodeBrightness))
		throw runtime_error("int MeteorPatternGenerator::load(MeteorConfigManager*) : ExplodeBrightness not found in Setting.");

	if( !mcf->Get(MeteorSetting::GlowLineSpeed, &glowLineSpeed))
		throw runtime_error("int MeteorPatternGenerator::load(MeteorConfigManager*) : GlowLineSpeed not found in Setting.");

	if( !mcf->Get(MeteorSetting::GlowLineDuration, &glowLineDuration))
		throw runtime_error("int MeteorPatternGenerator::load(MeteorConfigManager*) : GlowLineDuration not found in Setting.");

	if( !mcf->Get(MeteorSetting::GlowLineBrightness, &glowLineBrightness))
		throw runtime_error("int MeteorPatternGenerator::load(MeteorConfigManager*) : GlowLineBrightness not found in Setting.");

	return 0;
}

MeteorPatternGenerator::MeteorPatternGenerator(): PatternGenerator(), RegisterType("MeteorPatternGenerator")
{
	registerLoad(bind(static_cast<int(MeteorPatternGenerator::*)(void)>(&MeteorPatternGenerator::load), this));
}

Pattern* MeteorPatternGenerator::Generate(vector<Event*>* es, Event * e)
{
	// 在pattern generator消滅實消滅，或是converter跑完消滅
	Pattern* pattern = new Pattern();

	// 所有的event都要複製一個新的來用，才不會動到原本讀好的譜
	NoteControlPoint* note = e->Clone()->Cast<NoteControlPoint>();
	
	LOG(LogLevel::Finer) << "int MeteorSmConverter::Generate(vector<Event*>*, Event*) : Start converting [" << static_cast<int>(note->GetPitch()) << "," << note->GetStartTime() << "] to pattern...";

	if(!note)
		throw runtime_error("Pattern* MeteorPatternGenerator::Generate(vector<Event*>*, Event*) : event cannot cast to NoteControlPoint.");

	Pitch pitch = note->GetPitch();

	if (static_cast<int>(pitch) > static_cast<int>(startPitch) + width - 1 ||
		static_cast<int>(pitch) < static_cast<int>(startPitch)) {
		LOG(LogLevel::Warning) << "int MeteorSmConverter::Generate(vector<Event*>*, Event*) : Note [" << static_cast<int>(note->GetPitch()) << " is out of light map boundary.";
		return pattern;
	}


	// 公式： (鍵盤高度-打擊點高度) / 速度
	MTO_FLOAT fallTime = MTO_FLOAT(
		note->IsWhiteKey() ?
		(height - targetHeight) : (blackKeyHeight - blackKeyTargetHeight)
	) / fallSpeed;

	MTO_FLOAT fallLifeTime = MTO_FLOAT( 
		(note->IsWhiteKey() ?
		height : blackKeyHeight) + fallLength
		) / fallSpeed;

	MTO_FLOAT glowLineTime = fallTime + MTO_FLOAT(1) / glowLineSpeed + glowLineDuration;

	MTO_FLOAT noteLifeTime = MTO_FLOAT(
		note->IsWhiteKey() ?
		(targetHeight) : (blackKeyTargetHeight)
	) / glowLineSpeed;

	LOG(LogLevel::Finest) << "int MeteorSmConverter::Generate(vector<Event*>*, Event*) : Fall speed is [" << fallSpeed << "], GlowLine speed is [" << glowLineSpeed << "].";

	LOG(LogLevel::Finer) << "int MeteorSmConverter::Generate(vector<Event*>*, Event*) : Generate GlowLine at [" << (int)pitch << "], start time [" << e->GetStartTime() - glowLineTime << "], life time [" << fallTime + glowLineDuration << "].";

	GlowLineEffect* glow = new GlowLineEffect(
		(int)pitch, 
		0, 
		e->GetStartTime() - glowLineTime, 
		fallTime + glowLineDuration,
		glowLineSpeed);

	LOG(LogLevel::Finer) << "int MeteorSmConverter::Generate(vector<Event*>*, Event*) : Generate Fall at [" << (int)pitch << "], start time [" << e->GetStartTime() - fallTime << "], life time [" << fallLifeTime << "].";

	FallEffect* fall = new FallEffect(
		(int)pitch, 
		0, 
		e->GetStartTime() - fallTime,
		fallLifeTime,
		fallSpeed);

	note->SetLifeTime(noteLifeTime);

	pattern->Add(glow);
	pattern->Add(fall);
	//pattern->Add(note);

	// 把pattern裡面的event一個一個加進去es裡
	es->push_back(glow);
	es->push_back(fall);
	//es->push_back(note);

	return pattern;

}