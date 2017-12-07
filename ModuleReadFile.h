#pragma once

#include "Module.h"
#include <string>

class ModuleReadFile : public Module
{

public:
	ModuleReadFile();
	~ModuleReadFile();

	int* readHeightMap(const std::string path);
};

