#ifndef MTO_OBJECT_H
#define MTO_OBJECT_H





#include <string>


using namespace std;

namespace Util {

	class RegisterType {

		// TODO: ���L���n���o��h�Ŷ��A��Τ@��lookup table����
		string typeName;

	public:

		string GetTypeName() { return typeName; }

	protected:

		RegisterType(string t) { typeName = t; }

	};

	/// <summary>
	/// ���C��meteo��class�@��type name�A�]���Q���@��reflection���F��A�bprivate load�����
	/// �C�@�ӧڭ̵{���̪�class�@�w���n�мgGetTypeName
	/// </summary>
	class MtoObject : virtual public RegisterType {

	public:

		MtoObject();

		/// <summary>
		/// ����java�̪� (object) as (class)�A�@���૬�覡
		/// </summary>
		template<typename T>
		static T* Cast(MtoObject* o);

		template<typename T, typename U>
		static T* Cast(U* o);

		template<typename T, typename U>
		static bool CanCast(U* o);

	};
}



#endif