#include "findReader.h"
#include <iostream>
using namespace std;



findReader::findReader()
{
}


findReader::~findReader()
{
}

int findReader::findReaderbyNo(rDatabase rd)
{
	int no;
	cout << endl << "������ѧ��: ";
	cin >> no;
	return rd.isInDBbyNo(no,rd);
}

int findReader::findReaderbyName(rDatabase rd)
{
		char name[20];
		cout << endl << endl << "����������: ";
		cin >> name;
		return rd.isInDbbyName(name,rd);

}
