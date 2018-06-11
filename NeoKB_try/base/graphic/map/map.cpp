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
	// TODO: ��std::copy�g
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
/// �C�@��frame���n����map���m�@���A�}�l�e
/// </summary>
int Map::Reset()
{

	// TODO: ���ӥ�memory copy�����޳N�����
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			matrix[i][j] = defaultMatrix[i][j];
		}
	}

	return 0;
}

int Map::SetDefault()
{
	// TODO: ���ӥ�memory copy�����޳N�����
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			defaultMatrix[i][j] = matrix[i][j];
		}
	}
	return 0;
}
