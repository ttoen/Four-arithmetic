/*
�ֻ��绰�������:
������ֻ��ĵ绰�������һ��������򣬾���Ҫ������:
1.��ϵ����Ϣ�����ܹ�ʵ����ϵ�˵���Ϣ��ӡ���ѯ����ϵ����Ϣ����:��
�����绰�������ʼ�����ͥסַ��QQ�ŵ�; ->����Ĳ���
2.�ܹ�ʵ����ϵ����Ϣ������ĸ˳�������ʾ;->���������
3.�ܹ�ʵ����ͬ������ϵ�˺ϲ�;->�����ɾ��
4.�ܹ������ļ�ʵ����ϵ����Ϣ���嵼�뵼������;
*/

#include<iostream>
#include<string>
#include<stdio.h>//�ļ���Ϣ���뵼����
#define LIN sizeof(contacts)
#define MAX 20

using namespace std;

typedef struct buffer
	{
		char name[20];
		char number[20];
		char e_mail[20];
		char home[20];
		char QQ[20];
	}*bu;

typedef struct Contacts
{
	string name;
	string number;
	string e_mail;
	string home;
	string QQ;
	Contacts* next;
}contacts, * link;

//��ϵ�˵���Ϣ���;,��ÿ����һ����ϵ�˾��ж��Ƿ�������
void creat(int Num, link L)
{
	int num = Num;
	link head = L->next;

	for (int i = 0; i < num; i++)//ǰ�巨����
	{
		cout << " �뿪ʼ�����" << i + 1 << "����ϵ����Ϣ��" << endl;
		link p = new contacts;
		string one, two, three, four, five;
		cin >> one >> two >> three >> four >> five;
		(p->name) = one;
		(p->number) = two;
		(p->e_mail) = three;
		(p->home) = four;
		(p->QQ) = five;
		int sign = 0;
		while (head != NULL)
		{
			if (p->name == head->name)
			{
				sign = 1;
				delete(p);
				break;
			}
			head = head->next;
		}//�ж��Ƿ�������
		head = L;
		if (sign)
		{
			continue;
		}
		//��ʼ����
		p->next = head->next;
		head->next = p;
	}

}

//����ĸ����(ѡ������)

void sort(link L)
{
   link p, q, max, prior;
    
    p = new contacts;  //����һ��p�ڵ�
	p->next = L->next;      //pȡ��L
    L->next = NULL;         //L�ǿ�����
    
    while(p->next)
    {
        prior = p;
        max = prior->next;//δ�������ĵ�һ�����
 
        for(q = max; q->next; q = q->next)
        {
            if(max->name < q->next->name)
            {
                max = q->next;
                prior = q;//�ҵ�ǰ���
            }
        }
        
        //��p�����е���һ�����Ľڵ㣬��ͷ�巨���뵽L�����У����뷽ʽ����˳��ߵ�������
        prior->next = max->next;  
        max->next = L->next;
        L->next = max;
    }
 
    delete(p);
}

//��ѯ��ϵ�˲����
void find(link L, string Name)
{
	string name = Name;
	link p = L->next;
	int sign = 1;
	cout << "�����ѯ����ϵ����Ϣ��" << endl;
	while (p)
	{
		if (p->name == name)
		{
			sign = 0;
			cout
				<< p->name << " "
				<< p->number << " "
				<< p->e_mail << " "
				<< p->home << " "
				<< p->QQ
				<< endl;
		}
		p = p->next;
	}
	if (sign)
	{
		cout << "δ��ѯ�����ˣ�" << endl;
	}

}

//�����ļ�����ϵ����Ϣ
void getin(link L)
{
	link head = L;
	FILE* fp;
	cout << "������Ҫ������ļ�����" << endl;
	char infile[30];
	cin >> infile;
	if ((fp = (fopen(infile, "rb"))) == NULL)
	{
		cout << "�޷��򿪸��ļ���" << endl;
		exit(0);
	}
	else
	{
		cout << "�ɹ���" << infile << "�ļ�" << endl;
		while (!feof(fp))
		{	
			bu p = new buffer;
			fscanf(fp, "%s %s %s %s %s", p->name, p->number, p->e_mail, p->home, p->QQ);
			/*cout << p->name << " "
				<< p->number << " "
				<< p->e_mail << " "
				<< p->home << " "
				<< p->QQ << endl;*/
			//�����Ƿ��룻
			link q = new contacts;
			q->name = p->name;
			q->number = p->number;
			q->e_mail = p->e_mail;
			q->home = p->home;
			q->QQ = p->QQ;
			delete(p);//�ͷ��ڴ�
			q->next = head->next;
			head->next = q;
		}
		fclose(fp);
	}
}

