#include "MtoObject.h"



using namespace Util;




MtoObject::MtoObject() : RegisterType("MtoObject") 
{
}



template<typename T>
T * MtoObject::Cast(MtoObject * o) {
	if (typeid(T*) == typeid(o)) {
		return static_cast<T*>(o);
	}
	else if(T* t = dynamic_cast< T* >(o))
		return dynamic_cast< T* >(o);
	return NULL;
}

template<typename T, typename U>
T * MtoObject::Cast(U * o)
{
	if (T* t = dynamic_cast< T* >(o))
		return dynamic_cast< T* >(o);
	return NULL;
}

template<typename T, typename U>
bool MtoObject::CanCast(U * o)
{
	if (T* t = dynamic_cast< T* >(o)){
		return true;
	}
	else {
		return false;
	}
}