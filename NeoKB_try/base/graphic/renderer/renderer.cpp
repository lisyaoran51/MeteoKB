#include "renderer.h"
#include "../../../Util/InstanceCreator.h"
#include "../../../Util/MtoObject.h"



using namespace Base::Graphic::Renderers;
using namespace Util;
using namespace Drivers;


bool Renderer::initialize()
{
	for (int i = 0; i < sizeof(hwInfo) / sizeof(hwInfo[0]); i++) {
		renderers[hwInfo[i].HwVersion] = hwInfo[i].Renderer;
	}
	return true;;
}

int Renderer::RegisterHWMapAlgo(HardwareMapAlgo * hwma)
{
	hwMapAlgo = hwma;
	return 0;
}

int Renderer::RegisterLedDriver(LedDriver * ld)
{
	ledDriver = ld;
	return 0;
}

int Renderer::load()
{
	return 0;
}

Renderer::Renderer(): RegisterType("Renderer")
{
	initialized;
}

int Renderer::SetHardwareVersion(int hwVersion)
{
	hardwareVersion = hwVersion;
	return 0;
}

int Renderer::RegisterMap(Map * m)
{
	map = m;
	return 0;
}


Renderer * Renderer::GetRenderer(int hwVersion)
{
	string rendererName = renderers[hwVersion];

	InstanceCreator<MtoObject> &iCreator = InstanceCreator<MtoObject>::GetInstance();

	Renderer* renderer = iCreator.CreateInstanceWithT<Renderer>(rendererName);
	
	// TODO: 查看有沒有這個renderer，沒有要丟錯誤

	renderer->SetHardwareVersion(hwVersion);

	return renderer;
}

int Renderer::Render()
{
	return 0;
}

int Renderer::SendToDriver()
{
	return 0;
}
