#include "Book.h"
#include <string>
#include<iostream>
using namespace std;

Book::Book()
{
}


Book::~Book()
{
}

void Book::setNo(int n)
{
	no = n;
}

int Book::getNo()
{
	return no;
}

void Book::setPrice(int p)
{
	price = p;
}

int Book::getPrice()
{
	return price;
}

void Book::setName(char na[])
{
	strcpy_s(name, na); //�������ֵ����name
}

char * Book::getName()
{
	return name;
}

void Book::setAuthor(char a[])
{
	strcpy_s(author, a);
}

char * Book::getAuthor()
{
	return author;
}

bool Book::isBor()
{
	return is_rent;
}

bool Book::isDel()
{
	return is_del;
}

bool Book::borBook(bool b)
{
	is_rent = b; 
	return true;
}

int Book::delBook()
{
	if (is_rent)
		cout << "ͼ�鱻�������ȴ��黹����ɾ��" << endl;
	return false;
	is_del = true; //�鼮ɾ��
	return true;
}

int Book::newBook(int no, char na[], char author[], int price)
{
	setNo(no);
	setName(na);
	setAuthor(author);
	setPrice(price);
	is_rent = false;
	is_del = false;
	return 1;
}

void Book::showBook()
{
	char value[6];
	if (!is_del)
	{
		if (isBor()) strcpy_s(value, "�ڼ�");
		else
		{
			strcpy_s(value, "���");
		}
		cout << "��ţ�" << no << " ���ƣ�" << name << " ���ߣ�" << author << " �۸�" << price << " ���ߣ�" << author << "�����" << value << endl;
	}
	else
	{
		cout << "�Ȿ���Ѿ���ɾ���ˣ�" << endl;
	}
}
