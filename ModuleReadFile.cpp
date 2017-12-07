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

	unsigned long counter = 0;

	while (!file.eof())
	{
		getline(file, value, ','); 
		heightMap[counter] = stoi(value);
		++counter;
	}

	return heightMap;
}


