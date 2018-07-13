#include "WorkingSheetmusic.h"


using namespace Base::Sheetmusics;
using namespace Base::Sheetmusics::Format;


WorkingSm::WorkingSm(SmInfo * s)
{
	smInfo = s;
	if (s->metadata)
		smMetadata = new SmMetadata(s->metadata);
	else
		smMetadata = new SmMetadata();
}

WorkingSm::~WorkingSm()
{
	// �T�w���O�o��Ӥs��??
	delete sm;
	delete smMetadata;
	delete smInfo;
}

Sm<Event>* WorkingSm::GetSm()
{
	if (sm)
		return sm;

	sm = createSm();

	// use the database-backed info.
	sm->SetSmInfo(smInfo);

	return sm;
}

Sm<Event>* WorkingSm::createSm()
{
	Sm<Event>* s;

	// get path for file�O�b�o��sm set�̭���L�̥�����path�A�M���path�M�ɦW�a�b�@�_�A�^��
	ifstream* stream = new ifstream(getPathForFile(smInfo->path));

	SmDecoder* smDecoder = SmDecoder::GetDecoder(stream);
	s = smDecoder->Decode(stream);

	return s;
}

string WorkingSm::getPathForFile(string fileName)
{
	string s = smSetInfo->path + fileName;
	return s;
}
