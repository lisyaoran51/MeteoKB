#ifndef CACHABLE_H
#define CACHABLE_H

#include"loadable.h"
#include<map>

using namespace std;
/*
* mutual including two classes:
* http://squall.cs.ntou.edu.tw/cpp/1042/labtest/test2/MutualReferences.html
*
*/



namespace Util {
namespace Hierachal{

	class loadable_t;

	/// <summary>
	/// to make a cache of the whole game for some configuration and common data
	/// </summary>
	class Cachable: HasParent {

		map<string, MtoObject*> cache;

	public:

		/// <summary>
		/// get the cache of a certain type in the whole hierachy
		/// </summary>
		Cachable* GetCache(string type);

		template<typename T>
		int Cache(T* o);

	};

}}




#endif