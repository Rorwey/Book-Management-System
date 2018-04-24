#include "rDatabase.h"
#include <fstream>
#include <iostream>
#include "findReader.h"
using namespace std;


rDatabase::rDatabase()
{
	Reader rd;
  top = -1;
  fstream file("reader.txt", ios::in); //���ļ�
  while (1)
  {
   file.read((char *)&rd, sizeof(rd));
   if (!file) break;
   top++;
   rdArray[top] = rd;
  }
  file.close();  //�ر��ļ�  
}


rDatabase::~rDatabase()
{
	fstream file("reader.txt", ios::out);
	for (int i = 0; i <= top; i++)
	{
		Reader re = rdArray[i];
		if (re.isDel())//���û��ɾ��
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
void readerchamain()                                                     //ͼ������Ӳ˵�
{
	cout << "****************************" << endl;
	cout << "*         ͼ�����         *" << endl;
	cout << "*        (1)ѧ�Ų���          *" << endl;
	cout << "*        (2)��������          *" << endl;
	cout << "*        (3)������һ��     *" << endl;
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
		default:cout << "���������������롣" << endl;;
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
	cout << "������ѧ��: ";
	cin >> no;
	cout << endl << "����������: ";
	cin >> rname;
	cout << endl << "�������Ա�1Ϊ�У�0ΪŮ����";
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
			return i;//�ҵ��˾Ͱ����������λ�û���ȥ
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
			return i;//�ҵ��˾Ͱ����������λ�û���ȥ
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
			if (rdArray[i].isBor()) strcpy_s(value, "��");
			else strcpy_s(value, "��");			
			cout << "ѧ��: " << rdArray[i].getNo() << " ����: " << rdArray[i]. getName()<< " �Ƿ����: " << value << endl;
		}
	}
	return;
}
