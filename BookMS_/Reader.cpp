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
		cout << "���û�����ͼ�飬�뻹�����ɾ��" << endl;
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
		if (isBor()) strcpy_s(value, "�н�");
		else
		{
			strcpy_s(value, "û��");
		}
		cout << "ѧ�ţ�" << no << " ������" << name <<  "�����飿" << value << endl;
	}
	else
	{
		cout << "������Ѿ���ɾ���ˣ�" << endl;
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
	strcpy_s(name, na); //�������ֵ����name
	return true;
}
