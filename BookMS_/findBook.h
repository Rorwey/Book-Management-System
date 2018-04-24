#pragma once
#include "bDatabase.h"
class findBook
{
public:
	findBook();
	~findBook();
	int findBookbyNo(bDatabase bd);
	int findBookbyAuthor(bDatabase bd);
	int findBookbyName(bDatabase bd);
};

