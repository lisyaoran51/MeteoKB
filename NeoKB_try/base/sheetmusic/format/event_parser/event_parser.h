#ifndef EVENT_PARSER_H
#define EVENT_PARSER_H

#include <string>
#include "../../../scheduler/event/effect/effect.h"


using namespace std;
using namespace Util;
using namespace base::sheetmusic;
using namespace base::scheduler::event::effect;




namespace base {
namespace sheetmusic {
namespace format {
namespace event_parser {


	class event_parser_t
	{

	public:

		virtual event_t* parse(string text) = 0;

	};



}}}}



#endif