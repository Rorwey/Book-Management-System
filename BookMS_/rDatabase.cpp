#include "rDatabase.h"
#include <fstream>
#include <iostream>
#include "findReader.h"
using namespace std;


rDatabase::rDatabase()
{
	Reader rd;
  top = -1;
  fstream file("reader.txt", ios::in); //打开文件
  while (1)
  {
   file.read((char *)&rd, sizeof(rd));
   if (!file) break;
   top++;
   rdArray[top] = rd;
  }
  file.close();  //关闭文件  
}


rDatabase::~rDatabase()
{
	fstream file("reader.txt", ios::out);
	for (int i = 0; i <= top; i++)
	{
		Reader re = rdArray[i];
		if (re.isDel())//如果没有删除
			file.write((char *)&rdArray[i], sizeof(rdArray[i]));
	}
	file.close();
}

Reader rDatabase::getRdarray()
{
	return rdArray[RMAX];
}

int rDatabase::getSize()
{
	return top;
}

void rDatabase::setTop(int t)
{
	top = t;
}
void readerchamain()                                                     //图书查找子菜单
{
	cout << "****************************" << endl;
	cout << "*         图书查找         *" << endl;
	cout << "*        (1)学号查找          *" << endl;
	cout << "*        (2)姓名查找          *" << endl;
	cout << "*        (3)返回上一层     *" << endl;
	cout << "****************************" << endl;
}
int rDatabase::findReaders(rDatabase rd)
{
	char in;
	findReader fr;
	int index;
	int top = rd.getSize();
	do {
		readerchamain();
		cin >> in;
		switch (in)
		{
		case '1':
			index = fr.findReaderbyNo(rd);
			rd.rdArray[index].showReader();
			return index;
			break;
		case '2':
			index = fr.findReaderbyName(rd);
			rd.rdArray[index].showReader();
			return index;
			break;
		case '3':
			return -1;
			break;
		default:cout << "输入错误，请从新输入。" << endl;;
		}
	} while (in != '5');
	return -1;
}

void rDatabase::addreaders()
{
	Reader rd;
	int no;
	int rs;
	char rname[20];
	cout << "请输入学号: ";
	cin >> no;
	cout << endl << "请输入姓名: ";
	cin >> rname;
	cout << endl << "请输入性别（1为男，0为女）：";
	cin >> rs;
	cout << endl;
	rd.addreader(no, rname, rs);
	/*rd.setBor(false);*/
	top++;
	rdArray[top] = rd;
	return;
}

int rDatabase::isInDBbyNo(int no, rDatabase rd)
{
	for (int i = 0; i <= top; i++)
	{
		if (rd.rdArray[i].getNo() == no && !rd.rdArray[i].isDel())
		{
			return i;//找到了就把人在数组的位置还回去
		}
	}
	return -1;
}

int rDatabase::isInDbbyName(char name[20], rDatabase rd)
{
	for (int i = 0; i <= top; i++)
	{
		if (strcmp(rd.rdArray[i].getName(),name) && rd.rdArray[i].isDel() == false)
		{
			return i;//找到了就把人在数组的位置还回去
		}
	}
	return -1;
}

void rDatabase::showAllReaders()
{
	char value[3];
	for (int i = 0; i <= top; i++)
	{

		if (!rdArray[i].isDel())
		{
			if (rdArray[i].isBor()) strcpy_s(value, "借");
			else strcpy_s(value, "无");			
			cout << "学号: " << rdArray[i].getNo() << " 姓名: " << rdArray[i]. getName()<< " 是否借书: " << value << endl;
		}
	}
	return;
}
