#ifndef SM_DECODER_H
#define SM_DECODER_H

#include <string>
#include <fstream>
#include <map>
#include <stdexcept>
#include "../../../Util/singleton.h"
#include "../sheetmusic.h"
#include "../../scheduler/event/effect/effect.h"


using namespace std;
using namespace Util;
using namespace base::sheetmusic;
using namespace base::scheduler::event::effect;

// inlcude path defined by macro
// https://stackoverflow.com/questions/32066204/construct-path-for-include-directive-with-macro
//


namespace base {
namespace sheetmusic {
namespace format {



	class sm_decoder_t: public singleton_t<sm_decoder_t>
	{

		friend class singleton_t<sm_decoder_t>;

		map<string, string> decoders;

	public:
		
		sm_decoder_t* get_decoder(ifstream* stream);
		sm_t<effect_t>* decode(fstream* stream);

	protected:

		void add_decoder(string version, string type_name);
		virtual sm_t<effect_t>* parse_file(fstream* stream);
		virtual void parse_file(fstream* stream, sm_t<effect_t>* sm) = 0;
	};



}}}



#endif