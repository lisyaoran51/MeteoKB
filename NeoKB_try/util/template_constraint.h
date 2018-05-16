#ifndef TEMPLATE_CONSTRAINT_T
#define TEMPLATE_CONSTRAINT_T


/*
 * http://www.stroustrup.com/bs_faq2.html#constraints
 * make a constraint for template
 *
 *
 */


namespace util {

	class T_constraint_t {
	protected:
		virtual void T_constraint_check() = 0;
	};




}


#endif