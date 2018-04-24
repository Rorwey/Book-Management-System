#pragma once
class Book
{
public:
	Book();
	~Book();
private:
	int no;                                      //图书编号
	char name[20];                               //图书名称
	char author[20];                             //作者
	int price;                                   //价格
	bool is_rent;                                  //false为在架，true为借出
	bool is_del;                                   //false为存在, true为删除
public:
	void setNo(int n);
	int getNo();
	void setPrice(int p);
	int getPrice();
	void setName(char na[]);
	char* getName();
	void setAuthor(char a[]);
	char* getAuthor();
	bool isBor();
	bool isDel();
	bool borBook(bool b);//调整图书借还状态
	int delBook();//删除图书
	int newBook(int no, char na[], char author[], int price);    //增加图书功能
	void showBook();//展示图书信息
};

