#ifndef INSTANCE_CREATOR_H
#define INSTANCE_CREATOR_H

#include <string>
#include <map>
#include "Singleton.h"
#include <functional>


/*
* https://stackoverflow.com/questions/582331/is-there-a-way-to-instantiate-objects-from-a-string-holding-their-class-name
* instantiate a class with its name in string()發現有問題，是錯的
*
* https://stackoverflow.com/questions/9370749/c-singleton-class-inheritance-good-practice
* another design
*/

using namespace std;


namespace Util {

	/// <summary>
	/// instantiate a class with its name in string
	/// </summary>
	template<typename TBase>
	class InstanceCreator: public Singleton<InstanceCreator<TBase>> {
	
		typename map<string, function<TBase*(void)>> creators;

		template<typename T>
		T* create();

	public:

		InstanceCreator() = default;

		template<typename T>
		int RegisterType(string typeName);

		TBase* CreateInstance(string typeName);

		/// <summary>
		/// 回傳之前就自動先把形態轉回原本的形態
		/// TODO: 設計一個判斷轉型態有沒有成功的程式
		/// </summary>
		template<typename T>
		T* CreateInstanceWithT(string typeName);

	};


}


#endif