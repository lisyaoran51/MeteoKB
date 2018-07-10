#include "SimpleSmDecoder.h"



using namespace Base::Sheetmusics::Format;
using namespace std;
using namespace Base::Sheetmusics;


/*
 * 切字串的方法
 * https://blog.csdn.net/Vincentlmeng/article/details/73201188
 * https://www.cnblogs.com/MikeZhang/archive/2012/03/24/MySplitFunCPP.html
 */




int SimpleSmDecoder::handleGeneral(Sm<Event>* sm, string & line)
{
	vector<string> pair = split(line, ":");

    SmMetadata* metadata = sm->GetSmInfo()->metadata;

	if (pair.at(0) == "AudioFilename") {
		metadata->AudioFile = pair.at(1);
	}
	else if (pair.at(0) == "AudioLeadIn") {
		sm->GetSmInfo()->audioLeadIn = atoi(pair.at(1).c_str());
	}
	else if (pair.at(0) == "PreviewTime") {
		metadata->PreviewTime = atoi(pair.at(1).c_str());
	}
	else if (pair.at(0) == "Countdown") {
		//metadata->AudioFile = pair.at(1);
	}
	else if (pair.at(0) == "SampleSet") {
		//metadata->AudioFile = pair.at(1);
	}
	else if (pair.at(0) == "SampleVolume") {
		//metadata->AudioFile = pair.at(1);
	}
	else if (pair.at(0) == "StackLeniency") {
		//metadata->AudioFile = pair.at(1);
	}
	else if (pair.at(0) == "Mode") {
		sm->GetSmInfo()->rulesetId = atoi(pair.at(1).c_str());
	}
	else if (pair.at(0) == "LetterboxInBreaks") {
		//metadata->AudioFile = pair.at(1);
	}
	else if (pair.at(0) == "SpecialStyle") {
		//metadata->AudioFile = pair.at(1);
	}
	
    
	return 0;
}

int SimpleSmDecoder::handleMetadata(Sm<Event>* sm, string & line)
{
	vector<string> pair = split(line, ":");

	SmMetadata* metadata = sm->GetSmInfo()->metadata;

	if (pair.at(0) == "Title") {
		metadata->Title = pair.at(1);
	}
	else if (pair.at(0) == "TitleUnicode") {
		//sm->GetSmInfo()->audioLeadIn = atoi(pair.at(1).c_str());
	}
	else if (pair.at(0) == "Artist") {
		metadata->Artist = pair.at(1);
	}
	else if (pair.at(0) == "ArtistUnicode") {
		//metadata->AudioFile = pair.at(1);
	}
	else if (pair.at(0) == "Creator") {
		metadata->Author = pair.at(1);
	}
	else if (pair.at(0) == "Version") {
		sm->GetSmInfo()->version = atoi(pair.at(1).c_str());
	}
	else if (pair.at(0) == "Source") {
		//metadata->AudioFile = pair.at(1);
	}
	else if (pair.at(0) == "Tags") {
		sm->GetSmInfo()->rulesetId = atoi(pair.at(1).c_str());
	}
	else if (pair.at(0) == "SheetmusicID") {
		//metadata->AudioFile = pair.at(1);
	}
	else if (pair.at(0) == "SheetmusicSetID") {
		//metadata->AudioFile = pair.at(1);
	}

	switch (pair.Key) {
        case @"Title":
            metadata.Title = pair.Value;
            break;
        case @"TitleUnicode":
            metadata.TitleUnicode = pair.Value;
            break;
        case @"Artist":
            metadata.Artist = pair.Value;
            break;
        case @"ArtistUnicode":
            metadata.ArtistUnicode = pair.Value;
            break;
        case @"Creator":
            metadata.AuthorString = pair.Value;
            break;
        case @"Version":
            sheetmusic.SheetmusicInfo.Version = pair.Value;
            break;
        case @"Source":
            sheetmusic.SheetmusicInfo.Metadata.Source = pair.Value;
            break;
        case @"Tags":
            sheetmusic.SheetmusicInfo.Metadata.Tags = pair.Value;
            break;
        case @"SheetmusicID":
            sheetmusic.SheetmusicInfo.OnlineSheetmusicID = int.Parse(pair.Value);
            break;
        case @"SheetmusicSetID":
            sheetmusic.SheetmusicInfo.OnlineSheetmusicSetID = int.Parse(pair.Value);
            metadata.OnlineSheetmusicSetID = int.Parse(pair.Value);
            break;
    }

	return 0;
}

