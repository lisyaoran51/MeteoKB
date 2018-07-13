#include "FileReader.h"

#include "../../../Util/FileSystem.h"
#include "../../../Util/Log.h"


using namespace Base::Sheetmusics::IO;
using namespace Util;


FileReader::FileReader(string p)
{
	path = p;
}

ifstream * FileReader::GetStream(string name)
{
	return new ifstream(path+name);
}

SmSetInfo * FileReader::GetSmSetInfo()
{
	SmSetInfo* smSetInfo = new SmSetInfo();
	smSetInfo->path = path;
	return smSetInfo;
}

vector<string>* FileReader::WhereEndWith(string s)
{

	log(logINFO) << "FileReader::WhereEndWith : 讀取 " << s << " 路徑下的所有曲譜";

	char*** fileNames = new char**();

	int fileCount = GetFiles(path.c_str(), fileNames);

	vector<string>* files = new vector<string>();

	for (int i = 0; i < fileCount; i++) {
		log(logINFO) << "FileReader::WhereEndWith : 讀取曲譜-" << (*fileNames)[i];
		files->push_back((*fileNames)[i]);
	}

	// delete記憶體
	for (int i = 0; i < fileCount; i++) {
		free((*fileNames)[i]);
	}
	free(*fileNames);
	delete fileNames;

	return files;
}
