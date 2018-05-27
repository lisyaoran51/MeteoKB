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
/// �C�@��frame���n����map���m�@���A�}�l�e
/// </summary>
int Map::Reset()
{

	// TODO: ���ӥ�memory copy�����޳N�����
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = defaultMap[i][j];
		}
	}

	return 0;
}
