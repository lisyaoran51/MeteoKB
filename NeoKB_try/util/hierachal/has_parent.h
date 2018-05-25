#ifndef HAS_PARENT_H
#define HAS_PARENT_H




namespace Util {
	namespace Hierachal {

		/// <summary>
		/// has a parent object
		/// </summary>
		class has_parent_t {

			has_parent_t* parent;

		public:

			int get_parent();

			int set_parent(has_parent_t* p);

		};




	}
}




#endif