#pragma once
class Book
{
public:
	Book();
	~Book();
private:
	int no;                                      //ͼ����
	char name[20];                               //ͼ������
	char author[20];                             //����
	int price;                                   //�۸�
	bool is_rent;                                  //falseΪ�ڼܣ�trueΪ���
	bool is_del;                                   //falseΪ����, trueΪɾ��
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
	bool borBook(bool b);//����ͼ��軹״̬
	int delBook();//ɾ��ͼ��
	int newBook(int no, char na[], char author[], int price);    //����ͼ�鹦��
	void showBook();//չʾͼ����Ϣ
};

