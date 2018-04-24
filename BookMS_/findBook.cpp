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
	cout << endl << "���������: ";
	cin >> no;
	return bd.isInDBbyNo(no,bd);	
}

int findBook::findBookbyName(bDatabase bd)
{
	char bname[20];
	cout << endl <<endl << "����������: ";
	cin >> bname;
	return bd.isInDbbyName(bname, bd);
}

int findBook::findBookbyAuthor(bDatabase bd)
{
	char bau[20];
	cout << endl << "����������: ";
	cin >> bau;
	return bd.isInDBbyAuthor(bau, bd);
}
