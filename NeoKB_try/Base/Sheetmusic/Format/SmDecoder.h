#ifndef SM_DECODER_H
#define SM_DECODER_H

#include <string>
#include <fstream>
#include <map>
#include <stdexcept>
#include "../../../Util/MtoObject.h"
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


	template<typename T>
	class SmDecoder: public MtoObject
	{
		// sm decoder 不是singleton
		// friend class Singleton<SmDecoder>;

		static map<string, string> decoders;

	public:

		SmDecoder();

		static int RegisterDecoder(string version, string typeName);
		static SmDecoder* GetDecoder(ifstream* stream);
		Sm<Event>* Decode(ifstream* stream);

	protected:

		// 因為c++不支援enum直接轉string，所以要自己寫
		map<T, string> sectionMap;

		virtual int setSectionMap() = 0;

		T GetSectionEnum(string section);
		string GetSectionString(T section);

		virtual Sm<Event>* parseFile(ifstream* stream);
		virtual int parseFile(ifstream* stream, Sm<Event>* sm) = 0;
	};



}}}



#endif