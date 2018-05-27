#include "InstanceCreator.h"


using namespace Util;



template<typename TBase>
template<typename T>
T* InstanceCreator<TBase>::create()
{
	return new T;
}

template<typename TBase>
template<typename T>
int InstanceCreator<TBase>::RegisterType(string typeName)
{

	creators[typeName] = create<T>;

	return 0;
}

template<typename TBase>
TBase* Util::InstanceCreator<TBase>::CreateInstance(string typeName)
{
	return creators[typeName]();
}