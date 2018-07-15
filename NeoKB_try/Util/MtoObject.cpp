#include "MtoObject.h"

#include <typeinfo>


using namespace Util;




MtoObject::MtoObject() : RegisterType("MtoObject") 
{
}


/*
 * 因為template不能放在cpp裡面，改放header
 *
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
 *
 * 因為template不能放在cpp裡面，改放header
 */