#ifndef CACHABLE_H
#define CACHABLE_H

#include"Loadable.h"
#include<map>
#include"HasParent.h"

using namespace std;
/*
* mutual including two classes:
* http://squall.cs.ntou.edu.tw/cpp/1042/labtest/test2/MutualReferences.html
*
*/



namespace Util {
namespace Hierachal{

	class Loadable;

	/// <summary>
	/// to make a cache of the whole game for some configuration and common data
	/// </summary>
	class Cachable: public HasParent {

		map<string, MtoObject*> cache;

	public:

		template<typename T>
		T* GetCache(string type);

		template<typename T>
		int Cache(T* o);

	protected:

		/// <summary>
		/// get the cache of a certain type in the whole hierachy
		/// </summary>
		MtoObject* getCache(string type);

	};

}}




#endif