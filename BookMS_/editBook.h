#pragma once
#include "Book.h"

class editBook
{
public:
	editBook();
	editBook(Book bk);
	~editBook();
	void bookEditMenu();                                                    //ͼ���޸Ĳ˵�
	int bookEditTools(Book bk);
	int editBookName(Book bk);
	int editBookAuthor(Book bk);
	int editBookPrice(Book bk);
};

