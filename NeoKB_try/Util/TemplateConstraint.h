#ifndef TEMPLATE_CONSTRAINT_T
#define TEMPLATE_CONSTRAINT_T


/*
 * http://www.stroustrup.com/bs_faq2.html#constraints
 * make a constraint for template
 *
 * awesome trick to automatically register class
 * https://stackoverflow.com/questions/10332725/how-to-automatically-register-a-class-on-creation
 */




namespace Util {

	/// <summary>
	/// make a constraint for template
	/// </summary>
	template<class T_derived, class T_constraint>
	class TConstraint {
	
		/// <summary>
		/// to check if the template class is derived from T_constraint
		/// </summary>
		//template<class T_derived>
		//void constraint_check_derived_from() {
		//	T_derived* d;
		//	TConstraint* c = d;
		//}

		/// <summary>
		/// to check if the template class is derived from T_constraint
		/// </summary>
		void constraint_check_derived_from() {
			T_derived* d;
			TConstraint* c = d;
		}

		/// <summary>
		/// used to automatically check
		/// https://stackoverflow.com/questions/10332725/how-to-automatically-register-a-class-on-creation
		/// </summary>
		static bool check = init();

		static bool init()
		{
			constraint_check_derived_from();
			return true;
		}

	public:

		/// <summary>
		/// never want it really to check. just compile constraint_check_derived_from() is enough.
		/// </summary>
		TConstraint{
			if(false)
				check;
		}

		/// <summary>
		/// make a constraint for template. User have to design his own checking workflow. 
		/// </summary>
		virtual void constraint_check() = 0;

		

	};




}


#endif