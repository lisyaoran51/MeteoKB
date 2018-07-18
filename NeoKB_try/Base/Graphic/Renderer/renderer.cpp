#include "renderer.h"
#include "../../../Util/InstanceCreator.h"
#include "../../../Util/MtoObject.h"
#include "../../../Util/Log.h"




using namespace Base::Graphic::Renderers;
using namespace Util;
using namespace Devices;
using namespace std;


map<int, string> Renderer::renderers = {};
bool Renderer::initialized = Renderer::initialize();

bool Renderer::initialize()
{
	//TODO: �令Ū��� ���n�g�bcode��
	for (int i = 0; i < sizeof(hwInfo) / sizeof(hwInfo[0]); i++) {
		renderers[hwInfo[i].HwVersion] = hwInfo[i].Renderer;
	}
	return true;;
}

/*
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
*/

int Renderer::load()
{
	Updater* u = GetCache<Updater>("Updater");
	if (!u)
		throw runtime_error("int EventProcessorMaster::load() : Updater not found in cache.");

	FrameworkConfigManager * f = GetCache<FrameworkConfigManager>("FrameworkConfigManager");
	if (!f)
		throw runtime_error("int EventProcessorMaster::load() : FrameworkConfigManager not found in cache.");

	return load(u, f);
}

int Renderer::load(Updater * u, FrameworkConfigManager* f)
{
	Log(LogLevel::LogINFO) << "Renderer::load(Updater*, FrameworkConfigManager*) : �Nrender���ȵ��U��updater";

	u->RegisterTask(bind((int(Renderer::*)(MTO_FLOAT))&Renderer::Elapse, this, placeholders::_1));

	if (!f->Get(FrameworkSetting::FrameRate, &frameRate))
		throw runtime_error("int Renderer::load(Updater*, FrameworkConfigManager*) : FrameRate not found in Setting.");

	frameLength = MTO_FLOAT(1) / frameRate;
	currentFrameLength = 0;

	return 0;
}

Renderer::Renderer(): RegisterType("Renderer"), ChildAddable()
{
	registerLoad(bind((int(Renderer::*)())&Renderer::load, this));
	initialized;
}

int Renderer::SetHardwareVersion(int hwVersion)
{
	hardwareVersion = hwVersion;
	return 0;
}

int Renderer::RegisterMap(Map * m)
{
	lightMap = m;
	return 0;
}


Renderer * Renderer::GetRenderer(int hwVersion)
{
	string rendererName = renderers[hwVersion];

	InstanceCreator<MtoObject> &iCreator = InstanceCreator<MtoObject>::GetInstance();

	Renderer* renderer = iCreator.CreateInstanceWithT<Renderer>(rendererName);
	
	// TODO: �d�ݦ��S���o��renderer�A�S���n����~

	renderer->SetHardwareVersion(hwVersion);

	Log(LogLevel::LogINFO) << "Renderer::GetRenderer : �w�骩���� " << hwVersion << " �A���oRenderer�O���� " << rendererName;

	return renderer;
}

int Renderer::Elapse(MTO_FLOAT elapsedTime)
{
	if (elapsedTime == -1) {
		// �C���٨S�}�l�ɨ�-1�A������0�N��C���}�l
		currentTime = 0;
		return 0;
	}

	// �p�G�ɶ��W�L�nrender�Ϫ��P���ɶ��A�N�}�lrender��
	currentFrameLength += elapsedTime;
	if (currentFrameLength > frameLength) {
		currentFrameLength -= frameLength;
		Render();
		SendToDriver();
	}

	return 0;
}
