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



namespace util {
namespace hierachal{

	class loadable_t;

	/// <summary>
	/// to make a cache of the whole game for some configuration and common data
	/// </summary>
	class cachable_t {

		map<type_info, void*> cache;

	public:

		/// <summary>
		/// get the parent object in hierachy
		/// </summary>
		loadable_t* get_parent();

		/// <summary>
		/// get the cache of a certain type in the whole hierachy
		/// </summary>
		cachable_t* get_cache(type_info t);

		template<T>
		int cache(T o);

	};




}}




#endif