#include "Globals.h"
#include "Application.h"
#include "ModuleReadFile.h"
#include <fstream>
#include <iostream>

ModuleReadFile::ModuleReadFile()
{
}

ModuleReadFile::~ModuleReadFile()
{
}

int* ModuleReadFile::readHeightMap(const std::string path)
{
	std::ifstream file(path); 
	std::string value;

	int* heightMap = new int[SCREEN_HEIGHT*SCREEN_WIDTH];
	std::fill_n(heightMap, SCREEN_HEIGHT*SCREEN_WIDTH, 5);
	
	unsigned long counter = 0;

	while (!file.eof())
	{
		getline(file, value, ','); 
		if (value != "5")
		{
			heightMap[counter] = stoi(value);
		}
		++counter;
	}
	

	return heightMap;
}

int* ModuleReadFile::readTextureMap(const std::string path)
{
	std::ifstream file(path);
	std::string value;

	int* textureMap = new int[SCREEN_HEIGHT*SCREEN_WIDTH];
	memset(textureMap, 0, sizeof(int)*(SCREEN_HEIGHT*SCREEN_WIDTH));

	unsigned long counter = 0;

	while (!file.eof())
	{
		getline(file, value, ',');
		if (value != "0")
		{
			textureMap[counter] = stoi(value);
		}
		++counter;
	}


	return textureMap;
}


