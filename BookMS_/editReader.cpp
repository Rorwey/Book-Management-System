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
	cout << "ѧ��: " << re.getNo() << " ����: " << re.getName() << endl;
	cout << "׼���޸ģ�" << endl;
	readerEditTools(re);
	return;
}

void editReader::readerEditMenu()
{
	cout << "****************************" << endl;
	cout << "*         ������Ϣ�޸�         *" << endl;
	cout << "*        (1)�޸�����          *" << endl;
	cout << "*        (2)������һ��     *" << endl;
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
		default:cout << "���������������롣" << endl;;
		}
	} while (in != '3');
	return -1;
}

int editReader::editReaderName(Reader re)
{
	char name[20];
	cout << endl << "�����������: ";
	cin >> name;
	re.setName(name);
	return 1;
}

bool editReader::delReader(Reader re)
{
	if (re.isBor())                              //ɾ��ʱ�ж϶��������Ƿ�����
	{
		cout << "�ö��߽����飬���ڹ黹����ɾ����" << endl;
		return false;
	}
	re.delReader(); //ɾ��ͼ��
	cout << "�ö����Ѿ�ɾ����" << endl;
	return true;
}
