#ifndef INSTANCE_CREATOR_H
#define INSTANCE_CREATOR_H

#include <string>
#include <map>
#include"singleton.h"


/*
* https://stackoverflow.com/questions/582331/is-there-a-way-to-instantiate-objects-from-a-string-holding-their-class-name
* instantiate a class with its name in string
*
*
*/


namespace Util {

	/// <summary>
	/// instantiate a class with its name in string
	/// </summary>
	template<class T_base>
	class instance_creator_t: public singleton_t<instance_creator_t<T_base>> {
	
		map<string, T_base*(*)()> derived_creators;

	public:

		int register_type(string type_name, T_base* type);

		T_base* create_instance(string type_name);

	};

}


#endif