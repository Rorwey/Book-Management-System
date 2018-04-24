#pragma once
#include "Reader.h"
class editReader
{
public:
	editReader();
	~editReader();
	editReader(Reader re);
	void readerEditMenu();//¶ÁÕßĞŞ¸Ä²Ëµ¥
	int readerEditTools(Reader re);
	int editReaderName(Reader re);
	bool delReader(Reader re);
};

