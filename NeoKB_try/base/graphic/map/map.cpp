#include "Map.h"


using namespace Base::Graphic::Maps;







Map::Map(int w, int h)
{
	width = w;
	height = h;

	matrix = new int*[h];
	for (int i = 0; i < h; i++) {
		matrix[i] = new int[w];
	}
}

Map::~Map()
{
	for (int i = 0; i < height; i++) {
		delete [] matrix[i];
		delete[] defaultMatrix[i];
	}
	delete[] matrix;
	delete[] defaultMatrix;
}

int ** Base::Graphic::Maps::Map::GetMatrix()
{
	return matrix;
}

int Map::Add(int x, int y, int v)
{
	matrix[x][y] += v;
	return 0;
}

int Map::Set(int x, int y, int v)
{
	matrix[x][y] = v;
	return 0;
}

int Map::PasteAdd(Map * m, int x, int y, int toX, int toY, int xLen, int yLen)
{
	int** fromMatrix = m->GetMatrix();
	for (int i = 0; i < xLen; i++) {
		if (i + toX >= width) break;
		for (int j = 0; j < yLen; j++) {
			if (j + toY >= height) break;
			matrix[toX + i][toY + j] += fromMatrix[x + i][y + j];
		}
	}
	return 0;
}

int Map::PasteSet(Map * m, int x, int y, int toX, int toY, int xLen, int yLen)
{
	// TODO: 用std::copy寫
	int** fromMatrix = m->GetMatrix();
	for (int i = 0; i < xLen; i++) {
		if (i + toX >= width) break;
		for (int j = 0; j < yLen; j++) {
			if (j + toY >= height) break;
			matrix[toX + i][toY + j] = fromMatrix[x + i][y + j];
		}
	}
	return 0;
}



/// <summary>
/// 每一次frame都要先把map重置一次再開始畫
/// </summary>
int Map::Reset()
{

	// TODO: 應該用memory copy之類技術比較快
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			matrix[i][j] = defaultMatrix[i][j];
		}
	}

	return 0;
}

int Map::SetDefault()
{
	// TODO: 應該用memory copy之類技術比較快
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			defaultMatrix[i][j] = matrix[i][j];
		}
	}
	return 0;
}
