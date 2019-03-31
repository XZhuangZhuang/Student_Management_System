#include "interface.h"
void Interface::run() {
	int choose = 1;
	while (choose) {
		while (1) {
			menu();
			cin >> choose;
			if (choose == 1 || choose == 2 ||  choose == 0) {//通过输入0、1、2来进入到不同的管理界面
				break;
			}
			else
				cout << "输入有误，请重新输入！" << endl;
		}
		system("cls");//清空当前控制台界面
		if (choose == 1) {
			Administrator();//管理员管理函数
		}
		else if (choose == 2) {
			Teacher();//教师管理函数
		}
		else {
			break;
		}
		system("cls");//清空当前控制台界面
	}
	save();
	cout << "您已经退出师生管理系统，欢迎再次使用！" << endl;
}

//管理员管理函数
void Interface::Administrator() {
	cout << "         您已经成功进入管理员系统！        " << endl;
	int count = 0;//用于计数，输入三次后，判断是否还继续
	char ch;
	int flag = 0;
	string numbers;
	string passwords;
	while (!flag) {
		if (count > 0 && count % 3 == 0) {//若输入次数是3的倍数时，判断是否还继续
			cout << "      是否还继续（是y 或 否n）：";
			cin >> ch;
			if (ch != 'y') {
				cout << "您已经退出管理员系统！" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
		cout << "               管理员登陆     " << endl;
		cout << "      请输入账号：";
		cin >> numbers;
		cout << "      请输入密码：";
		cin >> passwords;

		count++;

		vector<administor>::iterator p = Adm.begin();
		while (p != Adm.end())
		{
			if (p->getNumber() == numbers && p->getPassword() == passwords)
			{
				flag = 1;
				break;
			}
			else
				p++;
		}
		if (flag)
		{
			cout << "账号密码正确！" << endl;
			break;
		}
		else {
			cout << "账号密码错误，请重新输入！" << endl;
		}
	}
	system("cls");

	int choose, choose1 = 1;
	while (choose1) {
		while (1) {
			menu1();
			cin >> choose;
			if (!choose) {
				cout << "您已经退出管理员系统" << endl;
				system("pause");
				system("cls");//执行控制台命令cls，就是CMD下面的cls，功能是清屏，清除所有显示的信息。
				return;
			}
			else if (choose != 1 && choose != 2 && choose != 3)
				cout << "输入有误，请重新输入" << endl;
			else break;
		}
		system("cls");//清屏
		if (choose == 1) {//专业管理
			while (choose1) {
				cout << endl;
				menu8();
				cin >> choose1;
				switch (choose1) {
				case 1:creatMajor(); break;
				case 2:Delete_Major(); break;
				case 3:Display(1, count4, maj.begin(), maj.end()); break;
				case 4:motify1(); break;
				case 0:break;
				}
				system("cls");
			}
		}
		else if(choose == 2){//班级管理
			while (choose1) {
				menu9();
				cin >> choose1;
				switch (choose1) {
				case 1:creatClass(); break;
				case 2:Delete_Class(); break;
				case 3:Display(2, count3, Cla.begin(), Cla.end()); break;
				case 4:motify2(); break;
				case 0:break;
				}
				system("cls");
			}
		}
		else if (choose == 3) {//教师管理
			
			while (choose1) {
				menu10();
				cin >> choose1;
				switch (choose1) {
				case 1:creatTeacher(); break;
				case 2:Delete_Teacher(); break;
				case 3:Display(5, count5, Tea.begin(), Tea.end()); break;
				case 0:break;
				}
				system("cls");
			}
		}
		else {
			while (choose1) {
				menu11();
				cin >> choose1;
				switch (choose1) {
				case 1:creatAdministor(); break;
				case 2:Delete_Administor(); break;
				case 3:Display(6, count6, Adm.begin(), Adm.end()); break;
				case 0:break;
				}
				system("cls");
			}
		}
		cout << "您已经退出管理员系统！" << endl;
		system("pause");
		system("cls");
	}
}

//教师管理函数
void Interface::Teacher()
{
	cout << "         您已经成功进入教师管理系统！        " << endl;
	int count = 0;//用于计数，输入三次后，判断是否还继续
	char ch;
	int flag = 0;
	string numbers;
	string passwords;
	while (!flag) {
		if (count > 0 && count % 3 == 0) {//若输入次数是3的倍数时，判断是否还继续
			cout << "      是否还继续（是y 或 否n）：";
			cin >> ch;
			if (ch != 'y') {
				cout << "您已经退出教师管理系统！" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
		cout << "               教师登陆     " << endl;
		cout << "      请输入账号：";
		cin >> numbers;
		cout << "      请输入密码：";
		cin >> passwords;

		count++;

		vector<teacher>::iterator p = Tea.begin();
		while (p != Tea.end())
		{
			if (p->getNumber() == numbers && p->getPassword() == passwords)
			{
				flag = 1;
				break;
			}
			else
				p++;
		}
		if (flag)
		{
			cout << "账号密码正确！" << endl;
			break;
		}
		else {
			cout << "账号密码错误，请重新输入！" << endl;
		}
	}
	system("cls");

	int choose, choose1 = 1;
	menu2();
	cin >> choose;
	system("cls");
	while (choose == 1 && choose1)  //学生信息管理菜单
	{
		menu3();
		cin >> choose1;
		switch (choose1) {
		case 1:Input(); break;
		case 2:motify3(); break;
		case 3:motify4(); break;
		case 4:DisplayByID(); break;
		case 5:Delete_student(); break;
		case 6:InputScore(); break;
		case 0:break;
		}
		system("cls");
	}
	while (choose == 2 && choose1)//学生信息查询管理菜单
	{
		menu4();
		cin >> choose1;
		switch (choose1)
		{
		case 1:Display(3, count1, stu1.begin(), stu1.end()); break;
		case 2:Display(4, count2, stu2.begin(), stu2.end()); break;
		case 3:DisplayByClass(); break;
		case 4:DisplayByMajor(); break;
		case 5:DisplayByName(); break;
		case 6:DisplayByID(); break;
		case 7:DisplayFailStudent(); break;
		}

	}
	while (choose == 3 && choose1)//学生信息排序管理菜单
	{
		menu5();
		cin >> choose1;
		switch (choose1)
		{
		case 1:sortUndergraduate();
			break;
		case 2:sortGraduate();
			break;
		case 3:sortByClass_undergraduate();
			break;
		case 4:sortByClass_graduate();
			break;
		}
	}
	while (choose == 4 && choose1)//学生信息统计管理菜单 
	{
		menu6();
		cin >> choose1;
		switch (choose1)
		{
		case 1:statistic1(); break;
		case 2:statistic2(); break;
		case 3:statistic3(); break;
		case 4:statistic4(); break;
		}
	}
	return;
}
