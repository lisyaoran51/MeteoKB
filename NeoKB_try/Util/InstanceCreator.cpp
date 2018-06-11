#include "InstanceCreator.h"


using namespace Util;
using namespace std;


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
TBase* InstanceCreator<TBase>::CreateInstance(string typeName)
{
	return creators[typeName]();
}

template<typename TBase>
template<typename T>
T* InstanceCreator<TBase>::CreateInstanceWithT(string typeName)
{
	TBase* temp = creators[typeName]();
	T temp2 = temp->Cast<T>();
	return temp2;
}