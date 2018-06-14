#ifndef SM_DECODER_H
#define SM_DECODER_H

#include <string>
#include <fstream>
#include <map>
#include <stdexcept>
#include "../../../Util/singleton.h"
#include "../Sheetmusic.h"
#include "../../Scheduler/Event/Event.h"


using namespace std;
using namespace Util;
using namespace Base::Sheetmusics;
using namespace Base::Schedulers::Events;

// inlcude path defined by macro
// https://stackoverflow.com/questions/32066204/construct-path-for-include-directive-with-macro
//


namespace Base {
namespace Sheetmusics {
namespace Format {



	class SmDecoder: public Singleton<SmDecoder>
	{

		friend class Singleton<SmDecoder>;

		static map<string, string> decoders;

	public:
		
		static int RegisterDecoder(string version, string typeName);
		static SmDecoder* GetDecoder(ifstream* stream);
		Sm<Event>* Decode(ifstream* stream);

	protected:

		virtual Sm<Event>* parseFile(ifstream* stream);
		virtual void parseFile(ifstream* stream, Sm<Event>* sm) = 0;
	};



}}}



#endif