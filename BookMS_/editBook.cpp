#include "editBook.h"
#include <iostream>
#include "Book.h"
using namespace std;

editBook::editBook() {};
editBook::editBook(Book bk)
{
	cout << "���: " << bk.getNo() << " ����: " << bk.getName() << " ����: " << bk.getAuthor() << " �۸�: " << bk.getPrice() << endl;
	cout << "׼���޸ģ�" << endl;
	bookEditTools(bk);
	return;
}


editBook::~editBook()
{
}

void editBook::bookEditMenu()
{
		cout << "****************************" << endl;
		cout << "*          ͼ���޸�         *" << endl;
		cout << "*        (1)�޸�����          *" << endl;
		cout << "*        (2)�޸�����         *" << endl;
		cout << "*        (3)�޸ļ۸�          *" << endl;
		cout << "*        (4)������һ��     *" << endl;
		cout << "****************************" << endl;
}

int editBook::bookEditTools(Book bk)
{
	char in;
	editBook ed;
	do {
		bookEditMenu();
		cin >> in;
		switch (in)
		{
		case '1':
			return ed.editBookName(bk);
			break;
		case '2':
			return ed.editBookAuthor(bk);
			break;
		case '3':
			return ed.editBookPrice(bk);
			break;
		case '4':
			return -1;
			break;
		default:cout << "���������������롣" << endl;;
		}
	} while (in != '5');
	return -1;
}

int editBook::editBookName(Book bk)
{
	char name[20];
	cout << endl << "�����������: ";
	cin >> name;
	bk.setName(name);
	return 1;
}

int editBook::editBookAuthor(Book bk)
{
	char author[20];
	cout << endl << "�����������: ";
	cin >> author;
	bk.setAuthor(author);
	return 1;
}

int editBook::editBookPrice(Book bk)
{
	int price;
	cout << endl << "������ļ۸�: ";
	cin >> price;
	bk.setPrice(price);
	return 1;
}
