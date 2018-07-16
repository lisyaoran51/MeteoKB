#include "Map.h"

#include <cstring>

using namespace Base::Graphic::Maps;







Map::Map(int w, int h)
{
	width = w;
	height = h;

	matrix = new uint8_t*[h];
	for (int i = 0; i < h; i++) {
		matrix[i] = new uint8_t[w];
	}

	defaultMatrix = new uint8_t*[h];
	for (int i = 0; i < h; i++) {
		defaultMatrix[i] = new uint8_t[w];
	}
	clear = false;
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

uint8_t ** Map::GetMatrix()
{
	clear = false;
	return matrix;
}

int Map::GetWidth()
{
	return width;
}

int Map::GetHeight()
{
	return height;
}

int Map::Add(int x, int y, int v)
{
	int brightness = matrix[x][y] + v;
	if (brightness > BRIGHTNESS_MAX)
		matrix[x][y] = BRIGHTNESS_MAX;
	else
		matrix[x][y] = brightness;
	clear = false;
	return 0;
}

int Map::Set(int x, int y, int v)
{
	matrix[x][y] = v;
	if (v > BRIGHTNESS_MAX)
		matrix[x][y] = BRIGHTNESS_MAX;
	clear = false;
	return 0;

}

uint8_t Map::
(int x, int y)
{
	return matrix[x][y];
}

int Map::PasteAdd(Map * m, int x, int y, int toX, int toY, int xLen, int yLen)
{
	uint8_t** fromMatrix = m->GetMatrix();
	for (int i = 0; i < xLen; i++) {
		if (i + toX >= width) break;
		for (int j = 0; j < yLen; j++) {
			if (j + toY >= height) break;

			int brightness = matrix[toX + i][toY + j] + fromMatrix[x + i][y + j];
			if (brightness > BRIGHTNESS_MAX)
				matrix[toX + i][toY + j] = BRIGHTNESS_MAX;
			else
				matrix[toX + i][toY + j] = brightness;
		}
	}
	clear = false;
	return 0;
}

int Map::PasteSet(Map * m, int x, int y, int toX, int toY, int xLen, int yLen)
{
	// TODO: 用std::copy寫
	uint8_t** fromMatrix = m->GetMatrix();
	for (int i = 0; i < xLen; i++) {
		if (i + toX >= width) break;
		for (int j = 0; j < yLen; j++) {
			if (j + toY >= height) break;
			matrix[toX + i][toY + j] = fromMatrix[x + i][y + j];
		}
	}
	clear = false;
	return 0;
}



/// <summary>
/// 每一次frame都要先把map重置一次再開始畫
/// </summary>
int Map::Reset()
{
	/*
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			matrix[i][j] = defaultMatrix[i][j];
		}
	}
	*/

	memcpy(
		matrix[0],
		defaultMatrix[0],
		width * height);
	clear = true;

	return 0;
}

bool Map::IsClear()
{
	return clear;
}

int Map::SetDefault()
{
	/*
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			defaultMatrix[i][j] = matrix[i][j];
		}
	}
	*/

	memcpy(
		defaultMatrix[0],
		matrix[0],
		width * height);
	clear = true;
	return 0;
}
