#ifndef MAP_H
#define MAP_H




namespace Base {
namespace Graphic {
namespace Maps {

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
		/// 每一次frame都要先把map重置一次再開始畫
		/// </summary>
		int Reset();

		/// <summary>
		/// set the map now as the default map. after reset the map, the default map value would be the map now
		/// </summary>
		virtual int SetDefault();
	};

	template<typename T>
	struct Matrix2D {
		T** mat;
		int width;
		int height;
		Matrix2D(int w, int h);
		int Clean();
	};


}}}




#endif