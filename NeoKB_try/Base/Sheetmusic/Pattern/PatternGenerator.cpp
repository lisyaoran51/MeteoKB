#include "PatternGenerator.h"


using namespace Base::Sheetmusics::Patterns;
using namespace std;




int PatternGenerator::load()
{
	FrameworkConfigManager * f = GetCache<FrameworkConfigManager>("FrameworkConfigManager");
	return load(f);
}

int PatternGenerator::load(FrameworkConfigManager * fConfigManager)
{
	width = fConfigManager->Get<int>(FrameworkSetting::Width);
	height = fConfigManager->Get<int>(FrameworkSetting::Height);
	startPitch = (Pitch)fConfigManager->Get<int>(FrameworkSetting::StartPitch);
	blackKeyHeight = fConfigManager->Get<int>(FrameworkSetting::BlackKeyHeight);

	return 0;
}

PatternGenerator::PatternGenerator()
{
	registerLoad(bind(static_cast<int(PatternGenerator::*)(void)>(&PatternGenerator::load), this));
}

PatternGenerator::~PatternGenerator()
{
	CleanPatterns();
}

int PatternGenerator::Add(Pattern * p)
{

	patterns.push_back(p);

	return 0;
}

int PatternGenerator::CleanPatterns()
{
	for (int i = 0; i < patterns.size(); i++) {
		delete patterns[i];
	}
	return 0;
}
