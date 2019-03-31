#include"interface.h"

Interface::Interface() {
	//创建四个文件
	ifstream  student1("undergraduate");//创建第一个文件--用于存储本科生信息
	if (!student1) {//若文件不存在，则直接返回
		cout << "can not open the file（undergraduate） !" << endl;
		return;
	}
	ifstream student2("graduate");//创建第二个文件--用于存储研究生信息
	if (!student2)//若文件不存在，则直接返回
	{
		cout << "can not open the file（graduate） !" << endl;
		return;
	}
	ifstream Major("major");//创建第三个文件--用于存储专业信息
	if (!Major)//若文件不存在，则直接返回
	{
		cout << "can not open the file（major） !" << endl;
		return;
	}
	ifstream cla("Class");//创建第四个文件--用于存储班级信息
	if (!cla)//若文件不存在，则直接返回
	{
		cout << "can not open the file（Class） !" << endl;
		return;
	}
	ifstream tea("Teacher");//创建第四个文件--用于存储班级信息
	if (!tea)//若文件不存在，则直接返回
	{
		cout << "can not open the file（Teacher） !" << endl;
		return;
	}
	ifstream adm("Administor");//创建第四个文件--用于存储班级信息
	if (!adm)//若文件不存在，则直接返回
	{
		cout << "can not open the file（administor） !" << endl;
		return;
	}

	int id;//学号
	string name;//姓名
	string sex;//性别
	string major_number;//专业编号
	string class_number;//班级编号
	string major_name;//专业名称
	string class_name;//班级名称
	int gradeRanking;//年级排名
	int classRanking;//班级排名

	//读取本科生文件中的数据，存储到向量中
	vector<int>score1(4, 0);
	student1 >> id >> name >> sex >> major_number >> class_number >> major_name >> class_name >> gradeRanking >> classRanking >> score1[0] >> score1[1] >> score1[2] >> score1[3];
	while (!student1.eof())//eof()函数用来判断文件是否为空，或是判断其是否读到文件结尾
	{
		undergraduate student(id, name, sex, major_number, class_number, major_name, class_name, gradeRanking, classRanking, score1.begin(), score1.end());
		stu1.push_back(student);
		count1++;   //记录本科生总人数
		student1 >> id >> name  >> sex >> major_number >> class_number >> major_name >> class_name >> gradeRanking >> classRanking >> score1[0] >> score1[1] >> score1[2] >> score1[3];
	}

	//读取研究生文件中的数据，存储到向量中
	score1.clear();
	vector<int> score2(3, 0);
	student2 >> id >> name >> sex >> major_number >> class_number >> major_name >> class_name >> gradeRanking >> classRanking >> score2[0] >> score2[1] >> score2[2];
	while (!student2.eof()) // eof()函数用来判断文件是否为空，或是判断其是否读到文件结尾
	{
		graduate student(id, name, sex, major_number, class_number, major_name, class_name, gradeRanking, classRanking, score2.begin(), score2.end());
		stu2.push_back(student);
		count2++;    //记录研究生总人数
		student2 >> id >> name >> sex >> major_number >> class_number >> major_name >> class_name >> gradeRanking >> classRanking >> score2[0] >> score2[1] >> score2[2];
	}

	//读取班级信息文件中的数据,存储到向量中
	string major_number1;
	string major_name1;
	string class_name1;
	string class_number1;
	cla >> major_number1 >> major_name1 >> class_name1 >> class_number1;
	while (!cla.eof())
	{
		Class class1(major_number1, major_name1, class_name1, class_number1);
		Cla.push_back(class1);
		count3++;     //记录班级总数
		cla >> major_number1 >> major_name1 >> class_name1>> class_number1;
	}

	//读取专业信息文件中的数据
	string major_number2;
	string major_name2;
	Major >> major_name2 >> major_number2;
	while (!Major.eof())
	{
		major maj1(major_name2, major_number2);
		maj.push_back(maj1);
		count4++;    //记录专业总数
		Major >> major_name2 >> major_number2;
	}

	//读取教师信息文件中的数据,存储到向量中
	int teacher_id;
	string teacher_name;
	string teacher_number;
	string teacher_password;
	tea >> teacher_id >> teacher_name >> teacher_number >> teacher_password;
	while (!tea.eof())
	{
		teacher teacher1(teacher_id, teacher_name, teacher_number, teacher_password);
		Tea.push_back(teacher1);
		count5++;     //记录教师总数
		tea >> teacher_id >> teacher_name >> teacher_number >> teacher_password;
	}

	//读取管理员信息文件中的数据,存储到向量中
	administor administor1(0, "xzz", "123456", "123456");//在管理员向量中加入一个最初的管理者
	Adm.push_back(administor1);
	count6 += 1;     //记录教师总数

	int administor_id;
	string administor_name;
	string administor_number;
	string administor_password;
	adm >> administor_id >> administor_name >> administor_number >> administor_password;
	while (!adm.eof())
	{
		administor administor2(administor_id, administor_name, administor_number, administor_password);
		Adm.push_back(administor2);
		count6++;     //记录教师总数
		adm >> administor_id >> administor_name >> administor_number >> administor_password;
	}

	//读取完毕，关闭文件
	student1.close();
	student2.close();
	Major.close();
	cla.close();
	tea.close();
	adm.close();
}

