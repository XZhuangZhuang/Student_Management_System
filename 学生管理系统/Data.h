/*
该文件有6个类：成绩类、学生类、本科生类、研究生类、班级类和专业类，
其中本科生类和研究生类继承学生类。
*/
#ifndef DATA_H
#define DATA_H

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

//成绩类
class score {
public:
	//有参构造函数------将某个向量的成绩复制到成绩向量中
	score(vector<int>::iterator beg, vector<int>::iterator en) {
		while (beg != en) {
			sco.push_back(*beg);
			++beg;
		}
	}

	//重置构造函数---将成员变量--向量的大小变为n，元素重置为-1
	score(int n) {
		sco.resize(n);
		for (int i = 0; i < n; ++i) {
			sco.push_back(-1);
		}
	}
	//打印整个向量元素
	void print() {
		for (auto a : sco) {
			cout << a << " ";
		}
		cout << endl;
	}
	//向量的最后一个元素为总成绩，获取学生的总成绩
	int getTotalScore()const {
		return *(sco.end() - 1);
	}
	//返回向量的第n个元素---用于返回学生的某科成绩
	int& getScore(int n) {
		return sco[n];
	}

	//计算学生的总成绩，并赋值给向量的最后一个元素
	void calculation() {
		int sum = 0;
		for (int i = 0; i < (int)sco.size()-1; ++i) {//检测是否所有成绩都均已输入
			if (sco[i] == -1) return;
		}
		for (int i = 0; i < (int)sco.size() - 1; ++i) {
			sum += sco[i];
		}
		sco[sco.size() - 1] = sum;
	}
private:
	vector<int> sco;//用于存储各科的成绩的向量
};


//Person类---学生的相关信息和操作
class person {
public:
	//有参构造函数
	person(int i, string na, string se, string num1, string num2, string maj, string cla, int rank1, int rank2, vector<int>::iterator begin, vector<int>::iterator end) :id(i), name(na), sex(se), major_number(num1), class_number(num2), major(maj), Class(cla), gradeRanking(rank1), classRanking(rank2), sco(begin, end)  //初始化列表
	{}
	//构造函数--成绩重置-1
	person(int i, string na, string se, string num1, string num2, string maj, string cla, int rank1, int rank2, int n) :id(i), name(na), sex(se), major_number(num1), class_number(num2), major(maj), Class(cla), gradeRanking(rank1), classRanking(rank2), sco(n)  //初始化列表
	{}

	//为了修改个人信息而用
	virtual void motify(int n) {
		int temp;
		switch (n) {
		case 1:cout << "请输入正确的名字："; cin >> temp; name = temp; break;
		case 2:cout << "请输入正确的性别："; cin >> temp; sex = temp; break;
		}
	}

	//同一返回引用，即左值，之后的函数可以通过返回的值来进行修改
	int& getID() { return id; }        //以下获取信息的放回值均设置为引用是用以左值为了方便修改
	string& getName() { return name; }      //获取姓名
	string& getSex() { return sex; }        //获取性别
	string& getMajorNumber() {return major_number; }//获取专业编号
	string& getClassNumber() { return class_number; }//获取班级编号
	string& getMajor() { return  major; }      //获取专业名称
	string& getClass() { return Class; }      //获取班级名称
	int& getRanking1() { return gradeRanking; }    //获取年级排名
	int& getRanking2() {return classRanking;}    //获取班级排名
	int& getScore(int n) { return sco.getScore(n); }    //获取各科成绩
protected:
	int id;                 //学号
	string name;            //姓名
	string sex;             //性别
	string major_number;    //专业编号
	string class_number;    //班级编号
	string major;           //专业名称
	string Class;           //班级名称
	string type;            //学生类型
	int gradeRanking;       //年级排名
	int classRanking;       //班级排名
	score sco;              //各项目成绩
};


//本科生类
class undergraduate : virtual public person {
public:
	undergraduate(int i, string na, string se, string num1, string num2, string major, string Class, int rank1, int rank2, vector<int>::iterator begin, vector<int>::iterator end) :person(i, na, se, num1, num2, major, Class, rank1, rank2, begin, end)
	{}
	undergraduate(int i, string na, string se, string num1, string num2, string major, string Class, int rank1, int rank2, int n) :person(i, na, se, num1, num2, major, Class, rank1, rank2, n)
	{}

	// //显示所有人信息的时候
	virtual void Display() {
		cout << setw(7) << id << setw(7) << name << setw(5) << sex << setw(11) << major_number << setw(7) << class_number << setw(11) << major << setw(12) << Class << setw(7) << sco.getScore(0) << setw(10) << sco.getScore(1) << setw(10) << sco.getScore(2) << setw(10) << sco.getScore(3) << setw(10) << classRanking << setw(10) << gradeRanking << endl;
	}   

	//显示个人信息
	virtual void print() {
		cout << "【A】ID： " << id << endl;
		cout << "【1】名字： " << name << endl;
		cout << "【2】性别： " << sex << endl;
		cout << "【3】专业编号：" << major_number << endl;
		cout << "【B】专业名称：" << major << endl;
		cout << "【4】班级编号： " << class_number << endl;
		cout << "【C】班级名称：" << Class << endl;
		cout << "【5】C语言成绩： " << sco.getScore(0) << endl;
		cout << "【6】高数成绩： " << sco.getScore(1) << endl;
		cout << "【7】英语成绩： " << sco.getScore(2) << endl;
		cout << "【D】总成绩： " << sco.getScore(3) << endl;
		cout << "【E】班级排名： " << gradeRanking << endl;
		cout << "【F】年级排名： " << classRanking << endl;
	}        

