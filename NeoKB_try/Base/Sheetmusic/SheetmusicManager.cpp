#include "SheetmusicManager.h"


using namespace Base::Sheetmusics;
using namespace std;

SmManager::SmManager()
{
	smInfos = new vector<SmInfo*>();
	rulesetInfos = new vector<RulesetInfo*>();
	// TODO: �q��Ʈw���[�J�C��ruleset info? ���Ӧbsm manager�~����ʥ[
}

SmManager::~SmManager()
{
	for (int i = 0; i < smInfos->size(); i++)
		delete smInfos->at(i);
	for (int i = 0; i < rulesetInfos->size(); i++)
		delete rulesetInfos->at(i);

	delete smInfos;
	delete rulesetInfos;
}

int SmManager::RegisterRulesetInfo(RulesetInfo * r)
{
	rulesetInfos->push_back(r);
	return 0;
}

int SmManager::Import(vector<string>* paths)
{
	for (int i = 0; i < paths->size(); i++) {
		FileReader fileReader(paths->at(i));
		import(fileReader);
	}

	return 0;
}

vector<SmInfo*>* SmManager::GetSmInfos()
{
	return smInfos;
}

WorkingSm * SmManager::GetWorkingSm(SmInfo * s)
{
	return new WorkingSm(s);
}

vector<SmInfo*>* SmManager::import(FileReader & fileReader)
{
	return importToStorage(fileReader);
}

vector<SmInfo*>* SmManager::importToStorage(FileReader & fileReader)
{
	vector<string>* smNames;

	smNames = fileReader.WhereEndWith(".sm");

	for (int i = 0; i < smNames->size(); i++) {

		ifstream* stream = fileReader.GetStream(smNames->at(i));

		// �C�@�ӭn�Ϊ�decoder�|�b�{���}�l���ɭԵ��U
		SmDecoder* smDecoder = SmDecoder::GetDecoder(stream);

		Sm<Event>* sm = smDecoder->Decode(stream);
		sm->GetSmInfo()->path = smNames->at(i);

		// TODO: ��o�q���ꪺcode��n�A���T���k���Ӥ��O�qfilereader��sm set info�A�n�htrace osu���g�k
		sm->GetSmInfo()->smSetInfo = fileReader.GetSmSetInfo();

		// �g��o�� �����D����ruleset---> �b�إ�sm  manager�ɤ�ʧ�ruleset info�[�J
		RulesetInfo* rulesetInfo = NULL;

		for (int i = 0; i < rulesetInfos->size(); i++){
			if (rulesetInfos->at(i)->GetId() == sm->GetSmInfo()->rulesetId) {
				rulesetInfo = rulesetInfos->at(i);
				break;
			}
		}

		if(rulesetInfo)
			sm->GetSmInfo()->rulesetInfo = rulesetInfo;
		else{
			// TODO: �Q���~
		}

		smInfos->push_back(sm->GetSmInfo());
	}



	return smInfos;
}