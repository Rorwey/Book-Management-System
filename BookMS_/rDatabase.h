//�������ݿ���
#pragma once
#include "Reader.h"
const int RMAX = 50;   //��������

class rDatabase
{
public:
	Reader rdArray[RMAX];
	int top;
public:
	rDatabase();
	~rDatabase();
	Reader getRdarray();
	int getSize();
	void setTop(int t);
	int findReaders(rDatabase rd); //����ͼ��
	void addreaders();
	int isInDBbyNo(int no,rDatabase rd);//�ж϶����Ƿ������ݿ�
	int isInDbbyName(char name[20], rDatabase rd);
	void showAllReaders();
};

