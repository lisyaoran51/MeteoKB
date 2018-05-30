#ifndef SM_DECODER_H
#define SM_DECODER_H

#include <string>
#include <fstream>
#include <map>
#include <stdexcept>
#include "../../../Util/singleton.h"
#include "../Sheetmusic.h"
#include "../../Scheduler/Event/effect/effect.h"


using namespace std;
using namespace Util;
using namespace Base::Sheetmusic;
using namespace Base::Scheduler::Event::effect;

// inlcude path defined by macro
// https://stackoverflow.com/questions/32066204/construct-path-for-include-directive-with-macro
//


namespace Base {
namespace Sheetmusic {
namespace format {



	class sm_decoder_t: public singleton_t<sm_decoder_t>
	{

		friend class singleton_t<sm_decoder_t>;

		map<string, string> decoders;

	public:
		
		static int registerDecoder(string version, string type_name);
		static sm_decoder_t* get_decoder(ifstream* stream);
		Sm<Effect>* decode(fstream* stream);

	protected:

		virtual Sm<Effect>* parse_file(fstream* stream);
		virtual void parse_file(fstream* stream, Sm<Effect>* sm) = 0;
	};



}}}



#endif