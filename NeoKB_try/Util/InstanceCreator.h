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
	template<typename TBase>
	class InstanceCreator: public singleton_t<InstanceCreator<TBase>> {
	
		int a;
		map<string, TBase*(*)()> creators;

		template<typename T>
		T* create();

	public:

		template<typename T>
		int RegisterType(string typeName);

		T_base* CreateInstance(string typeName);

		/// <summary>
		/// 回傳之前就自動先把形態轉回原本的形態
		/// TODO: 設計一個判斷轉型態有沒有成功的程式
		/// </summary>
		template<typename T>
		T* CreateInstance(string typeName);

	};


}


#endif