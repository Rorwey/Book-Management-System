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
//���黹�麯��.����br�����ж��ǡ����顱���ǡ����顱.1Ϊ�����顱,2Ϊ�����顱
{
	int rsuffix, bsuffix;

	if (br == '1')           //����
	{
		cout << "˭Ҫ���飿" << endl;
		rsuffix = t_rd.findReaders(t_rd);
		cout << "Ҫ���ı��飿" << endl;
		bsuffix = t_bd.findBooks(t_bd);
		if (rsuffix == -1 || bsuffix == -1)
			return;
		if (t_bd.btarray[bsuffix].isBor())
		{
			cout << "ͼ���Ѿ��������ѡ������ͼ��" << endl;
			return;
		}
		if (t_rd.rdArray[rsuffix].isBor())
		{
			cout << "���Ѿ����ͼ�飬���ȹ黹�ٽ�����ͼ��" << endl;
			return;
		}
		t_bd.btarray[bsuffix].borBook(true);//ͼ��ݵ�����Ϊ���

		t_rd.rdArray[rsuffix].setBor(true);//���ߵı�־��Ϊ����
		t_rd.rdArray[rsuffix].setBrBook(t_bd.btarray[bsuffix]);

		return;

	}
	if (br == '2')//����
	{
		cout << "˭Ҫ���飿" << endl;
		rsuffix = t_rd.findReaders(t_rd);
		cout << "Ҫ���ı��飿" << endl;
		bsuffix = t_bd.findBooks(t_bd);

		if (rsuffix == -1 || bsuffix == -1)
			return;
		if (t_rd.rdArray[rsuffix].getBrBook().getNo() == t_bd.btarray[bsuffix].getNo())
		{
			t_bd.btarray[bsuffix].borBook(false);//ͼ��ݵ�����Ϊ�ǽ��
			t_rd.rdArray[rsuffix].setBor(false);//���ߵı�־��Ϊû����
			//t_rd.rdArray[rsuffix].setBrBook(NULL);//�������ϵ������
		}
		else
		{
			cout << "���������룬���߽��ͼ��Ų���ȷ" << endl;
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
			bkIndex = bd.findBooks(bd);//��Ҫ���ҵ�ͼ���λ��
			if (bkIndex != -1)
			{
				eb.bookEditTools(bd.btarray[bkIndex]);
			}
			else cout << "û���ҵ��Ȿ�飬����������" << endl;			
			break;
		case '3':
			bkIndex = bd.findBooks(bd);//��Ҫ���ҵ�ͼ���λ��
			if (bkIndex != -1)
			{
				bd.delbooks(bd.btarray[bkIndex]);
			}
			else cout << "û���ҵ��Ȿ�飬����������" << endl;
			break;
		case '4':
			bkIndex = bd.findBooks(bd);//��Ҫ���ҵ�ͼ���λ��
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
		default:cout << "���������������롣" << endl;;
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
			reIndex = rd.findReaders(rd);//��Ҫ���ҵ����ߵ�λ��
			if (reIndex != -1)
			{
				er.editReaderName(rd.rdArray[reIndex]);
			}
			else cout << "û���ҵ�����ˣ�����������" << endl;
			break;
		case '3':
			reIndex = rd.findReaders(rd);//��Ҫ���ҵ����ߵ�λ��
			if (reIndex != -1)
			{
				er.delReader(rd.rdArray[reIndex]);
			}
			else cout << "û���ҵ�����ˣ�����������" << endl;
			break;
		case '4':
			reIndex = rd.findReaders(rd);//��Ҫ���ҵ����ߵ�λ��
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
		default:cout << "���������������롣" << endl;
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
		default:cout << "���������������롣" << endl;
		}
	} 
	while (in != '0');
	return 0;
}