#pragma once

#include "Point.h"
#include <vector>

using namespace std;

class Path
{
public:
	Path() {}
	~Path() {}

	void addNode(fPoint node) {
		nodes.push_back(node);
	}

public:
	vector<fPoint> nodes;
};