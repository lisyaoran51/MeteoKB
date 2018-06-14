#include "Updater.h"

using namespace Util::Update;
using namespace std::chrono;
using namespace std;


void Updater::update(MTO_FLOAT elapsedTime)
{
	vector<function<int(MTO_FLOAT)>>::iterator begin = tasks.begin();
	vector<function<int(MTO_FLOAT)>>::iterator end = tasks.end();
	vector<function<int(MTO_FLOAT)>>::iterator it;
	for (it = begin; it != end; it++) {
		(*it)(elapsedTime);
	}
}

Updater::Updater()
{
	updateState = UpdateState::NotStarted;
}

int Updater::RegisterTask(function<int(MTO_FLOAT)> t)
{
	tasks.push_back(t);

	return 0;
}

void Updater::Update()
{
	if (updateState == UpdateState::Started) {
		chrono::system_clock::time_point temp = system_clock::now();
		
		chrono::duration<double> difference = temp - currentTime;
		MTO_FLOAT elapsedTime = difference.count();

		update(elapsedTime);
		return;
	}
	else {
		updateState = UpdateState::Started;
		currentTime = system_clock::now();

		update(-1);
	}
}
