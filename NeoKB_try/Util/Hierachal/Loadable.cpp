#include "Loadable.h"

using namespace Util::Hierachal;
using namespace std;



/*
 * 多載的函市擺進去function裡面的方法
 * https://stackoverflow.com/questions/13064698/stdbind-and-overloaded-function
 * https://stackoverflow.com/questions/38559546/stdbind-with-overloaded-function-from-parent-class
 * registerLoad(bind(static_cast<int(??::*)(void)>(&??::load), this));
 */


int Loadable::load()
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


