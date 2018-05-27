#ifndef LOADABLE_H
#define LOADABLE_H

#include "cachable.h"
#include "../MtoType.h"
#include<vector>
#include<utility>

using namespace std;
using namespace Util;

/*
 * pointer of every variable
 * https://stackoverflow.com/questions/19710601/any-type-of-pointer-can-point-to-anything
 *
 * 註冊privateLoad的方法
 * 在constructor裡面放一個registerPrivateLoader("類別名稱", privateLoad);
 */


#define LOADER_POINTER MTO_FUNC_POINTER
#define LOADER_INPUT pair<int, char**>*

/*
 * when child class call parent class's protected function to access private variable, it only
 * access his own private variable, but not access child class's private variable
 *
 * c++ can't automatically register private function. so we do it manually by put 
 * "registerPrivateLoader()" into every constructor of child classes. So that
 * we could find a vector of loaders of each class inherited from loadable_t
 * and then call them
 *
 */

namespace Util {
namespace Hierachal{

	class loadable_t: public Cachable {

		load_state_t load_state;

		/// <summary>
		/// for register_load() to ergister every loaders into this vector
		/// </summary>
		vector<LOADER_POINTER> loaders;

		/// <summary>
		/// for every loaders to put input parameter into loaders
		/// </summary>
		vector<LOADER_INPUT> loader_inputs;

		int privateLoad(int argc, char* argv);

	public:

		loadable_t() {
			// must do in every loadable derived class
			registerPrivateLoader("loadable_t", privateLoad);
		}

		bool is_loaded();

		load_state_t get_load_state();

		/// <summary>
		/// call every parent class's private load() function
		/// 1. take out all loaders and all parameters
		/// 2. call every loaders with those parameter
		/// </summary>
		int load();

	protected:

		/// <summary>
		/// register loader, must do in every loadable derived class 
		/// 
		/// </summary>
		/// <param name="name">類別名稱</param>
		/// <param name="p_loader">private loader</param>
		/// <param name="argc">loader需要幾個輸入</param>
		/// <param name="argv">每個輸入的名稱</param>
		int registerPrivateLoader(string name, int(pLoader*)(int, char*), int argc, char** argv) {
			// find every parent class's private load() function
			// https://stackoverflow.com/questions/16262338/get-Base-class-for-a-type-in-class-hierarchy
			loaders.push_back(pLoader);

		}

	};


	/// <summary>
	/// Possible states of a <see cref="Drawable"/> within the loading pipeline.
	/// </summary>
	enum load_state_t {
		/// <summary>
		/// Not loaded, and no load has been initiated yet.
		/// </summary>
		load_state_not_loaded,
		/// <summary>
		/// Currently loading (possibly and usually on a background
		/// thread via <see cref="Drawable.LoadAsync(Game, Drawable, Action)"/>).
		/// </summary>
		load_state_loading,
		/// <summary>
		/// Loading is complete, but has not yet been finalized on the update thread
		/// (<see cref="Drawable.LoadComplete"/> has not been called yet, which
		/// always runs on the update thread and requires <see cref="Drawable.IsAlive"/>).
		/// </summary>
		load_state_ready,
		/// <summary>
		/// Loading is fully completed and the Drawable is now part of the scene graph.
		/// </summary>
		load_state_loaded
	}



}}




#endif