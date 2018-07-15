#include "InstanceCreator.h"

#include "Log.h"


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
	creators[typeName] = bind(&InstanceCreator::create<T>, this);

	return 0;
}

template<typename TBase>
TBase* InstanceCreator<TBase>::CreateInstance(string typeName)
{

	map<string, MtoFunc>::iterator iter = creators.find(typeName);
	if (iter != creators.end())
	{
		return creators[typeName]();
	}
}

template<typename TBase>
template<typename T>
T* InstanceCreator<TBase>::CreateInstanceWithT(string typeName)
{
	map<string, MtoFunc>::iterator iter = creators.find(typeName);
	if (iter != creators.end())
	{
		TBase* temp = creators[typeName]();
		T temp2 = temp->Cast<T>();
		return temp2;
	}

	// TODO: �Q���~�H
	log(logERROR) << "InstanceCreator::CreateInstanceWithT : �X�{���~�A����� " << typeName << " ���إߪ�";

	throw runtime_error("int InstanceCreator::CreateInstanceWithT() : �X�{���~�A������typename���إߪ�");
	return NULL;
	
}