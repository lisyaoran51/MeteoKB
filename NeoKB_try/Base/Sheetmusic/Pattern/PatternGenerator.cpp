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
	if(fConfigManager->Get<int>(FrameworkSetting::Width, &width));
	if(fConfigManager->Get<int>(FrameworkSetting::Height, &height));
	if(fConfigManager->Get<int>(FrameworkSetting::TargetHeight, &targetHeight));
	if(fConfigManager->Get<int>(FrameworkSetting::BlackKeyHeight, &blackKeyHeight));
	if(fConfigManager->Get<int>(FrameworkSetting::BlackKeyTargetHeight, &blackKeyTargetHeight));
	if(fConfigManager->Get<int>(FrameworkSetting::StartPitch, (int*)&startPitch));
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
