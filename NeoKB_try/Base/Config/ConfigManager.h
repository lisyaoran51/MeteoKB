#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include"../../Util/MtoObject.h"
#include"../../Util/MtoType.h"
#include<string>
#include<map>


#define CONFIG_PATH 


using namespace Util;
using namespace std;


namespace Base {
namespace Config{

	template<typename T>
	class ConfigManager: public MtoObject {

		typedef T Setting;

		map<Setting, int> configStoreInt;
		map<Setting, MTO_FLOAT> configStoreFloat;
		map<Setting, bool> configStoreBool;
		map<Setting, string> configStoreString;

	public:

		ConfigManager(): RegisterType("ConfigManager")
		{
			// TODO: 照裡來說應該是每次建立時，強制執行InitializeDefault，但是在c++裡建構子不能執行virtual函式
			// 這個問題要找別的方法解決
			InitializeDefault();
		}

		int Load() {
			// 這個式要做什麼?
			// 讀文件嗎?
			return 0;
		}

		int Set(T lookup, int value) {
			configStoreInt[lookup] = value;
			return 0;
		}

		int Set(T lookup, MTO_FLOAT value) {
			configStoreFloat[lookup] = value;
			return 0;
		}

		int Set(T lookup, bool value) {
			configStoreBool[lookup] = value;
			return 0;
		}

		int Set(T lookup, string value) {
			configStoreString[lookup] = value;
			return 0;
		}

		// 這個寫法不能判斷是否有資料在map裡
		//template<typename U>
		//U Get(T lookup);

		template<typename U>
		bool Get(T lookup, U* out) {
			if (typeid(U) == typeid(int))
			{
				typename map<Setting, int>::iterator iter = configStoreInt.find(lookup);
				if (iter != configStoreInt.end())
				{
					*out = static_cast<U*>(configStoreInt[lookup]);
					return true;
				}
			}

			if (typeid(U) == typeid(MTO_FLOAT))
			{
				typename map<Setting, MTO_FLOAT>::iterator iter = configStoreFloat.find(lookup);
				if (iter != configStoreFloat.end())
				{
					*out = static_cast<U*>(configStoreFloat[lookup]);
					return true;
				}
			}

			if (typeid(U) == typeid(bool))
			{
				typename map<Setting, bool>::iterator iter = configStoreBool.find(lookup);
				if (iter != configStoreBool.end())
				{
					*out = static_cast<U*>(configStoreBool[lookup]);
					return true;
				}
			}

			if (typeid(U) == typeid(string))
			{
				typename map<Setting, string>::iterator iter = configStoreString.find(lookup);
				if (iter != configStoreString.end())
				{
					*out = static_cast<U*>(configStoreString[lookup]);
					return true;
				}
			}
			return false;
		}

	protected:

		virtual int InitializeDefault() = 0;

	};

}}



#endif