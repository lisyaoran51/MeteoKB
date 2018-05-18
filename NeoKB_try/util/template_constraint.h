#ifndef TEMPLATE_CONSTRAINT_T
#define TEMPLATE_CONSTRAINT_T


/*
 * http://www.stroustrup.com/bs_faq2.html#constraints
 * make a constraint for template
 *
 */


namespace util {


	/// <summary>
	/// make a constraint for template
	/// </summary>
	template<class T_constraint>
	class T_constraint_t {
	
		/// <summary>
		/// to check if the template class is derived from T_constraint
		/// </summary>
		template<class T_derived>
		void constraint_check_derived_from() {
			T_derived* d;
			T_constraint_t* c = d;
		}

	public:

		/// <summary>
		/// make a constraint for template. User have to design his own checking workflow. 
		/// </summary>
		virtual void constraint_check() = 0;

		

	};




}


#endif