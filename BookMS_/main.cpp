#include <iostream>
#include "bDatabase.h"
#include "editBook.h"
#include "rDatabase.h"
#include "editReader.h"
#include "Menu.h"
#include "main.h"
#define NULL 0
using namespace std;

void borrowtoreturn(char br,bDatabase t_bd,rDatabase t_rd)
//借书还书函数.参数br用来判断是“借书”还是“还书”.1为“借书”,2为“还书”
{
	int rsuffix, bsuffix;

	if (br == '1')           //借书
	{
		cout << "谁要借书？" << endl;
		rsuffix = t_rd.findReaders(t_rd);
		cout << "要借哪本书？" << endl;
		bsuffix = t_bd.findBooks(t_bd);
		if (rsuffix == -1 || bsuffix == -1)
			return;
		if (t_bd.btarray[bsuffix].isBor())
		{
			cout << "图书已经借出，请选择其它图书" << endl;
			return;
		}
		if (t_rd.rdArray[rsuffix].isBor())
		{
			cout << "你已经借过图书，请先归还再借其它图书" << endl;
			return;
		}
		t_bd.btarray[bsuffix].borBook(true);//图书馆的书设为借出

		t_rd.rdArray[rsuffix].setBor(true);//读者的标志设为借入
		t_rd.rdArray[rsuffix].setBrBook(t_bd.btarray[bsuffix]);

		return;

	}
	if (br == '2')//还书
	{
		cout << "谁要还书？" << endl;
		rsuffix = t_rd.findReaders(t_rd);
		cout << "要还哪本书？" << endl;
		bsuffix = t_bd.findBooks(t_bd);

		if (rsuffix == -1 || bsuffix == -1)
			return;
		if (t_rd.rdArray[rsuffix].getBrBook().getNo() == t_bd.btarray[bsuffix].getNo())
		{
			t_bd.btarray[bsuffix].borBook(false);//图书馆的书设为非借出
			t_rd.rdArray[rsuffix].setBor(false);//读者的标志设为没借书
			//t_rd.rdArray[rsuffix].setBrBook(NULL);//读者手上的书清空
		}
		else
		{
			cout << "请重新输入，读者借的图书号不正确" << endl;
			return;
		}
		return;
	}
}

void booksmange(bDatabase  bd)
{
	char in;
	int bkIndex = -1;
	editBook eb;
	Menu mu;
	do {
		mu.bookMenu();
		cin >> in;
		switch (in)
		{
		case '1':
				bd.addBooks();			
			break;
		case '2':
			bkIndex = bd.findBooks(bd);//先要查找到图书的位置
			if (bkIndex != -1)
			{
				eb.bookEditTools(bd.btarray[bkIndex]);
			}
			else cout << "没有找到这本书，请重新输入" << endl;			
			break;
		case '3':
			bkIndex = bd.findBooks(bd);//先要查找到图书的位置
			if (bkIndex != -1)
			{
				bd.delbooks(bd.btarray[bkIndex]);
			}
			else cout << "没有找到这本书，请重新输入" << endl;
			break;
		case '4':
			bkIndex = bd.findBooks(bd);//先要查找到图书的位置
			if (bkIndex != -1)
			{
				bd.btarray[bkIndex].showBook();
			}
			break;
		case '5':
			bd.showAllBooks();
			break;
		case '6':
			break;
		default:cout << "输入错误，请从新输入。" << endl;;
		}
	} while (in != '6');
	return;
}

void readersmange(rDatabase  rd)
{
	char in;
	int reIndex=-1;
	Menu mu;
	editReader er;
	do {
		mu.readerMenu();
		cin >> in;
		switch (in)
		{
		case '1':
			rd.addreaders();
			break;
		case '2':
			reIndex = rd.findReaders(rd);//先要查找到读者的位置
			if (reIndex != -1)
			{
				er.editReaderName(rd.rdArray[reIndex]);
			}
			else cout << "没有找到这个人，请重新输入" << endl;
			break;
		case '3':
			reIndex = rd.findReaders(rd);//先要查找到读者的位置
			if (reIndex != -1)
			{
				er.delReader(rd.rdArray[reIndex]);
			}
			else cout << "没有找到这个人，请重新输入" << endl;
			break;
		case '4':
			reIndex = rd.findReaders(rd);//先要查找到读者的位置
			if (reIndex != -1)
			{
				rd.rdArray[reIndex].showReader();
			}
			break;
		case '5':
			rd.showAllReaders();
			break;
		case '6':
			break;
		default:cout << "输入错误，请从新输入。" << endl;
		}
	} 
	while (in != '6');
	return;

}


int main(int argc, char* argv[])
{
	bDatabase bd;
	rDatabase rd;
	char in;
	do {
		Menu mu;
		mu.mainMenu();
		cin >> in;
		switch (in)
		{
		case '1':
			borrowtoreturn(in,bd,rd);
			break;
		case '2':
			borrowtoreturn(in,bd, rd);
			break;
		case '3':
			booksmange(bd);
			break;
		case '4':
			readersmange(rd);
			break;
		case '0':
			break;
		default:cout << "输入错误，请从新输入。" << endl;
		}
	} 
	while (in != '0');
	return 0;
}