/*
���ļ���6���ࣺ�ɼ��ࡢѧ���ࡢ�������ࡢ�о����ࡢ�༶���רҵ�࣬
���б���������о�����̳�ѧ���ࡣ
*/
#ifndef DATA_H
#define DATA_H

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

//�ɼ���
class score {
public:
	//�вι��캯��------��ĳ�������ĳɼ����Ƶ��ɼ�������
	score(vector<int>::iterator beg, vector<int>::iterator en) {
		while (beg != en) {
			sco.push_back(*beg);
			++beg;
		}
	}

	//���ù��캯��---����Ա����--�����Ĵ�С��Ϊn��Ԫ������Ϊ-1
	score(int n) {
		sco.resize(n);
		for (int i = 0; i < n; ++i) {
			sco.push_back(-1);
		}
	}
	//��ӡ��������Ԫ��
	void print() {
		for (auto a : sco) {
			cout << a << " ";
		}
		cout << endl;
	}
	//���������һ��Ԫ��Ϊ�ܳɼ�����ȡѧ�����ܳɼ�
	int getTotalScore()const {
		return *(sco.end() - 1);
	}
	//���������ĵ�n��Ԫ��---���ڷ���ѧ����ĳ�Ƴɼ�
	int& getScore(int n) {
		return sco[n];
	}

	//����ѧ�����ܳɼ�������ֵ�����������һ��Ԫ��
	void calculation() {
		int sum = 0;
		for (int i = 0; i < (int)sco.size()-1; ++i) {//����Ƿ����гɼ�����������
			if (sco[i] == -1) return;
		}
		for (int i = 0; i < (int)sco.size() - 1; ++i) {
			sum += sco[i];
		}
		sco[sco.size() - 1] = sum;
	}
private:
	vector<int> sco;//���ڴ洢���Ƶĳɼ�������
};


//Person��---ѧ���������Ϣ�Ͳ���
class person {
public:
	//�вι��캯��
	person(int i, string na, string se, string num1, string num2, string maj, string cla, int rank1, int rank2, vector<int>::iterator begin, vector<int>::iterator end) :id(i), name(na), sex(se), major_number(num1), class_number(num2), major(maj), Class(cla), gradeRanking(rank1), classRanking(rank2), sco(begin, end)  //��ʼ���б�
	{}
	//���캯��--�ɼ�����-1
	person(int i, string na, string se, string num1, string num2, string maj, string cla, int rank1, int rank2, int n) :id(i), name(na), sex(se), major_number(num1), class_number(num2), major(maj), Class(cla), gradeRanking(rank1), classRanking(rank2), sco(n)  //��ʼ���б�
	{}

	//Ϊ���޸ĸ�����Ϣ����
	virtual void motify(int n) {
		int temp;
		switch (n) {
		case 1:cout << "��������ȷ�����֣�"; cin >> temp; name = temp; break;
		case 2:cout << "��������ȷ���Ա�"; cin >> temp; sex = temp; break;
		}
	}

	//ͬһ�������ã�����ֵ��֮��ĺ�������ͨ�����ص�ֵ�������޸�
	int& getID() { return id; }        //���»�ȡ��Ϣ�ķŻ�ֵ������Ϊ������������ֵΪ�˷����޸�
	string& getName() { return name; }      //��ȡ����
	string& getSex() { return sex; }        //��ȡ�Ա�
	string& getMajorNumber() {return major_number; }//��ȡרҵ���
	string& getClassNumber() { return class_number; }//��ȡ�༶���
	string& getMajor() { return  major; }      //��ȡרҵ����
	string& getClass() { return Class; }      //��ȡ�༶����
	int& getRanking1() { return gradeRanking; }    //��ȡ�꼶����
	int& getRanking2() {return classRanking;}    //��ȡ�༶����
	int& getScore(int n) { return sco.getScore(n); }    //��ȡ���Ƴɼ�
protected:
	int id;                 //ѧ��
	string name;            //����
	string sex;             //�Ա�
	string major_number;    //רҵ���
	string class_number;    //�༶���
	string major;           //רҵ����
	string Class;           //�༶����
	string type;            //ѧ������
	int gradeRanking;       //�꼶����
	int classRanking;       //�༶����
	score sco;              //����Ŀ�ɼ�
};


