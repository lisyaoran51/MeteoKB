#ifndef MTO_CLOCK_H
#define MTO_CLOCK_H

#include MtoType.h


namespace Util {

	class MtoClock : public MtoObject {

	public:

		virtual MTO_FLOAT GetTime()=0;

	};

}





#endif