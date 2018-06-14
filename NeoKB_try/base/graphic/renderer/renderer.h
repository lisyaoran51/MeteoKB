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



using namespace std;
using namespace Base::Graphic::Maps;
using namespace Base::Graphic::Renderers::MapAlgorithms;
using namespace Util::Hierachal;
using namespace Base::Config;
using namespace Drivers;


namespace Base {
namespace Graphic {
namespace Renderers {

	class Renderer: public ChildAddable {

		int load();

		/// <summary>
		/// key:�w�骩�� value:renderer�W��
		///	</summary>
		static map<int, string> renderers;

		static bool initialized;

		/// <summary>
		/// �غc�l�|�۰ʰ���o�Ө�O�A�}�|����@���A��Ҧ���rendererŪ�i�o��renderer��
		///	</summary>
		static bool initialize();


	public:

		Renderer();

		int SetHardwareVersion(int hwVersion);

		int RegisterMap(Map* m);

		static Renderer* GetRenderer(int hwVersion);

		virtual int Render() = 0;

		virtual int SendToDriver() = 0;

	protected:

		/// <summary>
		/// �w�骩���A����[�Jmap algo�Mled driver���ӳ��O�ھڳo��
		///	</summary>
		int hardwareVersion;

		Map* map;

		HardwareMapAlgo* hwMapAlgo;

		LedDriver* ledDriver;

		/// <summary>
		/// HWMapAlgo���ӬO�Mrenderer�O���j�w
		///	</summary>
		int RegisterHWMapAlgo(HardwareMapAlgo* hwma);

		/// <summary>
		/// ���Ӥ]�M�����j�w?
		///	</summary>
		int RegisterLedDriver(LedDriver* ld);
	};

	bool Renderer::initialized = Renderer::initialize();
	



}}}


#endif