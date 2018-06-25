#ifndef RENDERER_H
#define RENDERER_H

#include <map>
#include <string>
#include "../Map/Map.h"
#include "MapAlgorithm\HardwareMapAlgorithm.h"
#include "../../../Util/Hierachal/ChildAddable.h"
#include "../../Config/FrameworkConfigManager.h"
#include "../../../Drivers/HardwareInfo.h"
#include "../../../Drivers/LedDriver.h"
#include "../../../Util/Update/Updater.h"
#include "../../../Util/Update/Updatable.h"



using namespace std;
using namespace Base::Graphic::Maps;
using namespace Base::Graphic::Renderers::MapAlgorithms;
using namespace Util::Hierachal;
using namespace Base::Config;
using namespace Drivers;
using namespace Util::Update;


namespace Base {
namespace Graphic {
namespace Renderers {

	class Renderer : public Updatable,  public ChildAddable{

		int load();

		int load(Updater* u, FrameworkConfigManager* f);

		/// <summary>
		/// key:硬體版本 value:renderer名稱
		///	</summary>
		static map<int, string> renderers;

		static bool initialized;

		/// <summary>
		/// 建構子會自動執行這個函是，址會執行一次，把所有的renderer讀進這個renderer裡
		///	</summary>
		static bool initialize();


	public:

		Renderer();

		int SetHardwareVersion(int hwVersion);

		int RegisterMap(Map* m);

		static Renderer* GetRenderer(int hwVersion);

		virtual int Elapse(MTO_FLOAT elapsedTime);

		virtual int Render() = 0;

		virtual int SendToDriver() = 0;

	protected:

		/// <summary>
		/// 硬體版本，之後加入map algo和led driver應該都是根據這個
		///	</summary>
		int hardwareVersion;

		Map* map;

		HardwareMapAlgo* hwMapAlgo;

		LedDriver* ledDriver;

		/// <summary>
		/// 禎數、針長、目前所經過時間
		///	</summary>
		MTO_FLOAT frameRate, frameLength, currentFrameLength;


		/// <summary>
		/// HWMapAlgo應該是和renderer板本綁定
		///	</summary>
		int RegisterHWMapAlgo(HardwareMapAlgo* hwma);

		/// <summary>
		/// 應該也和版本綁定?
		///	</summary>
		int RegisterLedDriver(LedDriver* ld);
	};

	bool Renderer::initialized = Renderer::initialize();
	



}}}


#endif