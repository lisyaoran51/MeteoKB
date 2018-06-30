#include "SheetmusicManager.h"


using namespace Base::Sheetmusics;
using namespace std;

SmManager::SmManager()
{
	smInfos = new vector<SmInfo*>();
	rulesetInfos = new vector<RulesetInfo*>();
	// TODO: 從資料庫中加入每個ruleset info? 應該在sm manager外面手動加
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

		SmDecoder* smDecoder = SmDecoder::GetDecoder(stream);

		Sm<Event>* sm = smDecoder->Decode(stream);
		sm->GetSmInfo()->path = smNames->at(i);

		// TODO: 把這段佔實的code改好，正確做法應該不是從filereader拿sm set info，要去trace osu的寫法
		sm->GetSmInfo()->smSetInfo = fileReader.GetSmSetInfo();

		// 寫到這邊 不知道怎麼建ruleset---> 在建立sm  manager時手動把ruleset info加入
		RulesetInfo* rulesetInfo;

		for (int i = 0; i < rulesetInfos->size(); i++){
			if (rulesetInfos->at(i)->GetId() == sm->GetSmInfo()->rulesetId) {
				rulesetInfo = rulesetInfos->at(i);
				break;
			}
		}

		sm->GetSmInfo()->rulesetInfo = rulesetInfo;

		smInfos->push_back(sm->GetSmInfo());
	}



	return smInfos;
}
