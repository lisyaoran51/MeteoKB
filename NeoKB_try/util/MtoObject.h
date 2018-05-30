#ifndef MTO_OBJECT_H
#define MTO_OBJECT_H



#include <string>

class RegisterType {

	// TODO: 讓他不要佔這麼多空間，改用一個lookup table之類
	string typeName;

public:

	string GetTypeName() { return typeName; }

protected:

	RegisterType(string t) { typeName = t; }

};

/// <summary>
/// 給每個meteo的class一個type name，因為想做一些reflection的東西，在private load機制裡
/// 每一個我們程式裡的class一定都要覆寫GetTypeName
/// </summary>
class MtoObject : virtual public RegisterType {

public:

	MtoObject() : RegisterType("MtoObject"){}

	/// <summary>
	/// 類似java裡的 (object) as (class)，一種轉型方式
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