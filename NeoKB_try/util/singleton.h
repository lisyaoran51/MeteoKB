#ifndef SINGLETON_H
#define SINGLETON_H


/*
 * https://stackoverflow.com/questions/1008019/c-singleton-design-pattern
 *
 *
 *
 */


namespace util {

	class singleton_t {
		singleton_t() {}

		singleton_t(const singleton_t&);
		void operator=(const singleton_t&);

	public:
		static singleton_t get_instance() {
			static singleton_t instance; // Guaranteed to be destroyed.
										 // Instantiated on first use.
			return instance;
		}

		singleton_t(const singleton_t&) = delete;
		void operator=(const singleton_t&) = delete;
	};




}


#endif