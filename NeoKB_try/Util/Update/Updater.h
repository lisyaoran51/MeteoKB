#ifndef UPDATABLE_H
#define UPDATABLE_H


#include <vector>
#include"../MtoType.h"

using namespace std;


namespace Util {
namespace Update {

	/// <summary>
	/// to update current time for every object who need to update.
	/// <summary>
	class Updater {

		vector<MTO_FUNC_POINTER> tasks;

	public:

		int RegisterTask(MTO_FUNC_POINTER t);

		// int RemoveTask(MTO_FUNC_POINTER t);

		void Update();
	};

}}

#endif