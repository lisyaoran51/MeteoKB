#ifndef METEOR_CONFIG_MANAGER_H
#define METEOR_CONFIG_MANAGER_H

#include"../../Base/Config/ConfigManager.h"

using namespace Util;
using namespace std;
using namespace Base::Config;


namespace Meteor {
namespace Config{

	enum class MeteorSetting;

	class MeteorConfigManager: public ConfigManager<MeteorSetting> {

	public:

		MeteorConfigManager();

		virtual ~MeteorConfigManager() = default;

	protected:

		int InitializeDefault();

	};


	enum class MeteorSetting {

		PatternGenerator,
		FallMapAlgorithm,
		ExplodeMapAlgorithm,
		GlowLineMapAlgorithm,

		//PitchCount,
		//TargetLineHeight,

		FallSpeed,				// �C�����ʴX��
		FallBrightness,
		FallLength,
		ExplodeSpeed,
		ExplodeBrightness,
		GlowLineSpeed,
		GlowLineDuration,
		GlowLineBrightness,



	};

}}



#endif