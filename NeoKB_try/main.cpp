#include "base/sheetmusic/io/file_reader.h"
#include "base/sheetmusic/format/sm_decoder.h"

using namespace base::sheetmusic::io;
using namespace base::sheetmusic::format;



int main(int argc, char *argv[])
{
	file_reader_t* reader;
	
	// read sheet music
	sm_decoder_t decoder(reader);

	sm_t<fall_effect_group>* sm;

	// decode sheet music to sm type
	decoder.decode(path, sm);

	// build events from sm
	vector<event_t*>* events;
	sm_event_builder_t event_builder(sm);
	events = event_builder.build();

	event_timer_t timer;
	timer.add_range(events);

	event_runner_t event_runner;
	event_to_map_converter_t event2map_cvtr;
	neokb_renderer_t renderer;

	while (running)
	{
		event_runner.update();
		running_event_t tmp_events = event_runner.get_events();
		map = event2map_cvtr(tmp_events);
		renderer.renderer(map);
		
	}



}