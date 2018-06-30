#include"ConfigManager.h"


using namespace Base::Config;
using namespace std;


template<typename T>
ConfigManager<T>::ConfigManager(): RegisterType("ConfigManager")
{
	InitializeDefault();
}

template<typename T>
int ConfigManager<T>::Load()
{
	// 這個式要做什麼?
	// 讀文件嗎?
	return 0;
}

template<typename T>
int ConfigManager<T>::Set(T lookup, int value)
{
	configStoreInt[lookup] = value;
	return 0;
}

template<typename T>
int ConfigManager<T>::Set(T lookup, MTO_FLOAT value)
{
	configStoreFloat[lookup] = value;
	return 0;
}

template<typename T>
int ConfigManager<T>::Set(T lookup, bool value)
{
	configStoreBool[lookup] = value;
	return 0;
}

template<typename T>
int Base::Config::ConfigManager<T>::Set(T lookup, string value)
{
	configStoreString[lookup] = value;
	return 0;
}

/*
template<typename T>
template<typename U>
U ConfigManager<T>::Get(T lookup)
{
	if (typeid(U) == typeid(int))
	{
		map<int, Bar>::iterator iter = configStoreInt.find(lookup);
		if (iter != m.end())
		{
			// key 2 exists, do something with iter->second (the value)
		}
	}
		return configStoreInt[lookup];
	if (typeid(U) == typeid(MTO_FLOAT))
		return configStoreFloat[lookup];
	if (typeid(U) == typeid(bool))
		return configStoreBool[lookup];
	if (typeid(U) == typeid(string))
		return configStoreString[lookup];
	return NULL;
}*/

template<typename T>
template<typename U>
bool ConfigManager<T>::Get(T lookup, U * out)
{
	if (typeid(U) == typeid(int))
	{
		map<T, int>::iterator iter = configStoreInt.find(lookup);
		if (iter != configStoreInt.end())
		{
			*out = configStoreInt[lookup];
			return true;
		}
	}

	if (typeid(U) == typeid(MTO_FLOAT))
	{
		map<T, MTO_FLOAT>::iterator iter = configStoreFloat.find(lookup);
		if (iter != configStoreFloat.end())
		{
			*out = configStoreFloat[lookup];
			return true;
		}
	}

	if (typeid(U) == typeid(bool))
	{
		map<T, bool>::iterator iter = configStoreBool.find(lookup);
		if (iter != configStoreBool.end())
		{
			*out = configStoreBool[lookup];
			return true;
		}
	}

	if (typeid(U) == typeid(string))
	{
		map<T, string>::iterator iter = configStoreString.find(lookup);
		if (iter != configStoreString.end())
		{
			*out = configStoreString[lookup];
			return true;
		}
	}

	return false;
}
