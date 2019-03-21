#include <iostream>
#include <cstring>
#include <iomanip>
#include <conio.h>
#include <fstream>

// ���벿�� 

int chcode() 
{
    char pw[50],ch;
    char *syspw = "123456"; // ԭʼ����
    int i,m = 0;
    printf("����������:");
    while(m < 3)
	 {
        i = 0;
        while((ch = _getch()) != '\r') {
            if(ch == '\b' && i > 0) {
                printf("\b \b");
                --i;
            }
            else if(ch != '\b') {
                pw[i++] = ch;
                printf("*");
            }
        }
        pw[i] = '\0';
        printf("\n");
        if(strcmp(pw,syspw) != 0) {
            printf("�����������������!\n");
            m++;
        }
        else {
            printf("������ȷ��\n");
            return 1;
        }
    }
    printf("����3����������˳�!\n");
    system("pause");
    return 0;
}

using namespace std;
class Student
{
	public:
		void menu();                                   //�˵�
		Student* Input(Student stu[],int &num);        //¼��ѧ�� 
		void Output(Student stu[],int &num);           //��ʾ��Ϣ 
		void Order(Student stu[],int &num);            //�������� 
		void Search(Student stu[],int &num);           //����ѧ��
		Student* Insert(Student stu[],int &num);       //����ѧ�� 
		void Delete(Student stu[],int &num);           //ɾ��ѧ�� 
		void Statis(Student stu[],int &num);           //ͳ������ 
		void inputId();                                //����ѧ�� 
		void inputName();                              //�������� 
		void inputRegularGrade();                      //����ƽʱ�ɼ� 
		void inputFinalExam();                         //������ĩ���Գɼ� 
		int getId();                                   //���ѧ�� 
	
	
		double CalTotalMark();                         //���������ɼ� 
	private:
		int id;                                        //ѧ�� 
		char name[20];                                 //���� 
		double regularGrade;                           //ƽʱ�ɼ� 
		double finalExam;                              //��ĩ���Գɼ�
};

using namespace std;



void Student::inputId()
{
	do
	{
		cout<<"������ѧ�ţ�1-40��";
		cin>>id;
		if(id<1||id>40)
		{
			cout<<"�������ѧ��Ӧ����1-40֮��";
			cin>>id; 
		}
		else
		break;
		
	}
	while(1);
}

void Student::inputName()
{
	cout<<"������������";
	cin>>name;
}

void Student::inputRegularGrade()
{
	do
	{
		cout<<"������ƽʱ�ɼ���0-100����";
		cin>>regularGrade;
		if(regularGrade<0||regularGrade>100)
		{
			cout<<"�������󣡳ɼ�Ӧ����0-100֮��";
			cin>>regularGrade;
		}
		else
		break;
	}
	while(1); 
}

void Student::inputFinalExam()
{
	do
	{
		cout<<"��������ĩ�ɼ���0-100����";
		cin>>finalExam;
		if(finalExam<0||finalExam>100)
		{
			cout<<"�������󣡳ɼ�Ӧ����0-100֮��";
			cin>>finalExam;
		}
		else
		break;
	}
	while(1);
}

int Student::getId()
{
	return id;
}

double Student::CalTotalMark()
{
		return regularGrade*0.5+finalExam*0.5;
}

void Student::menu()                   //�˵� 
{
          cout<<"========================================="<<endl;
          cout<<"=          ��ӭʹ�óɼ�����ϵͳ         ="<<endl;
          cout<<"=       1=¼��ѧ��     2=��ʾ��Ϣ       ="<<endl;
          cout<<"=       3=��������     4=����ѧ��       ="<<endl;
          cout<<"=       5=����ѧ��     6=ɾ��ѧ��       ="<<endl;
          cout<<"=       7=ͳ������     0=�˳�           ="<<endl;
          cout<<"========================================="<<endl;
}

Student* Student::Input(Student stu[],int &num)                        //¼��ѧ��
{
	
	int x=0;
	int i=0;
	char c;
	do{
	
       	while(1)                                                     //�ж�ѧ�� �Ƿ��ظ� 
		{
			stu[num].inputId();
			for(i=0;i<num;i++)
				if(stu[num].getId()==stu[i].getId())
					break;
			
			if(i>=num)
				break;
				
			else
				cout<<"ѧ�Ų������ظ�����ѧ���Ѿ����ڣ�"<<endl; 
				
		}
		stu[num].inputName();
		stu[num].inputRegularGrade();
		stu[num].inputFinalExam();
		num++;
		cout<<"��������ѧ�������밴y��Y��";
		cin>>c;
	
}
while(c=='y'||c=='Y');
return stu;
}

void Student::Output(Student stu[],int &num)        //��ʾ��Ϣ 
{
	int i=0;
	cout<<setw(10)<<"ѧ��"<<setw(10)<<"����"<<setw(10)<<"ƽʱ"<<setw(10)<<"��ĩ"<<endl; 
	for(i=0;i<num;i++)
		cout<<setw(10)<<id<<setw(10)<<name<<setw(10)<<regularGrade<<setw(10)<<finalExam<<endl;
	    cout<<endl;
}

