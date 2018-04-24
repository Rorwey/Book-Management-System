#pragma once
#include "Book.h"

class Reader
{
private:
	int no;
	int sex;     //读者性别，1表示男，2表示女
	char name[20];
	bool is_del;  //false存在，true删除
	bool is_bor;  //true借过书，false没有借书 
	Book brbook;// 在借的图书
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
	void addreader(int id, char na[], int s);//增加读者
};

