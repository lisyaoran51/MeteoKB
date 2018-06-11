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

		map<T, int> configStoreInt;
		map<T, MTO_FLOAT> configStoreFloat;
		map<T, bool> configStoreBool;
		map<T, string> configStoreString;

	public:

		ConfigManager();

		Load();

		int Set(T lookup, int value);

		int Set(T lookup, MTO_FLOAT value);

		int Set(T lookup, bool value);

		int Set(T lookup, string value);

		template<typename U>
		U Get(T lookup);

	protected:

		virtual int InitializeDefault() = 0;

	};

}}



#endif