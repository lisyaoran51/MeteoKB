#include "Loadable.h"
#include <stdexcept>


using namespace Util::Hierachal;


/*
* stdexcept種類
* https://hk.saowen.com/a/180e33be2080d38fcfc0f75820680315c53d2a8035c7be6203cc9a093ff73bc2
*
* inner class怎麼取外面class的値
* https://stackoverflow.com/questions/486099/can-inner-classes-access-private-variables
*/

Loadable::LoadStateHandler::LoadStateHandler(Loadable & l): loadable(l)
{
}

// --------------------------

Loadable::NoParentHandler::NoParentHandler(Loadable & l): LoadStateHandler(l)
{
}

LoadState Loadable::NoParentHandler::GetLoadState()
{
	return LoadStateNoParent;
}

int Loadable::NoParentHandler::HandleLoad()
{
	throw runtime_error("int Loadable::Load(): This has no parent yet.");
	return -1;
}

int Loadable::NoParentHandler::Async()
{
	loadable.loadStateHandler = &loadable.loadingHandler;
	loadable.load();
	loadable.loadStateHandler = &loadable.readyHandler;
	return 0;
}

int Loadable::NoParentHandler::SetParent(HasParent * p)
{
	loadable.HasParent::SetParent(p);
	loadable.loadStateHandler = &loadable.notLoadedHandler;
	return 0;
}

// --------------------------

Loadable::NotLoadedHandler::NotLoadedHandler(Loadable & l) : LoadStateHandler(l)
{
}

LoadState Loadable::NotLoadedHandler::GetLoadState()
{
	return LoadStateNotLoaded;
}

int Loadable::NotLoadedHandler::HandleLoad()
{
	loadable.loadStateHandler = &loadable.loadingHandler;
	loadable.load();
	loadable.loadStateHandler = &loadable.readyHandler;
	return 0;
}

int Loadable::NotLoadedHandler::Async()
{
	loadable.loadStateHandler = &loadable.loadingHandler;
	loadable.load();
	loadable.loadStateHandler = &loadable.readyHandler;
	return 0;
}

int Loadable::NotLoadedHandler::SetParent(HasParent * p)
{
	loadable.HasParent::SetParent(p);
	return 0;
}

// --------------------------

Loadable::LoadingHandler::LoadingHandler(Loadable & l) : LoadStateHandler(l)
{
}

LoadState Util::Hierachal::Loadable::LoadingHandler::GetLoadState()
{
	return LoadStateLoading;
}

int Util::Hierachal::Loadable::LoadingHandler::HandleLoad()
{
	// 讀取中，不能重複讀取
	return -1;
}

int Util::Hierachal::Loadable::LoadingHandler::Async()
{
	// 讀取中，不能重複讀取
	return -1;
}

int Util::Hierachal::Loadable::LoadingHandler::SetParent(HasParent * p)
{
	// 已讀取中
	return -1;
}

// --------------------------

Loadable::ReadyHandler::ReadyHandler(Loadable & l) : LoadStateHandler(l)
{
}

LoadState Util::Hierachal::Loadable::ReadyHandler::GetLoadState()
{
	return LoadStateReady;
}

int Util::Hierachal::Loadable::ReadyHandler::HandleLoad()
{
	// TODO: 要寫重複利用的方法
	return -1;
}

int Util::Hierachal::Loadable::ReadyHandler::Async()
{
	// TODO: 要寫重複利用的方法
	return -1;
}

int Util::Hierachal::Loadable::ReadyHandler::SetParent(HasParent * p)
{
	// TODO: 要寫重複利用的方法
	return -1;
}

