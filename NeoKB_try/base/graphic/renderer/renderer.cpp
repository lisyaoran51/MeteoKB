#include "renderer.h"
#include "../../../Util/InstanceCreator.h"
#include "../../../Util/MtoObject.h"



using namespace Base::Graphic::Renderer;
using namespace Util;



int Renderer::RegisterHWMapAlgo(HwMapAlgo * hwma)
{
	hwMapAlgo = hwma;
	return 0;
}

int Base::Graphic::Renderer::Renderer::RegisterMap(Map * m)
{
	map = m;
	return 0;
}

int Renderer::RegisterRenderer(string hwVersion, string rendererName)
{
	renderers[hwVersion] = rendererName;
	return 0;
}

Renderer * Base::Graphic::Renderer::Renderer::GetRenderer(string hwVersion)
{
	string rendererName = renderers[hwVersion];

	InstanceCreator<MtoObject>* iCreator = InstanceCreator<MtoObject>::GetInstance();

	Renderer* renderer = (Renderer*)iCreator->CreateInstance(rendererName);

	// TODO: 查看有沒有這個renderer，沒有要丟錯誤

	return renderer;
}

int Base::Graphic::Renderer::Renderer::Render()
{
	return 0;
}

int Base::Graphic::Renderer::Renderer::SendToDriver()
{
	return 0;
}
