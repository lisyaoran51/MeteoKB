#include "SmDecoder.h"
#include "../../../Util/InstanceCreator.h"


using namespace std;
using namespace Base::Sheetmusics::Format;
using namespace Util;

/*
* https://openhome.cc/Gossip/CppGossip/StandardException.html
* error handling in c++
*
*/




int SmDecoder::RegisterDecoder(string version, string typeName)
{
	decoders[version] = typeName;
	return 0;
}

SmDecoder* SmDecoder::GetDecoder(ifstream * stream)
{
	
	string line;

	do {

		getline(*stream, line);

	} while (!stream->eof() && line.empty());

	if (!decoders.count(line)) {
		throw invalid_argument("sm_decoder_t:input stream has no decoder version in first line.");
	}

	// TODO: §ï½Õsingleton¿ù»~
	InstanceCreator<SmDecoder> &instance_creater =
		InstanceCreator<SmDecoder>::GetInstance();

	return instance_creater.CreateInstance(decoders[line]);
}

Sm<Event>* SmDecoder::Decode(ifstream * stream)
{
	return parseFile(stream);
}


Sm<Event>* SmDecoder::parseFile(ifstream * stream)
{
	Sm<Event>* sm = new Sm<Event>();

	parseFile(stream, sm);

	return sm;
}






