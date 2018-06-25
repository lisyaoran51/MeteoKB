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
	// �bpattern generator����������A�άOconverter�]������
	Pattern* pattern = new Pattern();

	// �Ҧ���event���n�ƻs�@�ӷs���ӥΡA�~���|�ʨ�쥻Ū�n����
	NoteControlPoint* note = (NoteControlPoint*)e->Cast<NoteControlPoint>()->Clone();
	Pitch pitch = note->GetPitch();

	// �����G (��L����-�����I����) / �t��
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

	// ��pattern�̭���event�@�Ӥ@�ӥ[�i�hes��
	es->push_back(glow);
	es->push_back(fall);
	es->push_back(note);

	return pattern;

}