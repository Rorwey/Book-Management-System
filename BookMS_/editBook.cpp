#include "editBook.h"
#include <iostream>
#include "Book.h"
using namespace std;

editBook::editBook() {};
editBook::editBook(Book bk)
{
	cout << "书号: " << bk.getNo() << " 书名: " << bk.getName() << " 作者: " << bk.getAuthor() << " 价格: " << bk.getPrice() << endl;
	cout << "准备修改：" << endl;
	bookEditTools(bk);
	return;
}


editBook::~editBook()
{
}

void editBook::bookEditMenu()
{
		cout << "****************************" << endl;
		cout << "*          图书修改         *" << endl;
		cout << "*        (1)修改书名          *" << endl;
		cout << "*        (2)修改作者         *" << endl;
		cout << "*        (3)修改价格          *" << endl;
		cout << "*        (4)返回上一层     *" << endl;
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
		default:cout << "输入错误，请从新输入。" << endl;;
		}
	} while (in != '5');
	return -1;
}

int editBook::editBookName(Book bk)
{
	char name[20];
	cout << endl << "输入书的名称: ";
	cin >> name;
	bk.setName(name);
	return 1;
}

int editBook::editBookAuthor(Book bk)
{
	char author[20];
	cout << endl << "输入书的作者: ";
	cin >> author;
	bk.setAuthor(author);
	return 1;
}

int editBook::editBookPrice(Book bk)
{
	int price;
	cout << endl << "输入书的价格: ";
	cin >> price;
	bk.setPrice(price);
	return 1;
}
