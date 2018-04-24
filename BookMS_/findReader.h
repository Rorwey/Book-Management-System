#pragma once
#include "rDatabase.h"
class findReader
{
public:
	findReader();
	~findReader();
	int findReaderbyNo(rDatabase rd);
	int findReaderbyName(rDatabase rd);
};

