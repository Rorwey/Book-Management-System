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
	strcpy_s(name, na); //将输入的值赋给name
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
		cout << "图书被借出，请等待归还后再删除" << endl;
	return false;
	is_del = true; //书籍删除
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
		if (isBor()) strcpy_s(value, "在架");
		else
		{
			strcpy_s(value, "借出");
		}
		cout << "书号：" << no << " 名称：" << name << " 作者：" << author << " 价格：" << price << " 作者：" << author << "借出：" << value << endl;
	}
	else
	{
		cout << "这本书已经被删掉了！" << endl;
	}
}
