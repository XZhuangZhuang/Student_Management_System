#include "interface.h"
void Interface::run() {
	int choose = 1;
	while (choose) {
		while (1) {
			menu();
			cin >> choose;
			if (choose == 1 || choose == 2 ||  choose == 0) {//ͨ������0��1��2�����뵽��ͬ�Ĺ������
				break;
			}
			else
				cout << "�����������������룡" << endl;
		}
		system("cls");//��յ�ǰ����̨����
		if (choose == 1) {
			Administrator();//����Ա������
		}
		else if (choose == 2) {
			Teacher();//��ʦ������
		}
		else {
			break;
		}
		system("cls");//��յ�ǰ����̨����
	}
	save();
	cout << "���Ѿ��˳�ʦ������ϵͳ����ӭ�ٴ�ʹ�ã�" << endl;
}

//����Ա������
void Interface::Administrator() {
	cout << "         ���Ѿ��ɹ��������Աϵͳ��        " << endl;
	int count = 0;//���ڼ������������κ��ж��Ƿ񻹼���
	char ch;
	int flag = 0;
	string numbers;
	string passwords;
	while (!flag) {
		if (count > 0 && count % 3 == 0) {//�����������3�ı���ʱ���ж��Ƿ񻹼���
			cout << "      �Ƿ񻹼�������y �� ��n����";
			cin >> ch;
			if (ch != 'y') {
				cout << "���Ѿ��˳�����Աϵͳ��" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
		cout << "               ����Ա��½     " << endl;
		cout << "      �������˺ţ�";
		cin >> numbers;
		cout << "      ���������룺";
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
			cout << "�˺�������ȷ��" << endl;
			break;
		}
		else {
			cout << "�˺�����������������룡" << endl;
		}
	}
	system("cls");

	int choose, choose1 = 1;
	while (choose1) {
		while (1) {
			menu1();
			cin >> choose;
			if (!choose) {
				cout << "���Ѿ��˳�����Աϵͳ" << endl;
				system("pause");
				system("cls");//ִ�п���̨����cls������CMD�����cls�����������������������ʾ����Ϣ��
				return;
			}
			else if (choose != 1 && choose != 2 && choose != 3)
				cout << "������������������" << endl;
			else break;
		}
		system("cls");//����
		if (choose == 1) {//רҵ����
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
		else if(choose == 2){//�༶����
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
		else if (choose == 3) {//��ʦ����
			
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
		cout << "���Ѿ��˳�����Աϵͳ��" << endl;
		system("pause");
		system("cls");
	}
}

//��ʦ������
void Interface::Teacher()
{
	cout << "         ���Ѿ��ɹ������ʦ����ϵͳ��        " << endl;
	int count = 0;//���ڼ������������κ��ж��Ƿ񻹼���
	char ch;
	int flag = 0;
	string numbers;
	string passwords;
	while (!flag) {
		if (count > 0 && count % 3 == 0) {//�����������3�ı���ʱ���ж��Ƿ񻹼���
			cout << "      �Ƿ񻹼�������y �� ��n����";
			cin >> ch;
			if (ch != 'y') {
				cout << "���Ѿ��˳���ʦ����ϵͳ��" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
		cout << "               ��ʦ��½     " << endl;
		cout << "      �������˺ţ�";
		cin >> numbers;
		cout << "      ���������룺";
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
			cout << "�˺�������ȷ��" << endl;
			break;
		}
		else {
			cout << "�˺�����������������룡" << endl;
		}
	}
	system("cls");

	int choose, choose1 = 1;
	menu2();
	cin >> choose;
	system("cls");
	while (choose == 1 && choose1)  //ѧ����Ϣ����˵�
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
	while (choose == 2 && choose1)//ѧ����Ϣ��ѯ����˵�
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
	while (choose == 3 && choose1)//ѧ����Ϣ�������˵�
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
	while (choose == 4 && choose1)//ѧ����Ϣͳ�ƹ���˵� 
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
