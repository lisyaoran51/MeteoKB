#ifndef SM_DECODER_H
#define SM_DECODER_H

#include <string>
#include <fstream>
#include <map>
#include "../../../util/singleton.h"
#include "../sheetmusic.h"


using namespace std;
using namespace util;
using namespace base::sheetmusic;

// inlcude path defined by macro
// https://stackoverflow.com/questions/32066204/construct-path-for-include-directive-with-macro
//


namespace base {
namespace sheetmusic {
namespace format {



	class sm_decoder_t: public singleton_t
	{
		map<string, sm_decoder_t*> decoders;

	public:
		
		sm_decoder_t* get_decoder(fstream* stream);
		sm_t<effect_t>* decode(fstream* stream);

	protected:
		static void add_decoder(string version, sm_decoder_t* decoder);
		virtual sm_t<effect_t>* parse_file(fstream* stream);
		virtual void parse_file(fstream* stream, sm_t<effect_t>* sm) = 0;
	};



}}}



#endif