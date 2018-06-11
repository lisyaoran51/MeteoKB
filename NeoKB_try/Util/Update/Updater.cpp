#include "Updater.h"

using namespace Util::Update;

int Updater::RegisterTask(MTO_FUNC_POINTER t)
{
	tasks.push_back(t);

	return 0;
}

void Updater::Update()
{
	vector<MTO_FUNC_POINTER>::iterator begin = tasks.begin();
	vector<MTO_FUNC_POINTER>::iterator end = tasks.end();
	vector<MTO_FUNC_POINTER>::iterator it;
	for (it = begin; it != end; it++) {
		(*it)();
	}
}
