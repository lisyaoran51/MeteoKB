#include "PatternGenerator.h"


using namespace Base::Sheetmusics::Patterns;




PatternGenerator::PatternGenerator()
{
}

PatternGenerator::~PatternGenerator()
{
	CleanPatterns();
}

int PatternGenerator::Add(Pattern * p)
{

	patterns.push_back(p);

	return 0;
}

int PatternGenerator::CleanPatterns()
{
	for (int i = 0; i < patterns.size(); i++) {
		delete patterns[i];
	}
	return 0;
}
