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
	cout << endl << "请输入学号: ";
	cin >> no;
	return rd.isInDBbyNo(no,rd);
}

int findReader::findReaderbyName(rDatabase rd)
{
		char name[20];
		cout << endl << endl << "请输入姓名: ";
		cin >> name;
		return rd.isInDbbyName(name,rd);

}
