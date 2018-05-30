#ifndef EVENT_PARSER_H
#define EVENT_PARSER_H

#include <string>
#include "../../../Scheduler/Event/effect/effect.h"


using namespace std;
using namespace Util;
using namespace Base::Sheetmusic;
using namespace Base::Scheduler::Event::effect;




namespace Base {
namespace Sheetmusic {
namespace format {
namespace event_parser {


	class event_parser_t
	{

	public:

		virtual Event* parse(string text) = 0;

	};



}}}}



#endif