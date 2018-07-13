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




SmDecoder::SmDecoder(): RegisterType("SmDecoder")
{
}

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




template<typename T>
SmDecoderWithSection<T>::SmDecoderWithSection(): SmDecoder(), RegisterType("SmDecoderWithSection")
{
}

template<typename T>
T SmDecoderWithSection<T>::GetSectionEnum(string section)
{
	// 쫜찱줄쮁딩쩤좥�壎豊U
	if (sectionMap.size() == 0)
		setSectionMap();

	typename map<T, string>::iterator i;

	for (i = sectionMap.begin(); i != sectionMap.end(); i++)
	{
		if (i->second == section)
			return i->first;
	}
	return 0;
}

template<typename T>
string SmDecoderWithSection<T>::GetSectionString(T section)
{
	// 쫜찱줄쮁딩쩤좥�壎豊U
	if (sectionMap.size() == 0)
		setSectionMap();

	typename map<T, string>::iterator i = sectionMap.find(section);

	if (i != sectionMap.end())
		return sectionMap[section];
	else
		return "";
}






