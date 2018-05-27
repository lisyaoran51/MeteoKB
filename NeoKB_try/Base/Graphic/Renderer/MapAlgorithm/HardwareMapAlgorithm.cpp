#include "HardwareMapAlgorithm.h"

using namespace Base::Graphic::Renderer::MapAlgorithm;


int HardwareMapAlgo::setCompatibleHwVersion()
{
	return 0;
}

HardwareMapAlgo::HardwareMapAlgo()
{
	setCompatibleHwVersion();
}

int HardwareMapAlgo::RegisterMap(Map * m)
{
	map = m;
	return 0;
}

int HardwareMapAlgo::CheckHardwareVersion()
{
	return 0;
}
