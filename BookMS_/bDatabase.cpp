#include "bDatabase.h"
#include <fstream>
#include <iostream>
#include "Book.h"
#include "findBook.h"
using namespace std;


bDatabase::bDatabase()
{
	Book b;
	
	top = -1;
	fstream file("book.txt", ios::in);    //打开文件
	while (1)
	{
		file.read((char *)&b, sizeof(b));
		if (!file) break;
		top++;
		btarray[top] = b;
		/*bd.initBtarray(b);*/
	}
	file.close();     //关闭文件
}


bDatabase::~bDatabase()
{
	
	fstream file("book.txt", ios::out);
	for (int i = 0; i <= top; i++)
	{
		if (!btarray[i].isDel())
			file.write((char *)&btarray[i], sizeof(btarray[i]));
	}
	file.close();
}

int bDatabase::getSize()
{
	return top;
}

int bDatabase::setTop(int s)
{
	top = s;
	return 1;
}

Book bDatabase::getBtarray()
{
	return btarray[BMAX];
}

void bookchamain()                                                     //图书查找子菜单
{
	cout << "****************************" << endl;
	cout << "*         图书查找         *" << endl;
	cout << "*        (1)书号查找          *" << endl;
	cout << "*        (2)书名查找          *" << endl;
	cout << "*        (3)作者查找          *" << endl;
	cout << "*        (4)返回上一层     *" << endl;
	cout << "****************************" << endl;
}

int bDatabase::initBtarray(Book b)
{
	int top = getSize();
	top = top++;
	setTop(top);
	btarray[top]=b;
	return 1;
}

int bDatabase::findBooks(bDatabase bd)
{
	char in;
	/*bDatabase bd;*/
	findBook fb;
	int index;
	int top = bd.getSize();
	do {
		bookchamain();
		cin >> in;
		switch (in)
		{
		case '1':
			index = fb.findBookbyNo(bd);
			bd.btarray[index].showBook();
			return index;
			break;
		case '2':
			index = fb.findBookbyAuthor(bd);
			bd.btarray[index].showBook();
			return index;
			break;
		case '3':
			index = fb.findBookbyName(bd);
			bd.btarray[index].showBook();
			return index;
			break;
		case '4':
			return -1;
			break;
		default:cout << "输入错误，请从新输入。" << endl;;
		}
	} while (in != '5');
	return -1;
}

int bDatabase::isInDBbyNo(int no,bDatabase bd)
{
	for (int i = 0; i <= top; i++)
	{
		if (bd.btarray[i].getNo() == no && !bd.btarray[i].isDel() )
		{
			return i;//找到了就把书在数组的位置还回去
		}		
	}
	return -1;
}

int bDatabase::isInDBbyAuthor(char* Author, bDatabase bd)
{
	for (int i = 0; i <= top; i++)
	{
		char *buf1 = bd.btarray[i].getAuthor();
		char *buf2 = Author;		
		if (strncmp(buf1, buf2,3) && !bd.btarray[i].isDel() )
		{
			return i;//找到了就把书在数组的位置还回去
		}
	}
	return -1;
}

int bDatabase::isInDbbyName(char* Name, bDatabase bd)
{
	for (int i = 0; i <= top; i++)
	{
		if (bd.btarray[i].getName() == Name && bd.btarray[i].isDel() == 0)
		{
			return i;//找到了就把书在数组的位置还回去
		}
	}
	return -1;
}

void bDatabase::addBooks()
{	
	Book bk;
	findBook fb;
	int no;
	char bname[20];
	char bau[20];
	int pr;
	cout << endl << "请输入书号: ";
	cin >> no;
	cout << endl << "请输入书名: ";
	cin >> bname;
	cout << endl << "请输入作者: ";
	cin >> bau;
	cout << endl << "请输入价格: ";
	cin >> pr;
	cout << endl;

	bk.newBook(no, bname, bau, pr);	
	bk.showBook();
	top++;
	btarray[top] = bk;
	return;
}

bool bDatabase::delbooks(Book bk)
{
	bk.showBook(); cout << "将要删除。" << endl;
	if (bk.isBor())                              //删除时判断图书是否借出
	{
		cout << "该图书已经借出，请在归还后再删除。" << endl;
		return false;
	}	
	
	bk.delBook(); //删除图书
	cout << "该图书已经删除。" << endl;
	return true;
}

void bDatabase::showAllBooks()
{
		char value[6];
		for (int i = 0; i <= top; i++)
		{
			if (btarray[i].isDel() == false)
			{
				if (btarray[i].isBor() == false) strcpy_s(value, "在架");
				if (btarray[i].isBor() == true) strcpy_s(value, "借出");
				cout << "书号: " << btarray[i].getNo() << " 书的名称: " << btarray[i].getName() << " 图书状态 :" << value << endl;
			}
		}
		return;
}
