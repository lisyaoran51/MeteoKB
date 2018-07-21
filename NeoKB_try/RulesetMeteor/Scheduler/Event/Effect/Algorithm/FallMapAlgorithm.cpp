#include "FallMapAlgorithm.h"



using namespace Meteor::Schedulers::Events::Effects::Algorithms; 
using namespace Meteor::Schedulers::Events::Effects;
using namespace Base::Schedulers::Events::Effects;



FallMapAlgorithm::FallMapAlgorithm(): RegisterType("FallMapAlgorithm"), MapAlgorithm()
{
	genAlgo = new FallMapGenerateAlgorithm();
	shiftAlgo = new MapShiftAlgorithm<FallEffect>();
	constructed = false;
}

int FallMapAlgorithm::LazyConstruct(int w, int h)
{
	MapAlgorithm<FallEffect>::LazyConstruct(w, h);
	constructed = true;
	return 0;
}

FallMapAlgorithm::FallMapAlgorithm(int w, int h) : RegisterType("FallMapAlgorithm"), MapAlgorithm(w, h)
{
	genAlgo = new FallMapGenerateAlgorithm();
	shiftAlgo = new MapShiftAlgorithm<FallEffect>();
	constructed = true;
}

int FallMapGenerateAlgorithm::ImplementGenerate(Map * m, EffectMapper<FallEffect>* em)
{

	LOG(LogLevel::Finest) << "FallMapGenerateAlgorithm::ImplementGenerate() : Generate Effect [" << em->GetStartTime() << "] on [" << em->GetCurrentTime() << "].";

	MTO_FLOAT currentTime = em->GetCurrentTime();
	// MTO_FLOAT lifeTime = em->GetLifeTime();
	MTO_FLOAT speed = em->GetSpeed();

	int width = em->GetWidth();
	int height = em->GetHeight();

	LOG(LogLevel::Finest) << [](int width, int height, Map* m) {
		LOG(LogLevel::Finest) << "FallMapGenerateAlgorithm::ImplementGenerate : light map - before";
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

	// 目前流星位置：height - speed * currentTime 
	MTO_FLOAT meteorPos = height - speed * currentTime;
	// 公式: -256*y + 256 
	// 算流星燈每一個燈泡的亮度，從下面網上算
	for (int i = 0; i < height; i++) {

		// TODO: 應該把流星長度變成參數
		if (i > meteorPos && i < meteorPos + 8.0) {

			int brightness = -BRIGHTNESS_MAX * (MTO_FLOAT(i) - meteorPos) / 8.0 + BRIGHTNESS_MAX;
			LOG(LogLevel::Finest) << "FallMapGenerateAlgorithm::ImplementGenerate : bright_max: " << BRIGHTNESS_MAX << ", MtoPos: " << meteorPos << ", i: " << i << ", bright: " << brightness;
			if (brightness > 0)
				m->Add(width, height + i, brightness);
		}
	}
	LOG(LogLevel::Finest) << [](int width, int height, Map* m) {
		LOG(LogLevel::Finest) << "FallMapGenerateAlgorithm::ImplementGenerate : light map - after";
		// 因為只看畫面中央，所以不看其他排
		for (int i = 0; i < width*2; i++) {
			string s;
			for (int j = 0; j < height*2; j++) {
				s += to_string(m->Get(i, j));
				s += " ";
			}
			LOG(LogLevel::Finest) << "| " << s << "|";
		}
		return 0;
	}(width, height, m);

	return 0;
}
