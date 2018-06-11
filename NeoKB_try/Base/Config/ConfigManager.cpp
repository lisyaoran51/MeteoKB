#include"ConfigManager.h"


using namespace Base::Config;
using namespace std;


template<typename T>
ConfigManager<T>::ConfigManager(): RegisterType("ConfigManager")
{
	InitializeDefault();
}

template<typename T>
ConfigManager<T>::Load()
{
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

template<typename T>
template<typename U>
U ConfigManager<T>::Get(T lookup)
{
	if (typeid(U) == typeid(int))
		return configStoreInt[lookup];
	if (typeid(U) == typeid(MTO_FLOAT))
		return configStoreFloat[lookup];
	if (typeid(U) == typeid(bool))
		return configStoreBool[lookup];
	if (typeid(U) == typeid(string))
		return configStoreString[lookup];
	return NULL;
}