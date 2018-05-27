#ifndef SHEETMUSIC_METADATA_H
#define SHEETMUSIC_METADATA_H

#include <string>
#include <fstream>
#include <vector>
#include "../../Util/TemplateConstraint.h"



using namespace std;
using namespace Util;

namespace Base {
namespace sheetmusic {
	
	 
	class sm_metadata_t
	{

	public:

		string Artist;
		string ArtistUnicode;
		string AudioFile;
		string AuthorString;
		int OnlineSheetmusic;
		int PreviewTime;
		string Source;
		string Tags;
		string Title;
		string TitleUnicode;



	};


}}



#endif