//��������
class undergraduate : virtual public person {
public:
	undergraduate(int i, string na, string se, string num1, string num2, string major, string Class, int rank1, int rank2, vector<int>::iterator begin, vector<int>::iterator end) :person(i, na, se, num1, num2, major, Class, rank1, rank2, begin, end)
	{}
	undergraduate(int i, string na, string se, string num1, string num2, string major, string Class, int rank1, int rank2, int n) :person(i, na, se, num1, num2, major, Class, rank1, rank2, n)
	{}

	// //��ʾ��������Ϣ��ʱ��
	virtual void Display() {
		cout << setw(7) << id << setw(7) << name << setw(5) << sex << setw(11) << major_number << setw(7) << class_number << setw(11) << major << setw(12) << Class << setw(7) << sco.getScore(0) << setw(10) << sco.getScore(1) << setw(10) << sco.getScore(2) << setw(10) << sco.getScore(3) << setw(10) << classRanking << setw(10) << gradeRanking << endl;
	}   

	//��ʾ������Ϣ
	virtual void print() {
		cout << "��A��ID�� " << id << endl;
		cout << "��1�����֣� " << name << endl;
		cout << "��2���Ա� " << sex << endl;
		cout << "��3��רҵ��ţ�" << major_number << endl;
		cout << "��B��רҵ���ƣ�" << major << endl;
		cout << "��4���༶��ţ� " << class_number << endl;
		cout << "��C���༶���ƣ�" << Class << endl;
		cout << "��5��C���Գɼ��� " << sco.getScore(0) << endl;
		cout << "��6�������ɼ��� " << sco.getScore(1) << endl;
		cout << "��7��Ӣ��ɼ��� " << sco.getScore(2) << endl;
		cout << "��D���ܳɼ��� " << sco.getScore(3) << endl;
		cout << "��E���༶������ " << gradeRanking << endl;
		cout << "��F���꼶������ " << classRanking << endl;
	}        

	//�޸ı�����������Ϣ
	virtual void motify(int n) {
		if (n <= 4)
		{
			person &p = *this;
			p.person::motify(n);
		}
		else
		{
			string temp;
			int score;
			switch (n)
			{
			case 5:cout << "��������ȷ��C���Գɼ���"; cin >> score; sco.getScore(0) = score; break;
			case 6:cout << "��������ȷ�ĸ����ɼ���"; cin >> score; sco.getScore(1) = score; break;
			case 7:cout << "��������ȷ��Ӣ��ɼ���"; cin >> score; sco.getScore(2) = score; break;
			case 0:cout << "�޸Ľ������밴������ص��˵�����" << endl; break;
			}
			sco.calculation();  //�����ܳɼ�
		}
		cout << "�޸ĳɹ���" << endl;
	}

};


//�о�����
class graduate :virtual public person
{
public:
	graduate(int i, string na, string se, string num1, string num2, string major, string Class, int rank1, int rank2, vector<int>::iterator begin, vector<int>::iterator end) :person(i, na, se, num1, num2, major, Class, rank1, rank2, begin, end)
	{}
	graduate(int i, string na, string se, string num1, string num2, string major, string Class, int rank1, int rank2, int n) :person(i, na, se, num1, num2, major, Class, rank1, rank2, n)
	{}

