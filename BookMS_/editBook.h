#pragma once
#include "Book.h"

class editBook
{
public:
	editBook();
	editBook(Book bk);
	~editBook();
	void bookEditMenu();                                                    //Í¼ÊéÐÞ¸Ä²Ëµ¥
	int bookEditTools(Book bk);
	int editBookName(Book bk);
	int editBookAuthor(Book bk);
	int editBookPrice(Book bk);
};

