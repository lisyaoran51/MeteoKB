#ifndef MTO_OBJECT_H
#define MTO_OBJECT_H



#include <string>

class RegisterType {

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

	MtoObject() : RegisterType("MtoObject"){}

	/// <summary>
	/// ����java�̪� (object) as (class)�A�@���૬�覡
	/// </summary>
	template<typename T>
	static T Cast(MtoObject* o) {
		if (typeid(T) == typeid(o)) {
			return static_cast<T>(o);
		}
		else
			return NULL;
	}

};



#endif