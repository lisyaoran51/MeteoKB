#ifndef MTO_OBJECT_H
#define MTO_OBJECT_H



#include <string>

/// <summary>
/// ���C��meteo��class�@��type name�A�]���Q���@��reflection���F��A�bprivate load�����
/// �C�@�ӧڭ̵{���̪�class�@�w���n�мgGetTypeName
/// </summary>
class MtoObject {

public:
	/// <summary>
	/// �C�@�ӧڭ̵{���̪�class�@�w���n�мgGetTypeName
	/// </summary>
	virtual string GetTypeName() = 0;

};


#endif