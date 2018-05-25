#ifndef CHILD_ADDABLE_H
#define CHILD_ADDABLE_H

#include"loadable.h"
#include<vector>

using namespace std;



namespace Util {
namespace Hierachal {

	/// <summary>
	/// able to add to a parent object
	/// </summary>
	class ChildAddable {

		/// <summary>
		/// this vector is applied every time you call add_child()
		/// </summary>
		private vector<MTO_FUNC_POINTER> onAdd;

	public:

		/// <summary>
		/// when add child, automatically call every privateLoad() to load in parent's configuration
		/// </summary>
		int AddChild(ChildAddable* child);


	};




}
}




#endif