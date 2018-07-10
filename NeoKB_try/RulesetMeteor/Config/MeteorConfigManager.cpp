#include "MeteorConfigManager.h"


using namespace Meteor::Config;
using namespace Base::Config;


int MeteorConfigManager::InitializeDefault()
{
	Set(MeteorSetting::PatternGenerator, "MeteorPatternGenerator");
	Set(MeteorSetting::FallMapAlgorithm, "FallMapAlgorithm");
	Set(MeteorSetting::ExplodeMapAlgorithm, "ExplodeMapAlgorithm");
	Set(MeteorSetting::GlowLineMapAlgorithm, "GlowLineMapAlgorithm");

	Set(MeteorSetting::FallSpeed, 16.f);
	Set(MeteorSetting::FallBrightness, 1.f);
	Set(MeteorSetting::ExplodeSpeed, 16.f);
	Set(MeteorSetting::FallBrightness, 1.f);
	Set(MeteorSetting::GlowLineSpeed, 1.f);
	Set(MeteorSetting::GlowLineBrightness, 1.f);
	Set(MeteorSetting::GlowLineDuration, 1.f);
	return 0;
}
