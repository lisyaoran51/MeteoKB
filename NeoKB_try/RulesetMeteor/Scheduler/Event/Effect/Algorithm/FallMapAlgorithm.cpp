#include "FallMapAlgorithm.h"


using namespace Meteor::Schedulers::Events::Effects::Algorithms; 
using namespace Meteor::Schedulers::Events::Effects;

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

int FallMapGenerateAlgorithm::Generate(Map * m, EffectMapper<FallEffect>* em)
{
	MTO_FLOAT currentTime = em->GetCurrentTime();
	// MTO_FLOAT lifeTime = em->GetLifeTime();
	MTO_FLOAT speed = em->GetSpeed();

	int width = em->GetWidth();
	int height = em->GetHeight();
	// 目前流星位置：height - speed * currentTime 
	MTO_FLOAT meteorPos = height - speed * currentTime;
	// 公式: -268435456*y + 2147483647 
	// 算流星燈每一個燈泡的亮度，從下面網上算
	for (int i = 0; i < height * 2; i++) {
		
		// TODO: 應該把流星長度變成參數
		if (i > meteorPos && i < meteorPos + 8.0 ) {

			int brightness = -268435455 * (MTO_FLOAT(i) - meteorPos) + INT_MAX;
			if(brightness > 0)
				m->Add(width, height, brightness);
		}
	}
	return 0;
}
