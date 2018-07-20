#include "Updater.h"

#include "../Log.h"

using namespace Util::Update;
using namespace std::chrono;
using namespace std;
using namespace Util;


void Updater::update(MTO_FLOAT elapsedTime)
{
	vector<function<int(MTO_FLOAT)>>::iterator begin = tasks.begin();
	vector<function<int(MTO_FLOAT)>>::iterator end = tasks.end();
	vector<function<int(MTO_FLOAT)>>::iterator it;
	for (it = begin; it != end; it++) {
		(*it)(elapsedTime);
	}
}

Updater::Updater(): MtoObject(), RegisterType("Updater")
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

		LOG(LogLevel::Finest) << "Updater::Update() : update frame - " << (currentTime - startTime).count();

		system_clock::time_point temp = system_clock::now();
		
		duration<double> difference = temp - currentTime;
		MTO_FLOAT elapsedTime = difference.count();

		currentTime = system_clock::now();

		LOG(LogLevel::Finest) << "Updater::Update() : elapse time - " << elapsedTime;

		update(elapsedTime);
		return;
	}
	else {

		LOG(LogLevel::Finest) << "Updater::Update() : Update start.";

		updateState = UpdateState::Started;
		currentTime = system_clock::now();
		startTime = currentTime;

		update(-1);
	}
}
