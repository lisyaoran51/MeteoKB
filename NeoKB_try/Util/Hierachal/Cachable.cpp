#include "Cachable.h"
#include <stdexcept>



using namespace Util::Hierachal;


Cachable::Cachable(): RegisterType("Cachable")
{
}

MtoObject* Cachable::getCache(string type)
{
	
	if (cache.find(type) != cache.end()) {
		// §ä¨ì

		MtoObject* c = cache[type];
		return c;
	}
	return NULL;
}

template<typename T>
T* Cachable::GetCache(string type) {

	MtoObject* o = getCache(type);

	if (!o) {
		// ¨S§ä¨ì

		HasParent* h = GetParent();
		if (!h)
			return NULL;

		Cachable* c = Cast<Cachable>(h);
		return c->GetCache<T>(type);
	}

	T* to = Cast<T>(o);

	if (!to) 
		throw invalid_argument("Cachable::GetCache<T>(string): cast to wrong class type.");
	
	return to;
}

template<typename T>
int Cachable::Cache(T* o)
{
	cache[o->GetTypeName()] = o;

	return 0;
}

template<typename T>
int Cachable::Cache(T * o, string typeName)
{
	cache[typeName] = o;

	return 0;
}

