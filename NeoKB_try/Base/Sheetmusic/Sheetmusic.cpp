#include"Sheetmusic.h"


using namespace Base::Sheetmusics;
using namespace std;

template<typename T>
Sm<T>::Sm(Sm<T>* sm)
{
	if (sm) {
		// TODO: 應該是要附置一份，而不是直接指過去
		SetSmInfo(sm->GetSmInfo());
		SetSmMetadata(sm->GetSmMetadata());
		SetEvents(sm->GetEvents());
		SetRulesetInfo(sm->GetRulesetInfo());
	}
	else {
		SetSmInfo(new SmInfo());
		SetSmMetadata(new SmMetadata());
		SetEvents(new vector<T*>());
		// SetRulesetInfo
	}
}

template<typename T>
Sm<T>::~Sm()
{
	delete smInfo;
	delete smMetadata;
	delete events;
	delete rulesetInfo;
}

template<typename T>
int Sm<T>::SetSmInfo(SmInfo * si)
{
	smInfo = si;
	return 0;
}

template<typename T>
SmInfo * Sm<T>::GetSmInfo()
{
	return smInfo;
}

template<typename T>
int Sm<T>::SetSmMetadata(SmMetadata * sm)
{
	smMetadata = sm;
	return 0;
}

template<typename T>
SmMetadata * Sm<T>::GetSmMetadata()
{
	return smMetadata;
}

template<typename T>
int Sm<T>::SetEvents(vector<T*>* e)
{
	events = e;
	// TODO: sort
	sort(e->begin(), e->end());
	return 0;
}

template<typename T>
vector<T*>* Sm<T>::GetEvents()
{
	return events;
}

template<typename T>
int Sm<T>::SetRulesetInfo(RulesetInfo * r)
{
	rulesetInfo = r;
	return 0;
}

template<typename T>
RulesetInfo * Sm<T>::GetRulesetInfo()
{
	return rulesetInfo;
}