//������ϵ������
void putout(link L)
{
	link head = L->next;
	FILE* fp;
	cout << "�����뵼��Ŀ���ļ�����" << endl;
	char infile[30];
	cin >> infile;
	if ((fp = (fopen(infile, "wb"))) == NULL)
	{
		cout << "�޷��򿪸��ļ���" << endl;
		exit(0);
	}
	else
	{
		while (head != NULL)
		{
			fprintf(fp, "%s %s %s %s %s\n", head->name, head->number, head->e_mail, head->home, head->QQ);
			head = head->next;
		}
		cout << "�ѳɹ�������ϵ���б�:" << infile << endl;
		fclose(fp);
	}
	
}
//�����ϵ������
void print(link L)
{
	link p = L->next;
	while (p != NULL)
	{
		cout 
			 << p->name<<" "
			<< p->number<<" "
			<< p->e_mail<<" "
			<< p->home<<" " 
			<< p->QQ
			<< endl;
		p = p->next;
	}
}

//��ʾ�û�������Ϣ
void inform(void)
{
	cout << "         ********�绰��********        " << endl;
	cout << "----------------------" << endl;
	cout << "�𾴵��û����ã�" << endl;
	cout << "�����ϵ��������1." << endl;	
	cout << "��ѯ��ϵ��������2." << endl;
	cout << "��ϵ����Ϣ���嵼��������3." << endl;
	cout << "��ϵ����Ϣ���嵼��������4." << endl;
	cout << "----------------------" << endl;
	cout << endl << endl;
}

//����ʵ��
void current(link L)
{
	string run = "in";
	while (run != "out")
	{
		string test;
		cin >> test;
		while (test != "1" && test != "2" && test != "3" && test != "4")
		{
			cout << "----------------------" << endl;
			cout << "����������������������:" << endl;
			cout << "----------------------" << endl;
			cin >> test;
		}
		if (test == "1")
		{
			cout << "----------------------" << endl;
			cout << "�����ϵ��" << endl
				<< "->��������Ҫ��ӵ���ϵ�˸�����" << endl;
			cout << "----------------------" << endl;
			int num;
			cin >> num;
			creat(num, L);
			sort(L);
			cout << "----------------------" << endl;
			cout << "������������ϵ���б�" << endl;
			cout << "----------------------" << endl;
			print(L);
		}
		if (test == "2")
		{
			cout << endl;
			cout << "----------------------" << endl;
			cout << "��ѯ��ϵ��" << endl
				<< "->��������Ҫ��ѯ����ϵ��������" << endl;
			cout << "----------------------" << endl;
			string name;
			cin >> name;
			find(L, name);
		}
		if (test == "3")
		{	
			getin(L);
			cout << "----------------------" << endl;
			cout << "���������ϵ���б�" << endl;
			cout << "----------------------" << endl;
			sort(L);
			print(L);
		}

		if (test == "4")
		{	
			putout(L);
		}
		cout << "----------------------" << endl;
		cout << "��������������������:out" << endl
			<< "��������������������:in" << endl;
		cout << "----------------------" << endl;
		cin >> run;
		while (run != "out" && run != "in")
		{
			cout << "----------------------" << endl;
			cout << "���Ĳ����������������룺" << endl;
			cout << "----------------------" << endl;
			cin >> run;
		}
		if (run == "in")
		{
			cout << "----------------------" << endl;
			cout << "������������Ĳ�����ţ�" << endl;
			cout << "----------------------" << endl;
		}
		if (run == "out")
		{
			cout << "----------------------" << endl;
			cout << "лл����ʹ��" << endl;
			cout << "----------------------" << endl;
		}
	}
}
int main()
{
	link L = new contacts;
	L->next = NULL;

	inform();
	current(L);
}
