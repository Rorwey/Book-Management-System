#include "Reader.h"
#include <string>
#include <iostream>
using namespace std;

Reader::Reader()
{
}


Reader::~Reader()
{
}


int Reader::getNo()
{
	return 0;
}

bool Reader::setNo(int n)
{
	no = n;
	return true;
}

int Reader::getSex()
{
	return sex;
}

bool Reader::setSex(int s)
{
	sex = s;
	return true;
}

bool Reader::isDel()
{
	return is_del;
}

bool Reader::delReader()
{
	if (is_bor)
	{
		cout << "该用户借了图书，请还书后再删除" << endl;
		return false;
	}
	is_del = true;
	return is_del;
}

bool Reader::isBor()
{
	return is_del;
}

bool Reader::setBor(bool b)
{
	is_bor = b;
	return true;
}

Book Reader::getBrBook()
{
	return brbook;
}

bool Reader::setBrBook(Book bt)
{
	brbook = bt;
	return true;
}

void Reader::showReader()
{
	char value[6];
	if (!is_del)
	{
		if (isBor()) strcpy_s(value, "有借");
		else
		{
			strcpy_s(value, "没借");
		}
		cout << "学号：" << no << " 姓名：" << name <<  "借了书？" << value << endl;
	}
	else
	{
		cout << "这个人已经被删掉了！" << endl;
	}
}

void Reader::addreader(int id, char na[], int s)
{
	setNo (id);
	setSex(s);
	setName(na);
	is_del = false;
	is_bor = false;
}

char* Reader::getName()
{
	return name;
}

bool Reader::setName(char na[])
{
	strcpy_s(name, na); //将输入的值赋给name
	return true;
}
