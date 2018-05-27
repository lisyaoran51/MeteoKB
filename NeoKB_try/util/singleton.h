#ifndef SINGLETON_H
#define SINGLETON_H


/*
 * https://stackoverflow.com/questions/1008019/c-singleton-design-pattern
 *
 */


namespace Util {

	template<typename T>
	class singleton_t
	{
	protected:
		singleton_t() noexcept = default;

		singleton_t(const singleton_t&) = delete;

		singleton_t& operator=(const singleton_t&) = delete;

		virtual ~singleton_t() = default; // to silence Base class Singleton<T> has a
										// non-virtual destructor [-Weffc++]

	public:
		static T& GetInstance() noexcept(std::is_nothrow_constructible<T>::value)
		{
			// Guaranteed to be destroyed.
			// Instantiated on first use.
			// Thread safe in C++11
			static T instance;

			return instance;
		}
	};

	/* --DEPRICATED
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
	*/




}


#endif