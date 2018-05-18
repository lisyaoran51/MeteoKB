#ifndef INSTANCE_CREATOR_H
#define INSTANCE_CREATOR_H

#include <string>
#include <map>


/*
* https://stackoverflow.com/questions/582331/is-there-a-way-to-instantiate-objects-from-a-string-holding-their-class-name
* instantiate a class with its name in string
*
*
*/


namespace util {

	/// <summary>
	/// instantiate a class with its name in string
	/// </summary>
	template<class T_base>
	class instance_creator_t {
	
		map<string, T_base*(*)()> derived_creators;

	public:

		template<class T_derived>
		int register_type(string type_name);

		template<class T_derived>
		T_derived* create_instance(string type_name);

	};

}


#endif