	//������ʾ�����˵���Ϣ��ʱ��
	virtual void Display() {
		cout << setw(7) << id << setw(7) << name << setw(5) << sex << setw(11) << major_number << setw(7) << class_number << setw(11) << major << setw(12) << Class << setw(9) << sco.getScore(0) << setw(12) << sco.getScore(1) << setw(10) << sco.getScore(2) << setw(7) << classRanking << setw(10) << gradeRanking << endl;
	}
	//��ϸ����ʾ������Ϣ
	virtual void print() {
		cout << "��A��ID�� " << id << endl;
		cout << "��1�����֣� " << name << endl;
		cout << "��2���Ա� " << sex << endl;
		cout << "��3��רҵ��ţ�" << major_number << endl;
		cout << "��B��רҵ���ƣ� " << major << endl;
		cout << "��4���༶��ţ� " << class_number << endl;
		cout << "��C���༶���ƣ� " << Class << endl;
		cout << "��5���γ��ۺϳɼ��� " << sco.getScore(0) << endl;
		cout << "��6�����ĳɼ��� " << sco.getScore(1) << endl;
		cout << "��D���ܳɼ��� " << sco.getScore(2) << endl;
		cout << "��E���༶������ " << gradeRanking << endl;
		cout << "��F���꼶������ " << classRanking << endl;
	}
	//�޸��о���������Ϣ
	virtual void motify(int n) {
		if (n <= 4)
		{
			person &p = *this;
			p.person::motify(n);
		}
		else
		{
			int score;
			switch (n)
			{
			case 5:cout << "��������ȷ�Ŀγ���Ƴɼ���"; cin >> score; sco.getScore(0) = score; break;
			case 6:cout << "��������ȷ�����ĳɼ���"; cin >> score; sco.getScore(1) = score; break;
			case 0:cout << "�޸Ľ������밴������ص��˵�����" << endl; break;
			}
			sco.calculation();
		}
		cout << "�޸ĳɹ���" << endl;
	}
};

//�༶��
class Class
{
private:
	string major_number;  //רҵ���
	string major;         //רҵ����
	string name;          //�༶����
	string id;            //�༶���
public:
	Class(string number, string maj, string na, string i) :major_number(number), major(maj), name(na), id(i)
	{}

	//������ʾ���еİ༶����
	void Display() const {
		cout << setw(15) << major_number << setw(11) << major << setw(17) << id << setw(17) << name << endl;
	}

	//ͬһ�������ã�����ֵ��֮��ĺ�������ͨ�����ص�ֵ�������޸�
	string& getMajor_number() { return major_number; }      //��ȡרҵ���  
	string& getMajor() { return major; }             //��ȡרҵ����
	string& getName() { return name; }              //��ȡ�༶����
	string& getID() { return id; }                //��ȡ�༶���
};

//רҵ��
class major {
private:
	string name;        //רҵ����
	string id;          //רҵ���
public:
	major(string na, string i) :name(na), id(i)      //���캯��
	{}

	//��ʾ����
	void Display() const {
		cout << setw(14) << id << setw(12) << name << endl;
	}                       
	string &getName() { return name; }                           //��ȡרҵ����
	string &getID() { return id; }                              //��ȡרҵ���
};


//��ʦ��
class teacher {
public:
	teacher(int i, string na, string nu, string pa) :id(i), name(na), number(nu), password(pa) {}//���캯��
	//ͬһ�������ã�����ֵ��֮��ĺ�������ͨ�����ص�ֵ�������޸�
	int& getId() { return id; }      //��ȡid  
	string& getName() { return name; }             //��ȡ����
	string& getNumber() { return number; }              //��ȡ�˺�
	string& getPassword() { return password; }                //��ȡ����

	void Display() {
		cout << setw(11) << id << setw(11) << name << setw(11) << number<< setw(11) << password<< endl;
	}

private:
	int id;//��ʦ���
	string name;//��ʦ����
	string number;//�˺�
	string password;//����
};
class administor {
public:
	administor(int i, string na, string nu, string pa) :id(i), name(na), number(nu), password(pa) {}//���캯��
	//ͬһ�������ã�����ֵ��֮��ĺ�������ͨ�����ص�ֵ�������޸�
	int& getId() { return id; }      //��ȡid 
	string& getName() { return name; }             //��ȡ����
	string& getNumber() { return number; }              //��ȡ�˺�
	string& getPassword() { return password; }                //��ȡ����

	void Display() {
		cout << setw(11) << id << setw(11) << name << setw(11) << number << setw(11) << password << endl;
	}

private:
	int id;//����Ա���
	string name;//����Ա����
	string number;//�˺�
	string password;//����
};

#endif // !DATA_H