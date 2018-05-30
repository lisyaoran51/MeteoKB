#ifndef METEOR_PLAYFIELD_H
#define METEOR_PLAYFIELD_H

#include "../../Base/Play/Playfield.h"
#include "../../Util/MtoType.h"

using namespace Util;
using namespace Base::Play;
using namespace Base::Scheduler::Events;

namespace Meteor {
namespace Play{

	class MeteorPlayfield: public Playfield {

		int load();

		int load(MeteorConfigManager* m);

	protected:

		Pitch startPitch;

		int pitchCount;

	};

}
}












#endif