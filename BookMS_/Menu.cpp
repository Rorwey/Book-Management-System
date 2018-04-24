#include "Menu.h"
#include <iostream>
using namespace std;


Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::bookMenu()
{
	cout << "****************************" << endl;
	cout << "*        图书管理           *" << endl;
	cout << "*        (1)增 加          *" << endl;
	cout << "*        (2)更 改          *" << endl;
	cout << "*        (3)删 除          *" << endl;
	cout << "*        (4)查 找          *" << endl;
	cout << "*        (5)显 示          *" << endl;
	cout << "*        (6)返回上一层     *" << endl;
	cout << "****************************" << endl;
}

void Menu::readerMenu()
{
	cout << "****************************" << endl;
	cout << "*        读者管理          *" << endl;
	cout << "*        (1)增 加          *" << endl;
	cout << "*        (2)更 改          *" << endl;
	cout << "*        (3)删 除          *" << endl;
	cout << "*        (4)查 找          *" << endl;
	cout << "*        (5)显 示          *" << endl;
	cout << "*        (6)返回上一层     *" << endl;
	cout << "****************************" << endl;
}

void Menu::mainMenu()
{
	cout << "***********************************************" << endl;
	cout << "*               图 书 管 理 系 统             *" << endl;
	cout << "*                                             *" << endl;
	cout << "*               (1) 借 书                     *" << endl;
	cout << "*                                             *" << endl;
	cout << "*               (2) 还 书                     *" << endl;
	cout << "*                                             *" << endl;
	cout << "*               (3) 图 书 管 理               *" << endl;
	cout << "*                                             *" << endl;
	cout << "*               (4) 用 户 管 理               *" << endl;
	cout << "*                                             *" << endl;
	cout << "*               (0) 退 出                     *" << endl;
	cout << "***********************************************" << endl;
}
