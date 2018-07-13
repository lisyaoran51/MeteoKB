#include "Updatable.h"

using namespace Util::Update;


Updatable::Updatable()
{
	currentTime = -1;
}

MTO_FLOAT Updatable::GetCurrentTime()
{
	return currentTime;
}
