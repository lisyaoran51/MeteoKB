#include "playfield.h"
#include "Playfield.h"



using namespace Base::Play;



int Playfield::Add(EventProcessor * ep)
{
	scheduler->Add(ep);
	return 0;
}
