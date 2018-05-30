#include "MeteorPlayfield.h"

using namespace Meteor::Play;


int MeteorPlayfield::load()
{
	MeteorConfigManager* m = GetCache<MeteorConfigManager>("MeteorConfigManager");

	if (!m)
		throw runtime_error("int MeteorPlayfield::load() : MeteorConfigManager not found in cache.");

	return load(m);
}

int MeteorPlayfield::load(MeteorConfigManager * m)
{

	startPitch = m->Get<Pitch>(MeteorSettingStartPitch);
	pitchCount = m->Get<int>(MeteorSettingPitchCount);

	return 0;
}


