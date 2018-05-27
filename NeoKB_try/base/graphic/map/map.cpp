#include "Map.h"


using namespace Base::Graphic::Map;







Map::Map(int w, int h)
{
	width = w;
	height = h;

	map = new int*[h];
	for (int i = 0; i < h; i++) {
		map[i] = new int[w];
	}
}

Map::~Map()
{
	for (int i = 0; i < height; i++) {
		delete [] map[i];
		delete[] defaultMap[i];
	}
	delete[] map;
	delete[] defaultMap;
}

/// <summary>
/// 每一次frame都要先把map重置一次再開始畫
/// </summary>
int Map::Reset()
{

	// TODO: 應該用memory copy之類技術比較快
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = defaultMap[i][j];
		}
	}

	return 0;
}
