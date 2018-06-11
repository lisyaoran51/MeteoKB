#ifndef METEOR_CONFIG_MANAGER_H
#define METEOR_CONFIG_MANAGER_H

#include"../../Base/Config/ConfigManager.h"

using namespace Util;
using namespace std;


namespace Base {
namespace Config{

	class MeteorConfigManager: public ConfigManager<MeteorSetting> {

	protected:

		int InitializeDefault();

	};


	enum class MeteorSetting {

		PatternGenerator,
		FallMapAlgorithm,
		ExplodeMapAlgorithm,
		GlowLineMapAlgorithm,

		StartPitch,
		PitchCount,
		TargetLineHeight

	};

}}



#endif