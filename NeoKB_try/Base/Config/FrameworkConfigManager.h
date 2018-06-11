#ifndef FRAMEWORK_CONFIG_MANAGER_H
#define FRAMEWORK_CONFIG_MANAGER_H

#include"ConfigManager.h"

using namespace Util;
using namespace std;


namespace Base {
namespace Config{

	class FrameworkConfigManager: public ConfigManager<FrameworkSetting> {

	protected:

		int InitializeDefault();

	};


	enum class FrameworkSetting {

		AudioDevice,
		VolumeUniversal,
		VolumeEffect,
		VolumeMusic,

		Width,
		Height,
		BlackKeyHeight,

		FrameSync,

		CursorSensitivity,

		PatternGenerator,
		Renderer,
		HardwareMapAlgorithm,
		LedDriver,
		HardwareVersion

	};

}}



#endif