#include "TargetLineMapAlgorithm.h"

#include <math.h>



using namespace Meteor::Schedulers::Events::Effects::Algorithms;


/***
	TargetLineMapAlgorithm
***/

int TargetLineMapAlgorithm::load()
{
	LOG(LogLevel::Info) << "TargetLineMapAlgorithm::load() : Start loading config.";

	shiftAlgo = new MapShiftAlgorithm<TargetLineEffect>(0);


	MeteorConfigManager* m = GetCache<MeteorConfigManager>("MeteorConfigManager");

	if (!m)
		throw runtime_error("int MeteorPlayfield::load() : MeteorConfigManager not found in cache.");


	return load(m);
}

int TargetLineMapAlgorithm::load(MeteorConfigManager * m)
{
	if (m->Get(MeteorSetting::TargetLineBlinkSpeed, &blinkSpeed)) {}

	genAlgo = new TargetLineMapGenerateAlgorithm(m);

	return 0;
}



TargetLineMapAlgorithm::TargetLineMapAlgorithm() : RegisterType("FallMapAlgorithm"), MapAlgorithm()
{
	registerLoad(bind((int(TargetLineMapAlgorithm::*)())&TargetLineMapAlgorithm::load, this));
}





/***
	TargetLineMapGenerateAlgorithm
***/

bool TargetLineMapGenerateAlgorithm::isWhiteKey(int key)
{
	switch (key % 12) {
	case 0:
	case 2:
	case 4:
	case 5:
	case 7:
	case 9:
	case 11:
		return true;
	case 1:
	case 3:
	case 6:
	case 8:
	case 10:
		return false;
	}
	return false;
}

TargetLineMapGenerateAlgorithm::TargetLineMapGenerateAlgorithm(MeteorConfigManager * m)
{
	if (m->Get(MeteorSetting::TargetLineBlinkSpeed, &blinkSpeed)) {}
	if (m->Get(MeteorSetting::TargetLineBrightness, &targetLineBrightness)) {}
	if (m->Get(MeteorSetting::WhiteKeyTargetHeight, &whiteKeyTargetLineHeight)) {}
	if (m->Get(MeteorSetting::BlackKeyTargetHeight, &blackKeyTargetLineHeight)) {}
	
	blinkInterval = 1.f / blinkSpeed;
}

int TargetLineMapGenerateAlgorithm::ImplementGenerate(Map * m, EffectMapper<TargetLineEffect>* em)
{

	LOG(LogLevel::Depricated) << "TargetLineMapGenerateAlgorithm::ImplementGenerate() : Generate Effect [" << em->GetStartTime() << "] on [" << em->GetCurrentTime() << "].";

	MTO_FLOAT currentTime = em->GetCurrentTime();
	// MTO_FLOAT lifeTime = em->GetLifeTime();
	MTO_FLOAT speed = em->GetSpeed();

	int width = em->GetWidth();
	int height = em->GetHeight();

	/* Log原本畫面 */
	LOG(LogLevel::Depricated) << [](int width, int height, Map* m) {
		LOG(LogLevel::Finest) << "TargetLineMapGenerateAlgorithm::ImplementGenerate : light map - before";
		// 因為只看畫面中央，所以不看其他排
		for (int i = 0; i < width * 2; i++) {
			string s;
			for (int j = 0; j < height * 2; j++) {
				s += to_string(m->Get(i, j));
				s += " ";
			}
			LOG(LogLevel::Finest) << "| " << s << "|";
		}
		return 0;
	}(width, height, m);


	/* 畫上打擊線 */
	MTO_FLOAT blinkTime = currentTime * blinkSpeed - floor(currentTime * blinkSpeed);

	/* 如果時間是在閃爍區段的前半段，就漸亮，如果是在後半段，就漸暗 */
	int brightness = blinkTime < 0.5f ? 
		blinkTime		  * 2.f * targetLineBrightness * BRIGHTNESS_MAX :
		(1.f - blinkTime) * 2.f * targetLineBrightness * BRIGHTNESS_MAX;

	for (int i = 0; i < width; i++) {
		if(isWhiteKey(i))
			m->Add(i, whiteKeyTargetLineHeight, brightness);
		else
			m->Add(i, blackKeyTargetLineHeight, brightness);
	}

	/* Log完成畫面 */
	LOG(LogLevel::Finest) << [](int width, int height, Map* m) {
		LOG(LogLevel::Finest) << "FallMapGenerateAlgorithm::ImplementGenerate : light map - after";
		// 因為只看畫面中央，所以不看其他排
		for (int i = 0; i < width * 2; i++) {
			string s;
			for (int j = 0; j < height * 2; j++) {
				s += to_string(m->Get(i, j));
				s += " ";
			}
			LOG(LogLevel::Finest) << "| " << s << "|";
		}
		return 0;
	}(width, height, m);

	return 0;
}