void Student::Order(Student stu[],int &num)       //��������
{
	Student t;
	int i, j;
	for(i=0;i<num;i++)
		for(j=i+1;j<num;j++)
			if(stu[i].CalTotalMark()<stu[j].CalTotalMark())
			{
				t = stu[i];
				stu[i] = stu[j]; 
				stu[j] = t;
			}
	Output(stu,num);
}

void Student::Search(Student stu[],int &num)        //����ѧ�� 
{
	char c;
	int i=0, idd;
	
	do
	{
		cout<<"��������Ҫ���ҵ�ѧ�ţ�";
		cin>>idd;
		for(i=0;i<num;i++)
			if(idd==stu[i].getId())
			{
					cout<<setw(10)<<"ѧ��"<<setw(10)<<"����"<<setw(10)<<"ƽʱ�ɼ�"<<setw(10)<<"��ĩ�ɼ�"; 
				cout<<setw(10)<<id<<setw(10)<<name<<setw(10)<<regularGrade<<setw(10)<<finalExam<<endl;
			
				break;
			}
		if(i>=num)
			cout<<"û�и�ѧ��ѧ����Ϣ��"<<endl;
		cout<<"���������밴y��Y��";
		cin>>c;
	}
	while(c=='y'||c=='Y');
		
}

Student* Student::Insert(Student stu[],int &num)     //����ѧ��
{
    Student t;
	char c;
	int i=0, j;
	
	do
	{
		
		cout<<"��������ѧ����Ϣ"<<endl;
		stu[num].inputId();
		for(i=0;i<num;i++)
			if(stu[i].getId()==stu[num].getId())
			{
				cout<<"��ѧ���Ѵ��ڣ�"<<endl;
				break;
			}	
		if(i>=num)
		{
			stu[num].inputName();
			stu[num].inputRegularGrade();
			stu[num].inputFinalExam();
			for(i=0;i<num+1;i++)
			{
				
				for(j=i+1;j<num+1;j++)
					if(stu[j].getId()<stu[i].getId())
					{
						t = stu[i];
						stu[i] = stu[j]; 
						stu[j] = t;
					}
			}
			num++;
		}
			
		cout<<"��������밴y��Y��";
		cin>>c;
	}
	while(c=='y'||c=='Y');

	return stu;
}

void Student::Delete(Student stu[],int &num)                             //ɾ��ѧ��
{
	char c;
	int i=0, j, idd;
	do
	{
		cout<<"������Ҫɾ��ѧ����ѧ�ţ�";
		cin>>idd;
		for(i=0;i<num;i++)
			if(idd==stu[i].getId())
			{
				for(j=i;j<num;j++)
					stu[j] = stu[j+1];
				
				break;
			}
		if(i>=num)
			cout<<"û�и�ѧ��ѧ����"<<endl;
		num--;	
		cout<<"����ɾ���밴y��Y��";
		cin>>c;
	}
	while(c=='y'||c=='Y');

}

void Student::Statis(Student stu[],int &num)                 //ͳ������ 
{
	int a=0, b=0, c=0, d=0, e=0;
	for(int i=0;i<num;i++)
		if(stu[i].CalTotalMark()<60)
			a++;
		else if(stu[i].CalTotalMark()<70)
			b++;
		else if(stu[i].CalTotalMark()<80)
			c++;
		else if(stu[i].CalTotalMark()<90)
			d++;
		else
			e++;
	cout<<" "<<"100~90"<<" "<<"89~80"<<" "<<"79~70"<<" "<<"69~60"<<" "<<"<60"<<endl;
	cout<<" "<<e<<" "<<d<<" "<<c<<" "<<b<<" "<<a;
}

int main()
{
      if(chcode())
            printf("��¼�ɹ�!\n");
      else
      {
            printf("��¼ʧ��!\n");
            return 0;
      }
    Student s1, *stu;
    int currentN=0;
    int s;
    int n=0;
   
		
		ifstream filein("student dat",ios::binary);
		if(filein)
		{
			filein.read((char*)&currentN,sizeof(currentN)) ;
			for(int i=0;i<currentN;i++)
			filein.read((char*)&(stu[i]),sizeof(stu[i])); 
		}
		filein.close();
		
		while(s)
		{
			s1.menu();
			cout<<"��ѡ��";
			cin>>s;
		    if(s==1)
		    {
		    	s1.Input(stu,n);
			}
			if(s==2)
			{
			     s1.Output(stu,n);
			}
			if(s==3)
			{
				s1.Order(stu,n);
			}
			if(s==4)
			{
				s1.Search(stu,n);
			}
			if(s==5)
			{
				s1.Insert(stu,n) ;
			}
			if(s==6)
			{
				s1.Delete(stu,n);
			}
			if(s==7)
			{
				s1.Statis(stu,n);
			}
			if(s==0)
			{
				ofstream fileout("student dat",ios::binary);
              if(!fileout)
           {
         	cout<<"�ļ����ܱ���";
        	return 0;
	          }
	            fileout.write((char*)&currentN,sizeof(currentN));
	                for(int i=0;i<currentN;i++)
	                  fileout.write((char*)&(stu[i]),sizeof(stu[i]));
	                	fileout.close();
	                    	return 0; 
			}
			ofstream fileout("student dat",ios::binary);
	            fileout.write((char*)&currentN,sizeof(currentN));
	            for(int i=0;i<currentN;i++)
	            fileout.write((char*)&(stu[i]),sizeof(stu[i]));
		        fileout.close();
	
		}
  }
