#ifndef MAP_H
#define MAP_H




namespace Base {
namespace Graphic {
namespace Map {

	class Map {

		int** map;

		int** defaultMap;

		int width;
		int height;

	public:

		Map(int w, int h);

		~Map();

		int Add(int x, int y, int v);

		int Set(int x, int y, int v);

		/// <summary>
		/// �C�@��frame���n����map���m�@���A�}�l�e
		/// </summary>
		int Reset();

		/// <summary>
		/// set the map now as the default map. after reset the map, the default map value would be the map now
		/// </summary>
		virtual int SetDefault();
	};




}}}




#endif