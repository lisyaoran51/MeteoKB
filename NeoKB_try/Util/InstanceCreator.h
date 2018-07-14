#ifndef INSTANCE_CREATOR_H
#define INSTANCE_CREATOR_H

#include <string>
#include <map>
#include "Singleton.h"
#include <functional>


/*
* https://stackoverflow.com/questions/582331/is-there-a-way-to-instantiate-objects-from-a-string-holding-their-class-name
* instantiate a class with its name in string()�o�{�����D�A�O����
*
* https://stackoverflow.com/questions/9370749/c-singleton-class-inheritance-good-practice
* another design
*/

using namespace std;


namespace Util {

	/// <summary>
	/// instantiate a class with its name in string
	/// </summary>
	template<typename TBase>
	class InstanceCreator: public Singleton<InstanceCreator<TBase>> {
	
		typename map<string, function<TBase*(void)>> creators;

		template<typename T>
		T* create();

	public:

		InstanceCreator() = default;

		template<typename T>
		int RegisterType(string typeName);

		TBase* CreateInstance(string typeName);

		/// <summary>
		/// �^�Ǥ��e�N�۰ʥ���κA��^�쥻���κA
		/// TODO: �]�p�@�ӧP�_�૬�A���S�����\���{��
		/// </summary>
		template<typename T>
		T* CreateInstanceWithT(string typeName);

	};


}


#endif