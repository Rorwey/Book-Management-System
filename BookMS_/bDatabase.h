#pragma once
#include <deque>
#include "Book.h"

const int BMAX = 100;   //书最多个数

class bDatabase
{
public:
	Book btarray[BMAX];                                         //图书集合
	int top;
public:
	bDatabase() ;
	~bDatabase();
	Book getBtarray();
	int getSize();
	int setTop(int s);	
	int initBtarray(Book bk);//从数据库中读取图书，初始化图书馆
	int findBooks(bDatabase bd); //查找图书
	int isInDBbyNo(int no, bDatabase bd);//判断图书是否在书库
	int isInDBbyAuthor(char* Author, bDatabase bd);
	int isInDbbyName(char* Name, bDatabase bd);
	void addBooks();
	bool delbooks(Book bk);
	void showAllBooks();
};

