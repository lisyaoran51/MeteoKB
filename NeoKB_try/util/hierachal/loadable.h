#ifndef LOADABLE_H
#define LOADABLE_H

#include "cachable.h"
#include<vector>
#include<utility>

using namespace std;

#define LOADER_POINTER int (*)(int, char*)
#define LOADER_INPUT pair<int, char**>*

/*
 * when child class call parent class's protected function to access private variable, it only
 * access his own private variable, but not access child class's private variable
 *
 */

namespace util {
namespace hierachal{

	class loadable_t: public cachable_t {

		load_state_t load_state;

		/// <summary>
		/// for register_load() to ergister every loaders into this vector
		/// </summary>
		vector<LOADER_POINTER> loaders;

		/// <summary>
		/// for every loaders to put input parameter into loaders
		/// </summary>
		vector<LOADER_INPUT> loader_inputs;

		int private_load();
		
		/// <summary>
		/// find every parent class's load() and put into loaders
		/// </summary>
		int register_loaders();

	public:

		loadable_t() {
			register_private_loader();
		}

		bool is_loaded();

		load_state_t get_load_state();

		/// <summary>
		/// call every parent class's private load() function
		/// 1. register every private load()
		/// 2. call every loaders
		/// </summary>
		int load();

	protected:

		int register_private_loader() {
			// find every parent class's private load() function
			// https://stackoverflow.com/questions/16262338/get-base-class-for-a-type-in-class-hierarchy
			loaders.push_back(private_load);

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