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
	fstream file("book.txt", ios::in);    //���ļ�
	while (1)
	{
		file.read((char *)&b, sizeof(b));
		if (!file) break;
		top++;
		btarray[top] = b;
		/*bd.initBtarray(b);*/
	}
	file.close();     //�ر��ļ�
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

void bookchamain()                                                     //ͼ������Ӳ˵�
{
	cout << "****************************" << endl;
	cout << "*         ͼ�����         *" << endl;
	cout << "*        (1)��Ų���          *" << endl;
	cout << "*        (2)��������          *" << endl;
	cout << "*        (3)���߲���          *" << endl;
	cout << "*        (4)������һ��     *" << endl;
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
		default:cout << "���������������롣" << endl;;
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
			return i;//�ҵ��˾Ͱ����������λ�û���ȥ
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
			return i;//�ҵ��˾Ͱ����������λ�û���ȥ
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
			return i;//�ҵ��˾Ͱ����������λ�û���ȥ
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
	cout << endl << "���������: ";
	cin >> no;
	cout << endl << "����������: ";
	cin >> bname;
	cout << endl << "����������: ";
	cin >> bau;
	cout << endl << "������۸�: ";
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
	bk.showBook(); cout << "��Ҫɾ����" << endl;
	if (bk.isBor())                              //ɾ��ʱ�ж�ͼ���Ƿ���
	{
		cout << "��ͼ���Ѿ���������ڹ黹����ɾ����" << endl;
		return false;
	}	
	
	bk.delBook(); //ɾ��ͼ��
	cout << "��ͼ���Ѿ�ɾ����" << endl;
	return true;
}

void bDatabase::showAllBooks()
{
		char value[6];
		for (int i = 0; i <= top; i++)
		{
			if (btarray[i].isDel() == false)
			{
				if (btarray[i].isBor() == false) strcpy_s(value, "�ڼ�");
				if (btarray[i].isBor() == true) strcpy_s(value, "���");
				cout << "���: " << btarray[i].getNo() << " �������: " << btarray[i].getName() << " ͼ��״̬ :" << value << endl;
			}
		}
		return;
}
