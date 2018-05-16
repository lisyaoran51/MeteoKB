#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>
#include<fstream>


using namespace std;

namespace base {
namespace sheetmusic {
namespace io {

	class file_reader_t
	{
		string path;
	public:
		file_reader_t(string p);
		fstream* get_stream(string name);
	};

}}}





#endif