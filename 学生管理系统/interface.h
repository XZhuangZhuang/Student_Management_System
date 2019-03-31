#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef INTERFACE_H
#define INTERFACE_H

#include<cstdio>
#include<algorithm>
#include<fstream>
#include<vector>
#include <assert.h>
#include"Data.h"

using namespace std;

class Interface {
public:
	//�����溯��
	void menu();          //���˵�����--��½���溯��
	void menu1();         //����Ա�˵�����
	void menu2();         //��ʦ����˵�����
	void menu3();         //ѧ����Ϣ����˵�
	void menu4();         //ѧ����Ϣ��ѯ����˵�
	void menu5();         //ѧ����Ϣ�������˵�
	void menu6();         //ѧ����Ϣͳ�ƹ���˵�
	void menu7(int n);    //????????????????????????????
	void menu8();         //רҵ����˵� 
	void menu9();         //�༶����˵� 
	void menu10();         //��ʦ����˵� 
	void menu11();         //����Ա����˵� 


	//��ȡ�ļ����ݺ��ļ��洢
	Interface();          //���ļ����Ҷ�ȡ�ļ�����
	void save();               //�رճ��򲢱�������

	//��������
	void run();

	//����Ա�ͽ�ʦ�Ĺ�����
	void Administrator();      //רҵ/�༶������
	void Teacher();          //רҵ���༶��Ա������

	//רҵ����ģ��
	void creatMajor();         //����רҵ
	void Delete_Major();       //ɾ��רҵ�Լ������Ա����Ϣ
	void motify1();            //�޸�רҵ��Ϣ

	//�༶����ģ��
	void creatClass();         //����һ���µİ༶
	void Delete_Class();       //ɾ��һ���༶����Ϣ
	void motify2();          //�޸İ༶��Ϣ

	//��ʦ����ģ��
	void creatTeacher();         //����һ���µĽ�ʦ
	void Delete_Teacher();       //ɾ��һ����ʦ����Ϣ

	//����Ա����ģ��
	void creatAdministor();         //����һ���µĹ���Ա
	void Delete_Administor();       //ɾ��һ������Ա����Ϣ

	template<class T>void getPage(int page, T begin, T end);   //��ȡ��ǰҳ����������Ϣ
	template<class T>void Display(int n, int count, T begin, T end);       //��ʾ����רҵ���༶�Լ�����ѧ���������Ϣ


	//ѧ����Ϣ������
	void Input();    //���ӱ����������о����Ļ���������Ϣ
	void InputScore();       //�������뱾���������о����ɼ�
	void motify3();          //����ѧ���޸�ѧ�������Ϣ
	void motify4();          //���������޸�ѧ�������Ϣ
	void Delete_student();   //����ѧ��ɾ��ѧ����Ϣ
	void DisplayByID();      //����ѧ�Ų�ѯ������Ϣ

	//ѧ����Ϣ��ѯ����
	void DisplayByClass();   //������༶��ѧ����Ϣ
	void DisplayByMajor();   //�����רҵ��ѧ����Ϣ
	void DisplayByName();    //�����������ѧ����Ϣ
	//void DisplayByID();      //����ѧ�Ų�ѯ������Ϣ
	void DisplayFailStudent();  //��ѯĳ�༶��ĳ��Ŀ�����������

	// ѧ����Ϣ���������
	static bool comparing1(undergraduate s1, undergraduate s2);  //�Ƚ϶����ܳɼ���С
	static bool comparing2(graduate s1, graduate s2);  //�Ƚ϶����ܳɼ���С
	static bool comparing3(undergraduate s1, undergraduate s2);  //�Ƚ϶���ѧ��
	static bool comparing4(graduate s1, graduate s2);  //�Ƚ�ѧ��
	void sortUndergraduate();   //����ȫ��������
	void sortGraduate();        //����ȫ���о���
	void sortByClass_undergraduate();        //���򱾿����༶
	void sortByClass_graduate();      //�����о����༶

	//ѧ����Ϣͳ�ƹ�����
	void statistic1();                //ͳ��ĳ�༶ƽ���֡���߷ֺ���ͷ�
	void statistic2();                //ͳ��ĳ�༶����ƽ���ֵ������Լ�����
	void statistic3();                //ͳ��ĳ�༶ĳ��Ŀ�����������������
	void statistic4();                //ͳ��ĳ�༶ĳ��Ŀ��ͬ�ȼ���ѧ������

