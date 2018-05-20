#ifndef UPDATABLE_H
#define UPDATABLE_H


#include <vector>
#include "../../util/mto_type.h"

using namespace std;


namespace base {
namespace scheduler {

	/// <summary>
	/// every class inherit form this has a function to update. we register update() to the updater. updater will call update().
	/// <summary>
	class updatable_t {

	public:

		virtual int elapse(MTO_FLOAT elapsed_time) = 0;

	protected:

		MTO_FLOAT current_time;

	};

}}

#endif