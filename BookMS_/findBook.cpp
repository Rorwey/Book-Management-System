#include "findBook.h"
#include <iostream>
#include "bDatabase.h"
using namespace std;

findBook::findBook()
{
}


findBook::~findBook()
{
}

int findBook::findBookbyNo(bDatabase bd)
{
	int no;
	cout << endl << "请输入书号: ";
	cin >> no;
	return bd.isInDBbyNo(no,bd);	
}

int findBook::findBookbyName(bDatabase bd)
{
	char bname[20];
	cout << endl <<endl << "请输入作者: ";
	cin >> bname;
	return bd.isInDbbyName(bname, bd);
}

int findBook::findBookbyAuthor(bDatabase bd)
{
	char bau[20];
	cout << endl << "请输入书名: ";
	cin >> bau;
	return bd.isInDBbyAuthor(bau, bd);
}