int SimpleSmDecoder::handleDifficulty(Sm<Event>* sm, string & line)
{
	return 0;
}

int SimpleSmDecoder::handleNoteControlPoints(Sm<Event>* sm, string & line)
{
	return 0;
}

vector<string> SimpleSmDecoder::split(string s, string pattern)
{
	string::size_type pos;
     vector<string> result;
     s+=pattern;//扩展字符串以方便操作
     int size=s.size();
 
     for(int i=0; i<size; i++)
     {
         pos=s.find(pattern,i);
         if(pos<size)
         {
             string split=s.substr(i,pos-i);
             result.push_back(split);
             i=pos+pattern.size()-1;
         }
     }
     return result;
}

SimpleSmDecoder::SimpleSmDecoder(): RegisterType("SimpleSmDecoder")
{
}

int SimpleSmDecoder::setSectionMap()
{
	return 0;
}

int SimpleSmDecoder::parseFile(ifstream * stream, Sm<Event>* sm)
{
	string line;

	do {

		getline(*stream, line);

	} while (!stream->eof() && line.empty());

	//sheetmusic.SheetmusicInfo.SheetmusicVersion = sheetmusicVersion;
	// rfind可能有問題，他可能是從後面算
	//sm->GetSmInfo()->smVersion = atoi(line.substr(line.rfind("v"), line.size() - line.rfind("v")).c_str());



	SimpleSmDecoderSection section = SimpleSmDecoderSection::None;
    //bool hasCustomColours = false;

	
    while (!stream->eof()) {
		getline(*stream, line);

        if (line==" " || line.empty())
            continue;

        if (line.find("//") == 0)
            continue;

        if (line.find("simple file format v") == 0) {
			sm->GetSmInfo()->smVersion = atoi(line.substr(20, line.size() - 20).c_str());
            continue;
        }

        if (line.find("[") == 0 && line.rfind("]") == line.size() - 1) {
            section = GetSectionEnum(line.substr(1, line.size()-2));
            continue;
        }

        switch (section) {
		case SimpleSmDecoderSection::General:
                handleGeneral(sm, line);
                break;
		case SimpleSmDecoderSection::Metadata:
                handleMetadata(sm, line);
                break;
		case SimpleSmDecoderSection::Difficulty:
                handleDifficulty(sm, line);
                break;
            //case Section.Events:
            //    handleEvents(sheetmusic, line, ref storyboardSprite, ref timelineGroup);
            //    break;
		case SimpleSmDecoderSection::NoteControlPoints:
                handleNoteControlPoints(sm, line);
                break;
            //case Section.Colours:
            //    handleColours(sheetmusic, line, ref hasCustomColours);
            //    break;
		//case SimpleSmDecoderSection::HitObjects:

                // If the ruleset wasn't specified, assume the osu!standard ruleset.
                //if (parser == null)
                //    parser = new Rulesets.Objects.Parsers.ConvertHitObjectParser();
				//
                //var obj = parser.Parse(line);
				//
                //if (obj != null)
                //    sheetmusic.HitObjects.Add(obj);
				//
                //break;
            //case Section.Variables:
            //    handleVariables(line);
            //    break;
        }
    }

    foreach (var hitObject in sheetmusic.HitObjects)
        hitObject.ApplyDefaults(sheetmusic.ControlPointInfo, sheetmusic.SheetmusicInfo.BaseDifficulty);



	return 0;
}
