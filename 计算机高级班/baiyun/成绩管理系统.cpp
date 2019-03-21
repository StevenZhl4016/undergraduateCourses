#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include<set>
#include<cstdio>
#include<iomanip>
#include<map>
using namespace std;
const vector<int>::size_type max_student_num = 2;
int welcome()
{
	set<int> modestd = { 0,1,2,3,4,5,6,7 };
	cout << "          =========================================" << endl;
	cout << "          =          ��ӭʹ�óɼ�����ϵͳ         =" << endl;
	cout << "          =       1=¼��ѧ��     2=��ʾ��Ϣ       =" << endl;
	cout << "          =       3=��������     4=����ѧ��       =" << endl;
	cout << "          =       5=����ѧ��     6=ɾ��ѧ��       =" << endl;
	cout << "          =       7=ͳ������     0=�˳�           =" << endl;
	cout << "          =========================================" << endl;
	cout << "��ѡ��";
	int mode;
	cin >> mode;
	while (modestd.find(mode) == modestd.end())
	{
		cout << "����Ƿ������������룡" << endl;
		welcome();
		cin >> mode;
	}
	return mode;
}
struct student
{
	student() = default;
	double usualscore;
	string name;
	int num;
	double finalscore;
	double sum;
};
vector<student> aaa;
map<int, student> ppp;
set<int> lll;
int mode1()
{
	if (aaa.size() >= max_student_num)
	{
		cout << "���������Ѵﵽ" << max_student_num << "�����ޣ��޷������룡" << endl;
		return 0;
	}
	student tem;
	int tem2;
	cout << "������ѧ�ţ�1-40��֮�䣺";
	cin >> tem2;
	while (tem2>40||tem2<0||(lll.find(tem2)!=lll.end()))
	{
		if (tem2 > 40 || tem2 < 0)
		{
			cout << "����ѧ�ŷǷ������������룡" << endl;
			cout << "������ѧ�ţ�1-40��֮�䣺";
		}
		else
			cout << "ѧ�Ų������ظ�����ѧ���Ѿ����ڣ�" << endl<<"������ѧ�ţ�1-40��֮��:";
		cin >> tem2;
	}
	tem.num = tem2;
	cout << "������������";
	cin >> tem.name;
	cout << "������ƽʱ�ɼ���0~100)��";
	cin >> tem2;
	while (tem2 > 100 || tem2 < 0)
	{
		cout << "������󣬳ɼ�Ӧ����0��100֮�䣡" << endl;
		cout << "������ƽʱ�ɼ���0~100)��";
		cin >> tem2;
	}
	tem.usualscore = tem2;
	cout << "��������ĩ���Գɼ���0~100)��";
	cin >> tem2;
	while (tem2 > 100 || tem2 < 0)
	{
		cout << "������󣬳ɼ�Ӧ����0��100֮�䣡" << endl;
		cout << "��������ĩ���Գɼ���0~100)��";
		cin >> tem2;
	}
	tem.finalscore = tem2;
	tem.sum = tem.finalscore/2 + tem.usualscore/2;
	aaa.push_back(tem);
	ppp[tem.num] = tem;
	lll.insert(tem.num);
	cout << "��������ѧ�������밴y��Y��";
	char tem3;
	cin >> tem3;
	if (tem3 == 'y' || tem3 == 'Y')
	{
		mode1();
	}
	return 0;
}
int mode2()
{
	if (!aaa.size()){cout << "û��ѧ����Ϣ��" << endl;return 0;}
	cout << "      ѧ��           ����           ƽʱ           ��ĩ           ����" << endl;
	for (auto c : aaa)
	{
		printf("%10d", c.num);
		cout << setw(15) << c.name;
		printf("%15.1f", c.usualscore);
		printf("%15.1f", c.finalscore);
		printf("%15.1f", c.sum);
		cout << endl;
	}
	return 0;
}
int mode3()
{
	sort(aaa.begin(), aaa.end(), [=](student a, student b) {return a.sum > b.sum;});
	if (!aaa.size()) { cout << "û��ѧ����Ϣ��" << endl;return 0; }
	cout << "      ѧ��           ����           ƽʱ           ��ĩ           ����" << endl;
	for (auto c : aaa)
	{
		printf("%10d", c.num);
		cout << setw(15)<< c.name;
		printf("%15.1f", c.usualscore);
		printf("%15.1f", c.finalscore);
		printf("%15.1f", c.sum);
		cout << endl;
	}
	return 0;
}
int mode4()
{
	cout << "��������Ҫ���ҵ�ѧ�ţ�";
	int tem1;cin >> tem1;
	if (lll.find(tem1)!=lll.end())
	{
		cout << "      ѧ��           ����           ƽʱ           ��ĩ           ����" << endl;
		printf("%10d", ppp[tem1].num);
		cout << setw(15) << ppp[tem1].name;
		printf("%15.1f", ppp[tem1].usualscore);
		printf("%15.1f", ppp[tem1].finalscore);
		printf("%15.1f", ppp[tem1].sum);
		cout << endl;
	}
	else cout << "û�и�ѧ��ѧ����Ϣ��"<<endl;
	return 0;
}
int mode7()
{
	cout << "    100~90   89~80   79~70   69~60    <60" << endl;
	int a[5] = { 0,0,0,0,0 };
	for (auto c : aaa)
	{
		if (c.sum >= 90)++a[0];
		else if (c.sum >= 80) ++a[1];
		else if (c.sum >= 70)++a[2];
		else if (c.sum >= 60)++a[3];
		else ++a[4];
	}
	for (auto c : a)
		cout << setw(8) << c;
	cout << endl;
	return 0;
}
int mode6()
{
	cout << "������Ҫɾ��ѧ����ѧ�ţ�";
	int n;
	cin >> n;
	if(lll.find(n)==lll.end())
	{
		cout << "û�и�ѧ��ѧ����" << endl;
		return 0;
	}
	else
	{
		lll.erase(n);
		for (auto c = aaa.begin();c != aaa.end();)
		{
			if (c->num == n) { aaa.erase(c);break; }
		}
		cout << n << "��ѧ����Ϣɾ���ɹ���" << endl;
	}
	return 0;
}
int main()
{
	vector<student>	aaa;
	int mode = welcome();
	char choice;
	while (mode != 0)
	{
		if (mode == 1)
		{
			cout << "��ѡ����1=¼��ѧ��" << endl;
			mode1();
		}
		else if (mode == 2) {
			cout << "��ѡ����2=��ʾ��Ϣ" << endl;
			mode2();
		}
		else if (mode == 5)
		{
			cout << "��ѡ����5=����ѧ��" << endl;
			mode1();
		}
		else if (mode == 3)
		{
			cout << "��ѡ����3=��������" << endl;
			mode3();
		}
		else if (mode == 4)
		{
			cout << "��ѡ����4=����ѧ��" << endl;
			mode4();
			cout << "���������밴y��Y��";
			cin >> choice;
			while (choice == 'y' || choice == 'Y')
			{
				mode4();
				cout << "���������밴y��Y��";
				cin >> choice;
			}
		}
		else if (mode == 7)
			mode7();
		else if (mode == 6)
		{
			mode6();
			char choice2;
			cout << " ����ɾ������ѧ���밴y��Y��";
			cin >> choice2;
			while (choice2 == 'y' || choice2 == 'Y')
			{
				mode6();
				cout << " ����ɾ������ѧ���밴y��Y��";
				cin >> choice2;
			}
		}
		mode = welcome();
		}
	return 0;
	}