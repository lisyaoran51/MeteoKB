#include "ChildAddable.h"

using namespace Util::Hierachal;


int ChildAddable::AddChild(ChildAddable * child)
{
	if (child->SetParent(this) == 0) {
		child->Load();

		for (int i = 0; i < onAdd.size(); i++)
			onAdd[i]();

		return 0;
	}
	

	// TODO: ¨Ò¥~³B²z
	return -1;
}


int Util::Hierachal::ChildAddable::RegisterOnAdd(int (*action)())
{
	onAdd.push_back(action);
	return 0;
}
