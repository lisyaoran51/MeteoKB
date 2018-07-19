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


map<string, string> SmDecoder::decoders;

SmDecoder::SmDecoder(): RegisterType("SmDecoder")
{
}

int SmDecoder::RegisterDecoder(string version, string typeName)
{
	LOG(LogLevel::Fine) << "int SmDecoder::RegisterDecoder(string,string) : Registering Sm decoder: [" << typeName << "] to version [" << version << "].";
	decoders[version] = typeName;
	return 0;
}

SmDecoder* SmDecoder::GetDecoder(ifstream * stream)
{
	
	string line;

	do {

		getline(*stream, line);

		LOG(LogLevel::Finer) << "SmDecoder* SmDecoder::GetDecoder(ifstream*) : read sm file [" << line << "].";

	} while (!stream->eof() && line.empty());

	if (!decoders.count(line)) {
		throw invalid_argument("sm_decoder_t:input stream has no decoder version in first line.");
	}

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



