#include "editReader.h"
#include <iostream>
using namespace std;



editReader::editReader()
{
}


editReader::~editReader()
{
}

editReader::editReader(Reader re)
{
	cout << "学号: " << re.getNo() << " 姓名: " << re.getName() << endl;
	cout << "准备修改：" << endl;
	readerEditTools(re);
	return;
}

void editReader::readerEditMenu()
{
	cout << "****************************" << endl;
	cout << "*         读者信息修改         *" << endl;
	cout << "*        (1)修改姓名          *" << endl;
	cout << "*        (2)返回上一层     *" << endl;
	cout << "****************************" << endl;
}

int editReader::readerEditTools(Reader re)
{
	char in;
	editReader ed;
	do {
		readerEditMenu();
		cin >> in;
		switch (in)
		{
		case '1':
			return ed.editReaderName(re);
			break;
		case '2':
			return -1;
			break;			
		default:cout << "输入错误，请从新输入。" << endl;;
		}
	} while (in != '3');
	return -1;
}

int editReader::editReaderName(Reader re)
{
	char name[20];
	cout << endl << "输入读者名称: ";
	cin >> name;
	re.setName(name);
	return 1;
}

bool editReader::delReader(Reader re)
{
	if (re.isBor())                              //删除时判断读者手中是否有书
	{
		cout << "该读者借了书，请在归还后再删除。" << endl;
		return false;
	}
	re.delReader(); //删除图书
	cout << "该读者已经删除。" << endl;
	return true;
}
