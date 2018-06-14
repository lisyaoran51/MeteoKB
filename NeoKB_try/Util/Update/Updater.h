#ifndef UPDATER_H
#define UPDATER_H


#include <vector>
#include <chrono>
#include"../MtoType.h"

using namespace std::chrono;
using namespace std;



/*
 * 取得相差時間
 * http://zh.cppreference.com/w/cpp/chrono/system_clock/now
 */



namespace Util {
namespace Update {

	/// <summary>
	/// to update current time for every object who need to update.
	/// <summary>
	class Updater {

		time_point currentTime;

		vector<function<int(MTO_FLOAT)>> tasks;

		void update(MTO_FLOAT elapsedTime);

		UpdateState updateState;

	public:

		Updater();

		int RegisterTask(function<int(MTO_FLOAT)> t);

		// int RemoveTask(MTO_FUNC_POINTER t);

		void Update();
	};


	enum class UpdateState {

		NotStarted,
		Started,
		Paused,
		Stopped

	};


}}

#endif