	//void motify5();                   //�޸ĸ���רҵ���
	//void motify6();                   //�޸ĸ��˰༶���

private:
	vector<undergraduate>stu1;    //������----���������ڴ洢������
	vector<graduate>stu2;         //�о���-----���������ڴ洢�о���
	vector<Class>Cla;             //�༶-----���������ڴ洢�༶
	vector<major>maj;             //רҵ-----���������ڴ洢רҵ
	vector<teacher>Tea;             //��ʦ-----���������ڴ洢��ʦ
	vector<administor>Adm;             //����Ա-----���������ڴ洢����Ա

	//��̬����
	static int count1;    //��¼������������
	static int count2;    //��¼�о���������
	static int count3;    //��¼�༶������
	static int count4;    //��¼רҵ������
	static int count5;    //��¼��ʦ������
	static int count6;    //��¼����Ա������

};
#endif

template<class T>     //��ģ�壺��ȡ��ǰҳ��
void Interface::getPage(int page, T begin, T end)
{
	T p = begin;
	int count = 0, page1, page2;
	page1 = (page - 1) * 10;
	page2 = (page) * 10;
	while (p != end)
	{
		count++;
		if (count > page1)
			break;
		p++;
	}
	while (p != end && count <= page2)
	{
		p->Display();
		count++;
		p++;
	}
}

template<class T>     //��ģ�壺��ʾ����ѧ������Ϣ
void Interface::Display(int n, int count, T begin, T end)    //  nΪ��ʾ����
{
	int page = 1, allpage;
	int choose;
	if (count <= 10 && count > 0)
	{
		allpage = 1;
	}
	else if (count == 0)
	{
		allpage = 0;
		cout << "û�����ѧ����Ϣ���밴���������..." << endl;
		system("pause");
		system("pause");
		return;
	}
	else if (count % 10)
	{
		allpage = count / 10 + 1;
	}
	else
	{
		allpage = count / 10;
	}
	do {
		if (page == 1 && allpage == 1) {
			printf("======================================================================\n");
			menu7(n);
			printf("----------------------------------------------------------------------\n");
			getPage(page, begin, end);
			printf("----------------------------------------------------------------------\n");
			printf("             ��ǰҳΪ��%dҳ  ��ҳ��Ϊ%dҳ ��0������\n", page, allpage);
			printf("======================================================================\n");
			do {
				printf("��ѡ��>>");
				scanf("%d", &choose);
				if (choose != 0)
					printf("��������������ѡ��...\n");
				else break;
			} while (1);
		}
		else if (page == 1 && allpage > 1) {
			printf("=============================================================================\n");
			menu7(n);
			getPage(page, begin, end);
			printf("-----------------------------------------------------------------------------\n");
			printf("  ��ǰҳΪ��%dҳ  ��ҳ��Ϊ%dҳ ��2����һҳ ��4��βҳ ��0���˳�\n", page, allpage);
			printf("==============================================================================\n");
			do {
				printf("��ѡ��>>");
				scanf("%d", &choose);
				if (choose != 0 && choose != 2 && choose != 4)
					printf("��������������ѡ��...\n");
				else break;
			} while (1);
		}
		else if (page > 1 && page != allpage) {
			printf("================================================================================================\n");
			menu7(n);
			getPage(page, begin, end);
			printf("------------------------------------------------------------------------------------------------\n");
			printf("  ��ǰҳΪ��%dҳ  ��ҳ��Ϊ%dҳ ��1����һҳ ��2����һҳ ��3����ҳ ��4��βҳ ��0���˳�\n", page, allpage);
			printf("================================================================================================\n");
			do {
				printf("��ѡ��>>");
				scanf("%d", &choose);
				if (choose != 0 && choose != 2 && choose != 4 && choose != 1 && choose != 3)
					printf("��������������ѡ��...\n");
				else break;
			} while (1);
		}
		else if (page == allpage) {
			printf("=============================================================================\n");
			menu7(n);
			getPage(page, begin, end);
			printf("-----------------------------------------------------------------------------\n");
			printf("  ��ǰҳΪ��%dҳ  ��ҳ��Ϊ%dҳ ��1����һҳ ��3����ҳ��0���˳�\n", page, allpage);
			printf("=============================================================================\n");
			do {
				printf("��ѡ��>>");
				scanf("%d", &choose);
				if (choose != 0 && choose != 1 && choose != 3)
					printf("��������������ѡ��...\n");
				else break;
			} while (1);
		}
		if (choose == 1)
			page--;
		if (choose == 2)
			page++;
		if (choose == 3)
			page = 1;
		if (choose == 4)
			page = allpage;
		if (choose == 0)break;
		system("cls");
	} while (1);
	cout << "��ѯ�������밴���������..." << endl;
	system("pause");
	system("cls");
}