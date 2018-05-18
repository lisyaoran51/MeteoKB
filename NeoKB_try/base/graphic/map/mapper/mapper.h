#ifndef MAPPER_H
#define MAPPER_H


#include "../../../scheduler/event/event_processor.h"
#include "../../../scheduler/event/effect/effect.h"

using namespace base::scheduler::event;
using namespace base::scheduler::event::effect;

namespace base {
namespace graphic {
namespace map {
namespace mapper {

	template<class T>
	class mapper_t : public event_processor_t<effect_t>, private T_constraint_t<effect_t> {

		/// <summary>
		/// make a constraint for template
		/// </summary>
		void constraint_check() {
			constraint_check_derived_from<T>();
		}

	public:

		mapper_t(int w, int h);

		/// <summary>
		/// after registering the map to mapper, the mapper can apply effect to map.
		/// </summary>
		int register_map(map_t* m);

	protected:

		map_t* map;

		/// <summary>
		/// to transform the effect to the map with every parameter relevant.
		/// </summary>
		virtual int map_algo() = 0;

	};


}}}}




#endif