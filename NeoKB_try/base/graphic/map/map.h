#ifndef MAP_H
#define MAP_H




namespace base {
namespace graphic {
namespace map {

	class map_t {

		int** map;

		int** default_map;

		int width;
		int height;

	public:

		map_t(int w, int h);

		~map_t();

		int add(int x, int y, int v);

		int set(int x, int y, int v);

		int reset();

		/// <summary>
		/// set the map now as the default map. after reset the map, the default map value would be the map now
		/// </summary>
		int set_default();
	};




}}}




#endif