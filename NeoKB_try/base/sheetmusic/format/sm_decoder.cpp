#include "sm_decoder.h"
#include "../../../Util/instance_creator.h"


using namespace std;
using namespace base::sheetmusic::format;
using namespace Util;

/*
* https://openhome.cc/Gossip/CppGossip/StandardException.html
* error handling in c++
*
*/




sm_decoder_t* sm_decoder_t::get_decoder(ifstream * stream)
{
	
	string line;

	do {

		getline(*stream, line);

	} while (!stream->eof() && line.empty());

	if (!decoders.count(line)) {
		throw invalid_argument("sm_decoder_t:input stream has no decoder version in first line.");
	}

	// TODO: §ï½Õsingleton¿ù»~
	instance_creator_t<sm_decoder_t> instance_creater = 
		instance_creator_t<sm_decoder_t>::get_instance();

	return instance_creator_t<sm_decoder_t>::create_instance(decoders[line]);
}

sm_t<effect_t>* sm_decoder_t::decode(fstream * stream)
{
	return parse_file(stream);
}

void sm_decoder_t::add_decoder(string version, string type_name)
{
	decoders[version] = type_name;
}

sm_t<effect_t>* sm_decoder_t::parse_file(fstream * stream)
{
	sm_t<effect_t>* sm = new sm_t<effect_t>();

	parse_file(stream, sm);

	return sm;
}






