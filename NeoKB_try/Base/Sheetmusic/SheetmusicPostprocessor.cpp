#include "SheetmusicPostprocessor.h"


using namespace std;
using namespace Util;
using namespace Base::Schedulers::Events;
using namespace Base::Sheetmusics;



Sm<Event>* SmPostprocessor::postprocess(Sm<Event>* s)
{
	LOG(LogLevel::Fine) << "Sm<Event>* SmPostprocessor::postprocess(Sm<Event>*) : Start sorting ...";

	sort(s->GetEvents()->begin(), s->GetEvents()->end());
	return s;
}


