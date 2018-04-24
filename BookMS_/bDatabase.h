#pragma once
#include <deque>
#include "Book.h"

const int BMAX = 100;   //��������

class bDatabase
{
public:
	Book btarray[BMAX];                                         //ͼ�鼯��
	int top;
public:
	bDatabase() ;
	~bDatabase();
	Book getBtarray();
	int getSize();
	int setTop(int s);	
	int initBtarray(Book bk);//�����ݿ��ж�ȡͼ�飬��ʼ��ͼ���
	int findBooks(bDatabase bd); //����ͼ��
	int isInDBbyNo(int no, bDatabase bd);//�ж�ͼ���Ƿ������
	int isInDBbyAuthor(char* Author, bDatabase bd);
	int isInDbbyName(char* Name, bDatabase bd);
	void addBooks();
	bool delbooks(Book bk);
	void showAllBooks();
};

