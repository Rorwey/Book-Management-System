#pragma once
#include "Book.h"

class Reader
{
private:
	int no;
	int sex;     //�����Ա�1��ʾ�У�2��ʾŮ
	char name[20];
	bool is_del;  //false���ڣ�trueɾ��
	bool is_bor;  //true����飬falseû�н��� 
	Book brbook;// �ڽ��ͼ��
public:
	Reader();
	~Reader();
	int getNo();
	bool setNo(int n);
	int getSex();
	bool setSex(int s);
	char* getName();
	bool setName(char name[]);
	bool isDel();
	bool delReader();
	bool isBor();
	bool setBor(bool b);
	Book getBrBook();
	bool setBrBook(Book bt);
	void showReader();
	void addreader(int id, char na[], int s);//���Ӷ���
};

