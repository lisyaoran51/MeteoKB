#include "Hierachal\Cachable.h"
#include <stdexcept>


using namespace Util::Hierachal;



Cachable* Cachable::GetCache(string type)
{
	if (cache.find(type) == cache.end()) {
		if (GetParent() != NULL) {

		}
	}


	Cachable* c = cache[type];

	// TODO: 在沒有的時候丟錯誤
	if (!c)
		throw invalid_argument("Cachable: No such type in this cache");

	return c;
}

template<typename T>
int Cachable::Cache(T* o)
{
	cache[o->GetTypeName()] = o;

	return 0;
}

