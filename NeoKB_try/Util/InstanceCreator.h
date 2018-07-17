#ifndef INSTANCE_CREATOR_H
#define INSTANCE_CREATOR_H

#include <string>
#include <map>
#include "Singleton.h"
#include <functional>
#include "Log.h"


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
	
		typedef function<TBase*(void)> MtoFunc;
		//typename function<TBase*(void)> aaaa;

		map<string, MtoFunc> creators;

		template<typename T>
		T* create() {
			return new T;
		}

	public:

		InstanceCreator() = default;

		template<typename T>
		int RegisterType(string typeName) {
			creators[typeName] = bind(&InstanceCreator::create<T>, this);

			return 0;
		}

		TBase* CreateInstance(string typeName) {

			typename map<string, MtoFunc>::iterator iter = creators.find(typeName);
			if (iter != creators.end())
			{
				return creators[typeName]();
			}
		}

		/// <summary>
		/// �^�Ǥ��e�N�۰ʥ���κA��^�쥻���κA
		/// TODO: �]�p�@�ӧP�_�૬�A���S�����\���{��
		/// </summary>
		template<typename T>
		T* CreateInstanceWithT(string typeName) {
			typename map<string, MtoFunc>::iterator iter = creators.find(typeName);
			if (iter != creators.end())
			{
				TBase* temp = creators[typeName]();
				T* temp2 = temp->template Cast<T>();
				return temp2;
			}

			// TODO: �Q���~�H
			Log(LogLevel::LogERROR) << "InstanceCreator::CreateInstanceWithT : �X�{���~�A����� " << typeName << " ���إߪ�";

			throw runtime_error("int InstanceCreator::CreateInstanceWithT() : �X�{���~�A������typename���إߪ�");
			return NULL;

		}

	};


}


#endif