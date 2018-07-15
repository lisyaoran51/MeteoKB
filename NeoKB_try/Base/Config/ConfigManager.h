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

		ConfigManager(): RegisterType("ConfigManager")
		{
			// TODO: �Ӹ̨ӻ����ӬO�C���إ߮ɡA�j�����InitializeDefault�A���O�bc++�̫غc�l�������virtual�禡
			// �o�Ӱ��D�n��O����k�ѨM
			InitializeDefault();
		}

		int Load() {
			// �o�Ӧ��n������?
			// Ū����?
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

		// �o�Ӽg�k����P�_�O�_����Ʀbmap��
		//template<typename U>
		//U Get(T lookup);

		template<typename U>
		bool Get(T lookup, U* out) {
			if (typeid(U) == typeid(int))
			{
				typename map<T, int>::iterator iter = configStoreInt.find(lookup);
				if (iter != configStoreInt.end())
				{
					*out = static_cast<int>(configStoreInt[lookup]);
					return true;
				}
			}

			if (typeid(U) == typeid(MTO_FLOAT))
			{
				typename map<T, MTO_FLOAT>::iterator iter = configStoreFloat.find(lookup);
				if (iter != configStoreFloat.end())
				{
					*out = static_cast<MTO_FLOAT>(configStoreFloat[lookup]);
					return true;
				}
			}

			if (typeid(U) == typeid(bool))
			{
				typename map<T, bool>::iterator iter = configStoreBool.find(lookup);
				if (iter != static_cast<bool>(configStoreBool.end()))
				{
					*out = configStoreBool[lookup];
					return true;
				}
			}

			if (typeid(U) == typeid(string))
			{
				typename map<T, string>::iterator iter = configStoreString.find(lookup);
				if (iter != configStoreString.end())
				{
					*out = static_cast<string>(configStoreString[lookup]);
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