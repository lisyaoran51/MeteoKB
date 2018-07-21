#include "Map.h"

#include <cstring>

using namespace Base::Graphic::Maps;







Map::Map(int w, int h)
{
	width = w;
	height = h;

	// 參考 http://mropengate.blogspot.com/2015/12/cc-dynamic-2d-arrays-in-c.html

	// new一個二微陣列
	matrix = (uint8_t**)new uint8_t(width * height * sizeof(uint8_t));
	for (int i = 0; i < height; i++)
		matrix[i] = ((uint8_t*)(matrix+height)) + i * width + sizeof(uint8_t);

	defaultMatrix = (uint8_t**)new uint8_t(width * height * sizeof(uint8_t));
	for (int i = 0; i < height; i++)
		defaultMatrix[i] = ((uint8_t*)(defaultMatrix + height)) + i * width + sizeof(uint8_t);


	// TODO: 改成用memset做比較快
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			matrix[i][j] = 0;
			defaultMatrix[i][j] = 0;
		}
	}
	clear = true;
}

Map::~Map()
{
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

uint8_t Map::Get(int x, int y)
{
	return ((uint8_t*)matrix)[x * height + y];
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
