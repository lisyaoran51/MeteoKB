#ifndef HAS_PARENT_H
#define HAS_PARENT_H


#include "../MtoObject.h"


using namespace Util;


namespace Util {
namespace Hierachal {

	/// <summary>
	/// has a parent object
	/// </summary>
	class HasParent: virtual public MtoObject {

		HasParent* parent;

	public:

		HasParent();

		bool hasParent();

		HasParent* GetParent();

		int SetParent(HasParent* p);

	};




}
}




#endif