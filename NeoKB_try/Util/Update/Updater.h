#ifndef UPDATABLE_H
#define UPDATABLE_H


#include <vector>

using namespace std;


namespace Base {
namespace Scheduler {

	/// <summary>
	/// to update current time for every object who need to update.
	/// <summary>
	class updater_t {

		vector<void*> tasks;

	public:

		int register_task(void* t);

		int remove_task(void* t);

		void update();
	};

}}

#endif