#ifndef MTO_OBJECT_H
#define MTO_OBJECT_H



#include <string>

/// <summary>
/// 給每個meteo的class一個type name，因為想做一些reflection的東西，在private load機制裡
/// 每一個我們程式裡的class一定都要覆寫GetTypeName
/// </summary>
class MtoObject {

public:
	/// <summary>
	/// 每一個我們程式裡的class一定都要覆寫GetTypeName
	/// </summary>
	virtual string GetTypeName() = 0;

};


#endif