#include "Loadable.h"

using namespace Util::Hierachal;
using namespace std;


int Util::Hierachal::Loadable::load()
{
	for (int i = 0; i < loaders.size(); i++) {
		loaders[i]();
	}
	return 0;
}

Loadable::Loadable(): RegisterType("Loadable")
{
	loadStateHandler = &noParentHandler;
}

int Loadable::Async()
{
	return loadStateHandler -> Async();
}

LoadState Loadable::GetLoadState()
{
	return loadStateHandler->GetLoadState();
}

int Loadable::SetParent(HasParent * p)
{
	loadStateHandler->SetParent(p);
	return 0;
}

int Loadable::registerLoad(function<int(void)> l) {
	// find every parent class's private load() function
	// https://stackoverflow.com/questions/16262338/get-Base-class-for-a-type-in-class-hierarchy
	loaders.push_back(l);
}

int Loadable::Load()
{
	loadStateHandler->HandleLoad();
	return 0;
}


