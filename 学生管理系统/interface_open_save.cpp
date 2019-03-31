#include"interface.h"

Interface::Interface() {
	//�����ĸ��ļ�
	ifstream  student1("undergraduate");//������һ���ļ�--���ڴ洢��������Ϣ
	if (!student1) {//���ļ������ڣ���ֱ�ӷ���
		cout << "can not open the file��undergraduate�� !" << endl;
		return;
	}
	ifstream student2("graduate");//�����ڶ����ļ�--���ڴ洢�о�����Ϣ
	if (!student2)//���ļ������ڣ���ֱ�ӷ���
	{
		cout << "can not open the file��graduate�� !" << endl;
		return;
	}
	ifstream Major("major");//�����������ļ�--���ڴ洢רҵ��Ϣ
	if (!Major)//���ļ������ڣ���ֱ�ӷ���
	{
		cout << "can not open the file��major�� !" << endl;
		return;
	}
	ifstream cla("Class");//�������ĸ��ļ�--���ڴ洢�༶��Ϣ
	if (!cla)//���ļ������ڣ���ֱ�ӷ���
	{
		cout << "can not open the file��Class�� !" << endl;
		return;
	}
	ifstream tea("Teacher");//�������ĸ��ļ�--���ڴ洢�༶��Ϣ
	if (!tea)//���ļ������ڣ���ֱ�ӷ���
	{
		cout << "can not open the file��Teacher�� !" << endl;
		return;
	}
	ifstream adm("Administor");//�������ĸ��ļ�--���ڴ洢�༶��Ϣ
	if (!adm)//���ļ������ڣ���ֱ�ӷ���
	{
		cout << "can not open the file��administor�� !" << endl;
		return;
	}

	int id;//ѧ��
	string name;//����
	string sex;//�Ա�
	string major_number;//רҵ���
	string class_number;//�༶���
	string major_name;//רҵ����
	string class_name;//�༶����
	int gradeRanking;//�꼶����
	int classRanking;//�༶����

	//��ȡ�������ļ��е����ݣ��洢��������
	vector<int>score1(4, 0);
	student1 >> id >> name >> sex >> major_number >> class_number >> major_name >> class_name >> gradeRanking >> classRanking >> score1[0] >> score1[1] >> score1[2] >> score1[3];
	while (!student1.eof())//eof()���������ж��ļ��Ƿ�Ϊ�գ������ж����Ƿ�����ļ���β
	{
		undergraduate student(id, name, sex, major_number, class_number, major_name, class_name, gradeRanking, classRanking, score1.begin(), score1.end());
		stu1.push_back(student);
		count1++;   //��¼������������
		student1 >> id >> name  >> sex >> major_number >> class_number >> major_name >> class_name >> gradeRanking >> classRanking >> score1[0] >> score1[1] >> score1[2] >> score1[3];
	}

	//��ȡ�о����ļ��е����ݣ��洢��������
	score1.clear();
	vector<int> score2(3, 0);
	student2 >> id >> name >> sex >> major_number >> class_number >> major_name >> class_name >> gradeRanking >> classRanking >> score2[0] >> score2[1] >> score2[2];
	while (!student2.eof()) // eof()���������ж��ļ��Ƿ�Ϊ�գ������ж����Ƿ�����ļ���β
	{
		graduate student(id, name, sex, major_number, class_number, major_name, class_name, gradeRanking, classRanking, score2.begin(), score2.end());
		stu2.push_back(student);
		count2++;    //��¼�о���������
		student2 >> id >> name >> sex >> major_number >> class_number >> major_name >> class_name >> gradeRanking >> classRanking >> score2[0] >> score2[1] >> score2[2];
	}

	//��ȡ�༶��Ϣ�ļ��е�����,�洢��������
	string major_number1;
	string major_name1;
	string class_name1;
	string class_number1;
	cla >> major_number1 >> major_name1 >> class_name1 >> class_number1;
	while (!cla.eof())
	{
		Class class1(major_number1, major_name1, class_name1, class_number1);
		Cla.push_back(class1);
		count3++;     //��¼�༶����
		cla >> major_number1 >> major_name1 >> class_name1>> class_number1;
	}

	//��ȡרҵ��Ϣ�ļ��е�����
	string major_number2;
	string major_name2;
	Major >> major_name2 >> major_number2;
	while (!Major.eof())
	{
		major maj1(major_name2, major_number2);
		maj.push_back(maj1);
		count4++;    //��¼רҵ����
		Major >> major_name2 >> major_number2;
	}

	//��ȡ��ʦ��Ϣ�ļ��е�����,�洢��������
	int teacher_id;
	string teacher_name;
	string teacher_number;
	string teacher_password;
	tea >> teacher_id >> teacher_name >> teacher_number >> teacher_password;
	while (!tea.eof())
	{
		teacher teacher1(teacher_id, teacher_name, teacher_number, teacher_password);
		Tea.push_back(teacher1);
		count5++;     //��¼��ʦ����
		tea >> teacher_id >> teacher_name >> teacher_number >> teacher_password;
	}

	//��ȡ����Ա��Ϣ�ļ��е�����,�洢��������
	administor administor1(0, "xzz", "123456", "123456");//�ڹ���Ա�����м���һ������Ĺ�����
	Adm.push_back(administor1);
	count6 += 1;     //��¼��ʦ����

	int administor_id;
	string administor_name;
	string administor_number;
	string administor_password;
	adm >> administor_id >> administor_name >> administor_number >> administor_password;
	while (!adm.eof())
	{
		administor administor2(administor_id, administor_name, administor_number, administor_password);
		Adm.push_back(administor2);
		count6++;     //��¼��ʦ����
		adm >> administor_id >> administor_name >> administor_number >> administor_password;
	}

	//��ȡ��ϣ��ر��ļ�
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
		cout << "���ļ�1ʧ�ܣ��޷���������" << endl;
		return;
	}
	ofstream out2("graduate");
	if (!out2)
	{
		cout << "���ļ�2ʧ�ܣ��޷���������" << endl;
		return;
	}
	ofstream out3("Class");
	if (!out3)
	{
		cout << "���ļ�3ʧ�ܣ��޷���������" << endl;
		return;
	}
	ofstream out4("major");
	if (!out4)
	{
		cout << "���ļ�4ʧ�ܣ��޷���������" << endl;
		return;
	}
	ofstream out5("teacher");
	if (!out5)
	{
		cout << "���ļ�5ʧ�ܣ��޷���������" << endl;
		return;
	}
	ofstream out6("administor");
	if (!out6)
	{
		cout << "���ļ�6ʧ�ܣ��޷���������" << endl;
		return;
	}

	//�洢��������Ϣ
	for (auto a : stu1) {
		out1 << a.getID() << " " << a.getName() << " " << a.getSex() << " " << a.getMajorNumber() << " " << a.getClassNumber() << " " << a.getMajor() << " " << a.getClass() << " " << a.getRanking1() << " " << a.getRanking2() << " " << a.getScore(0) << " " << a.getScore(1) << " " << a.getScore(2) << " " << a.getScore(3) << endl;
	}
	printf("�ɹ��洢%dλ����������Ϣ��\n", count1);
	out1.close();

	//�洢�о�����Ϣ
	for (auto a : stu2) {
		out2 << a.getID() << " " << a.getName() << " " << a.getSex() << " " << a.getMajorNumber() << " " << a.getClassNumber() << " " << a.getMajor() << " " << a.getClass() << " " << a.getRanking1() << " " << a.getRanking2() << " " << a.getScore(0) << " " << a.getScore(1) << " " << a.getScore(2) << " " << endl;
	}
	printf("�ɹ��洢%dλ�о�������Ϣ��\n", count2);
	out2.close();

	//�洢�༶��Ϣ
	for (auto a : Cla) {
		out3 << a.getMajor_number() << " " << a.getMajor() << " " << a.getName() << " " << a.getID() << endl;
	}
	printf("�ɹ��洢%d���༶����Ϣ��\n", count3);
	out3.close();

	//�洢רҵ��Ϣ
	for (auto a : maj) {
		out4 << a.getName() << " " << a.getID() << endl;
	}
	printf("�ɹ��洢%d��רҵ����Ϣ��\n", count4);
	out4.close();

	//�洢��ʦ��Ϣ
	for (auto a : Tea) {
		out5 << a.getName() << " " << a.getId() << endl;
	}
	printf("�ɹ��洢%d��רҵ����Ϣ��\n", count5);
	out5.close();

	//�洢����Ա��Ϣ
	for (auto a : Adm) {
		out6 << a.getName() << " " << a.getId() << endl;
	}
	printf("�ɹ��洢%d��רҵ����Ϣ��\n", count6);
	out6.close();
}