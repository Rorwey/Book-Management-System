//读者数据库类
#pragma once
#include "Reader.h"
const int RMAX = 50;   //人最多个数

class rDatabase
{
public:
	Reader rdArray[RMAX];
	int top;
public:
	rDatabase();
	~rDatabase();
	Reader getRdarray();
	int getSize();
	void setTop(int t);
	int findReaders(rDatabase rd); //查找图书
	void addreaders();
	int isInDBbyNo(int no,rDatabase rd);//判断读者是否在数据库
	int isInDbbyName(char name[20], rDatabase rd);
	void showAllReaders();
};

