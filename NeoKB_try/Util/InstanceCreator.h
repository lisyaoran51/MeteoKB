#ifndef INSTANCE_CREATOR_H
#define INSTANCE_CREATOR_H

#include <string>
#include <map>
#include "Singleton.h"
#include <functional>
#include "Log.h"


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
	
		typedef function<TBase*(void)> MtoFunc;
		//typename function<TBase*(void)> aaaa;

		map<string, MtoFunc> creators;

		template<typename T>
		T* create() {
			return new T;
		}

	public:

		InstanceCreator() = default;

		template<typename T>
		int RegisterType(string typeName) {
			creators[typeName] = bind(&InstanceCreator::create<T>, this);

			return 0;
		}

		TBase* CreateInstance(string typeName) {

			typename map<string, MtoFunc>::iterator iter = creators.find(typeName);
			if (iter != creators.end())
			{
				return creators[typeName]();
			}
		}

		/// <summary>
		/// 回傳之前就自動先把形態轉回原本的形態
		/// TODO: 設計一個判斷轉型態有沒有成功的程式
		/// </summary>
		template<typename T>
		T* CreateInstanceWithT(string typeName) {
			typename map<string, MtoFunc>::iterator iter = creators.find(typeName);
			if (iter != creators.end())
			{
				TBase* temp = creators[typeName]();
				T* temp2 = temp->template Cast<T>();
				return temp2;
			}

			// TODO: 噴錯誤？
			Log(LogLevel::LogERROR) << "InstanceCreator::CreateInstanceWithT : 出現錯誤，未找到 " << typeName << " 的建立者";

			throw runtime_error("int InstanceCreator::CreateInstanceWithT() : 出現錯誤，未找到該typename的建立者");
			return NULL;

		}

	};


}


#endif