#include "FileReader.h"

#include "../../../Util/FileSystem.h"
#include "../../../Util/Log.h"
#include <string.h>


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

	LOG(LogLevel::Info) << "FileReader::WhereEndWith(string) : read all sheetmusics under [" << s << "].";

	char*** fileNames = new char**();

	int fileCount = GetFiles(path.c_str(), fileNames);

	vector<string>* files = new vector<string>();

	for (int i = 0; i < fileCount; i++) { LOG(LogLevel::Debug) << (*fileNames)[i]; }

	for (int i = 0; i < fileCount; i++) {

		int len = strlen((*fileNames)[i]);
		
		LOG(LogLevel::Debug) << (*fileNames)[i];

		if (len >= 2 && strcmp((*fileNames)[i] + len - 2, ".sm") == 1) {

			LOG(LogLevel::Info) << "FileReader::WhereEndWith : sheetmusic read : [" << (*fileNames)[i] << "]";
			files->push_back((*fileNames)[i]);

		}
		else if (len >= 2){
			LOG(LogLevel::Debug) << "FileReader::WhereEndWith : not sm : [" << (*fileNames)[i] << "]. the last words are ["
				<< (*fileNames)[i] + len - 2 << "]";
		}
	}

	// delete�O����
	for (int i = 0; i < fileCount; i++) {
		free((*fileNames)[i]);
	}
	free(*fileNames);
	delete fileNames;

	return files;
}
