/*
手机电话簿的设计:
请参照手机的电话簿，设计一个仿真程序，具体要求如下:
1.联系人信息管理，能够实现联系人的信息添加、查询，联系人信息包括:姓
名、电话、电子邮件、家庭住址、QQ号等; ->链表的插入
2.能够实现联系人信息按照字母顺序分类显示;->链表的排序
3.能够实现相同姓名联系人合并;->链表的删除
4.能够利用文件实现联系人信息整体导入导出功能;
*/

#include<iostream>
#include<string>
#include<stdio.h>//文件信息导入导出；
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

//联系人的信息添加;,并每输入一个联系人就判断是否重名；
void creat(int Num, link L)
{
	int num = Num;
	link head = L->next;

	for (int i = 0; i < num; i++)//前插法插入
	{
		cout << " 请开始输入第" << i + 1 << "个联系人信息：" << endl;
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
		}//判断是否重名；
		head = L;
		if (sign)
		{
			continue;
		}
		//开始插入
		p->next = head->next;
		head->next = p;
	}

}

//按字母排序(选择排序)

void sort(link L)
{
   link p, q, max, prior;
    
    p = new contacts;  //生成一个p节点
	p->next = L->next;      //p取代L
    L->next = NULL;         //L是空链表
    
    while(p->next)
    {
        prior = p;
        max = prior->next;//未排序区的第一个结点
 
        for(q = max; q->next; q = q->next)
        {
            if(max->name < q->next->name)
            {
                max = q->next;
                prior = q;//找到前结点
            }
        }
        
        //从p链表中弹出一个最大的节点，用头插法插入到L链表中，插入方式导致顺序颠倒过来；
        prior->next = max->next;  
        max->next = L->next;
        L->next = max;
    }
 
    delete(p);
}

//查询联系人并输出
void find(link L, string Name)
{
	string name = Name;
	link p = L->next;
	int sign = 1;
	cout << "您想查询的联系人信息：" << endl;
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
		cout << "未查询到此人！" << endl;
	}

}

//导入文件中联系人信息
void getin(link L)
{
	link head = L;
	FILE* fp;
	cout << "请输入要导入的文件名：" << endl;
	char infile[30];
	cin >> infile;
	if ((fp = (fopen(infile, "rb"))) == NULL)
	{
		cout << "无法打开该文件！" << endl;
		exit(0);
	}
	else
	{
		cout << "成功打开" << infile << "文件" << endl;
		while (!feof(fp))
		{	
			bu p = new buffer;
			fscanf(fp, "%s %s %s %s %s", p->name, p->number, p->e_mail, p->home, p->QQ);
			/*cout << p->name << " "
				<< p->number << " "
				<< p->e_mail << " "
				<< p->home << " "
				<< p->QQ << endl;*/
			//调试是否导入；
			link q = new contacts;
			q->name = p->name;
			q->number = p->number;
			q->e_mail = p->e_mail;
			q->home = p->home;
			q->QQ = p->QQ;
			delete(p);//释放内存
			q->next = head->next;
			head->next = q;
		}
		fclose(fp);
	}
}

//导出联系人链表
void putout(link L)
{
	link head = L->next;
	FILE* fp;
	cout << "请输入导出目标文件名：" << endl;
	char infile[30];
	cin >> infile;
	if ((fp = (fopen(infile, "wb"))) == NULL)
	{
		cout << "无法打开该文件！" << endl;
		exit(0);
	}
	else
	{
		while (head != NULL)
		{
			fprintf(fp, "%s %s %s %s %s\n", head->name, head->number, head->e_mail, head->home, head->QQ);
			head = head->next;
		}
		cout << "已成功导出联系人列表到:" << infile << endl;
		fclose(fp);
	}
	
}
//输出联系人链表
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

//提示用户输入信息
void inform(void)
{
	cout << "         ********电话簿********        " << endl;
	cout << "----------------------" << endl;
	cout << "尊敬的用户您好：" << endl;
	cout << "添加联系人请输入1." << endl;	
	cout << "查询联系人请输入2." << endl;
	cout << "联系人信息整体导入请输入3." << endl;
	cout << "联系人信息整体导出请输入4." << endl;
	cout << "----------------------" << endl;
	cout << endl << endl;
}

//具体实现
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
			cout << "您的输入有误，请重新输入:" << endl;
			cout << "----------------------" << endl;
			cin >> test;
		}
		if (test == "1")
		{
			cout << "----------------------" << endl;
			cout << "添加联系人" << endl
				<< "->请输入需要添加的联系人个数：" << endl;
			cout << "----------------------" << endl;
			int num;
			cin >> num;
			creat(num, L);
			sort(L);
			cout << "----------------------" << endl;
			cout << "输出已输入的联系人列表：" << endl;
			cout << "----------------------" << endl;
			print(L);
		}
		if (test == "2")
		{
			cout << endl;
			cout << "----------------------" << endl;
			cout << "查询联系人" << endl
				<< "->请输入需要查询的联系人姓名：" << endl;
			cout << "----------------------" << endl;
			string name;
			cin >> name;
			find(L, name);
		}
		if (test == "3")
		{	
			getin(L);
			cout << "----------------------" << endl;
			cout << "输出导入联系人列表：" << endl;
			cout << "----------------------" << endl;
			sort(L);
			print(L);
		}

		if (test == "4")
		{	
			putout(L);
		}
		cout << "----------------------" << endl;
		cout << "如果你想结束操作请输入:out" << endl
			<< "如果你想继续操作请输入:in" << endl;
		cout << "----------------------" << endl;
		cin >> run;
		while (run != "out" && run != "in")
		{
			cout << "----------------------" << endl;
			cout << "您的操作有误，请重新输入：" << endl;
			cout << "----------------------" << endl;
			cin >> run;
		}
		if (run == "in")
		{
			cout << "----------------------" << endl;
			cout << "输入您想继续的操作序号：" << endl;
			cout << "----------------------" << endl;
		}
		if (run == "out")
		{
			cout << "----------------------" << endl;
			cout << "谢谢您的使用" << endl;
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
