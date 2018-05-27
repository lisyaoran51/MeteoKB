#include "Hierachal\Cachable.h"
#include <stdexcept>



using namespace Util::Hierachal;



MtoObject* Cachable::getCache(string type)
{
	
	if (cache.find(type) != cache.end()) {
		// §ä¨ì

		MtoObject* c = cache[type];
		return c;
	}
	else {
		// ¨S§ä¨ì
		
		HasParent* h = GetParent();
		if (!h)
			return NULL;

		Cachable* c = Cast<Cachable*>(h);
		return c->GetCache(type);
	}
}

template<typename T>
T Cachable::GetCache(string type) {

	MtoObject* o = GetCache(type);

	if (!o)
		return NULL;

	T to = Cast<T>(o);

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