void Interface::save() {
	ofstream out1("undergraduate");
	if (!out1)
	{
		cout << "打开文件1失败，无法保存数据" << endl;
		return;
	}
	ofstream out2("graduate");
	if (!out2)
	{
		cout << "打开文件2失败，无法保存数据" << endl;
		return;
	}
	ofstream out3("Class");
	if (!out3)
	{
		cout << "打开文件3失败，无法保存数据" << endl;
		return;
	}
	ofstream out4("major");
	if (!out4)
	{
		cout << "打开文件4失败，无法保存数据" << endl;
		return;
	}
	ofstream out5("teacher");
	if (!out5)
	{
		cout << "打开文件5失败，无法保存数据" << endl;
		return;
	}
	ofstream out6("administor");
	if (!out6)
	{
		cout << "打开文件6失败，无法保存数据" << endl;
		return;
	}

	//存储本科生信息
	for (auto a : stu1) {
		out1 << a.getID() << " " << a.getName() << " " << a.getSex() << " " << a.getMajorNumber() << " " << a.getClassNumber() << " " << a.getMajor() << " " << a.getClass() << " " << a.getRanking1() << " " << a.getRanking2() << " " << a.getScore(0) << " " << a.getScore(1) << " " << a.getScore(2) << " " << a.getScore(3) << endl;
	}
	printf("成功存储%d位本科生的信息！\n", count1);
	out1.close();

	//存储研究生信息
	for (auto a : stu2) {
		out2 << a.getID() << " " << a.getName() << " " << a.getSex() << " " << a.getMajorNumber() << " " << a.getClassNumber() << " " << a.getMajor() << " " << a.getClass() << " " << a.getRanking1() << " " << a.getRanking2() << " " << a.getScore(0) << " " << a.getScore(1) << " " << a.getScore(2) << " " << endl;
	}
	printf("成功存储%d位研究生的信息！\n", count2);
	out2.close();

	//存储班级信息
	for (auto a : Cla) {
		out3 << a.getMajor_number() << " " << a.getMajor() << " " << a.getName() << " " << a.getID() << endl;
	}
	printf("成功存储%d个班级的信息！\n", count3);
	out3.close();

	//存储专业信息
	for (auto a : maj) {
		out4 << a.getName() << " " << a.getID() << endl;
	}
	printf("成功存储%d个专业的信息！\n", count4);
	out4.close();

	//存储教师信息
	for (auto a : Tea) {
		out5 << a.getName() << " " << a.getId() << endl;
	}
	printf("成功存储%d个专业的信息！\n", count5);
	out5.close();

	//存储管理员信息
	for (auto a : Adm) {
		out6 << a.getName() << " " << a.getId() << endl;
	}
	printf("成功存储%d个专业的信息！\n", count6);
	out6.close();
}