	//修改本科生个人信息
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
			case 5:cout << "请输入正确的C语言成绩："; cin >> score; sco.getScore(0) = score; break;
			case 6:cout << "请输入正确的高数成绩："; cin >> score; sco.getScore(1) = score; break;
			case 7:cout << "请输入正确的英语成绩："; cin >> score; sco.getScore(2) = score; break;
			case 0:cout << "修改结束，请按任意键回到菜单处！" << endl; break;
			}
			sco.calculation();  //计算总成绩
		}
		cout << "修改成功！" << endl;
	}

};


//研究生类
class graduate :virtual public person
{
public:
	graduate(int i, string na, string se, string num1, string num2, string major, string Class, int rank1, int rank2, vector<int>::iterator begin, vector<int>::iterator end) :person(i, na, se, num1, num2, major, Class, rank1, rank2, begin, end)
	{}
	graduate(int i, string na, string se, string num1, string num2, string major, string Class, int rank1, int rank2, int n) :person(i, na, se, num1, num2, major, Class, rank1, rank2, n)
	{}

	//用于显示所有人的信息的时候
	virtual void Display() {
		cout << setw(7) << id << setw(7) << name << setw(5) << sex << setw(11) << major_number << setw(7) << class_number << setw(11) << major << setw(12) << Class << setw(9) << sco.getScore(0) << setw(12) << sco.getScore(1) << setw(10) << sco.getScore(2) << setw(7) << classRanking << setw(10) << gradeRanking << endl;
	}
	//详细显显示个人信息
	virtual void print() {
		cout << "【A】ID： " << id << endl;
		cout << "【1】名字： " << name << endl;
		cout << "【2】性别： " << sex << endl;
		cout << "【3】专业编号：" << major_number << endl;
		cout << "【B】专业名称： " << major << endl;
		cout << "【4】班级编号： " << class_number << endl;
		cout << "【C】班级名称： " << Class << endl;
		cout << "【5】课程综合成绩： " << sco.getScore(0) << endl;
		cout << "【6】论文成绩： " << sco.getScore(1) << endl;
		cout << "【D】总成绩： " << sco.getScore(2) << endl;
		cout << "【E】班级排名： " << gradeRanking << endl;
		cout << "【F】年级排名： " << classRanking << endl;
	}
	//修改研究生个人信息
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
			case 5:cout << "请输入正确的课程设计成绩："; cin >> score; sco.getScore(0) = score; break;
			case 6:cout << "请输入正确的论文成绩："; cin >> score; sco.getScore(1) = score; break;
			case 0:cout << "修改结束，请按任意键回到菜单处！" << endl; break;
			}
			sco.calculation();
		}
		cout << "修改成功！" << endl;
	}
};

//班级类
class Class
{
private:
	string major_number;  //专业编号
	string major;         //专业名称
	string name;          //班级名称
	string id;            //班级编号
public:
	Class(string number, string maj, string na, string i) :major_number(number), major(maj), name(na), id(i)
	{}

	//用于显示所有的班级名称
	void Display() const {
		cout << setw(15) << major_number << setw(11) << major << setw(17) << id << setw(17) << name << endl;
	}

	//同一返回引用，即左值，之后的函数可以通过返回的值来进行修改
	string& getMajor_number() { return major_number; }      //获取专业编号  
	string& getMajor() { return major; }             //获取专业名称
	string& getName() { return name; }              //获取班级名称
	string& getID() { return id; }                //获取班级编号
};

//专业类
class major {
private:
	string name;        //专业名称
	string id;          //专业编号
public:
	major(string na, string i) :name(na), id(i)      //构造函数
	{}

	//显示函数
	void Display() const {
		cout << setw(14) << id << setw(12) << name << endl;
	}                       
	string &getName() { return name; }                           //获取专业名称
	string &getID() { return id; }                              //获取专业编号
};


//教师类
class teacher {
public:
	teacher(int i, string na, string nu, string pa) :id(i), name(na), number(nu), password(pa) {}//构造函数
	//同一返回引用，即左值，之后的函数可以通过返回的值来进行修改
	int& getId() { return id; }      //获取id  
	string& getName() { return name; }             //获取姓名
	string& getNumber() { return number; }              //获取账号
	string& getPassword() { return password; }                //获取密码

	void Display() {
		cout << setw(11) << id << setw(11) << name << setw(11) << number<< setw(11) << password<< endl;
	}

private:
	int id;//老师编号
	string name;//老师姓名
	string number;//账号
	string password;//密码
};
class administor {
public:
	administor(int i, string na, string nu, string pa) :id(i), name(na), number(nu), password(pa) {}//构造函数
	//同一返回引用，即左值，之后的函数可以通过返回的值来进行修改
	int& getId() { return id; }      //获取id 
	string& getName() { return name; }             //获取姓名
	string& getNumber() { return number; }              //获取账号
	string& getPassword() { return password; }                //获取密码

	void Display() {
		cout << setw(11) << id << setw(11) << name << setw(11) << number << setw(11) << password << endl;
	}

private:
	int id;//管理员编号
	string name;//管理员姓名
	string number;//账号
	string password;//密码
};

#endif // !DATA_H