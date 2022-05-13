#include "fstream"
#include "windows.h"
#include <iostream>
#include <string>
using namespace std;
#define N 200
#include <iomanip>

//结构体
struct book
{
	string num;	   //书本编号
	string name;   //书名
	string writer; //作者
	string home;   //出版社
	float price;   //价格
	string type;   //类别
	int kucun;	   //库存
};

void mainMenu(book s[], int n);	  //声明主菜单
void chaxunMenu(book s[], int n); //声明信息查询主菜单
void weihuMenu(book s[], int n);  //信息维护主菜单
void amendMenu(book s[], int n);  //修改信息主菜单
void sortMenu(book s[], int n);	  //排序菜单

//从文件读取数据
/*
函数功能:从文件读取数据
函数参数:book s[]
函数返回值:实际人数
*/
int readData(book s[])
{
	cout << "正在读取文件."<<'\n';
	int i = 0;
	ifstream in("D:\\CODE\\C++\\POP\\practice\\library.txt"); //读取文件
	if(!in)
    {
        std::cerr << "无法打开输入文件"
                  << "\n";
        return -1;
    }
	in.close(); //读取完毕
	std::cout << "读取完毕" << '\n';
	return 1;
}

//保存数据
/*
函数功能:保存数据
函数参数:book s[]
函数返回值:无
*/
void saveData(book s[], int n)
{
	int i = 0;
	ofstream out("D:\\CODE\\C++\\POP\\practice\\library.txt"); //读取文件
	for (i = 0; i < n; i++)
		out << '\n'
			<< s[i].num << " " << s[i].name << " " << s[i].writer << " " << s[i].home << " " << s[i].price << " " << s[i].type << " " << s[i].kucun; //存储文件内容
	out.close();																																	 //读取完毕
}

//编号重复检测
/*
函数功能:检查有无重复编号
函数参数:book s[],int n
函数返回值:t
*/
int check_num(book s[], int n, string a)
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		if (a == s[i].num)
		{
			t = 1; //有重复值则t返回1
			break;
		}
	}
	return t;
}
//类别检测
/*
函数功能:检测是否符合要求
函数参数:book s[],int n
函数返回值:t
*/
int check_type(string a)
{
	int t = 0;
	if (a == "文学" || a == "教育" || a == "管理" || a == "生活" || a == "艺术")
		t = 1; //符合则t返回1
	return t;
}

//显示书籍信息
/*
函数参数:book s[],int n
函数参数:book s[],int n
函数返回值:无
*/
void display(book s[], int n)
{
	int i;
	cout << std::left << setw(20) << "编号" << std::left << setw(20) << "书名" << std::left << setw(20) << "作者" << std::left << setw(20) << "出版社" << std::left << setw(20) << "金额" << std::left << setw(20) << "类别" << std::left << setw(20) << "当前库存" << endl;
	for (i = 0; i < n; i++)
		cout << std::left << setw(20) << s[i].num << std::left << setw(20) << s[i].name << std::left << setw(20) << s[i].writer << std::left << setw(20) << s[i].home << std::left << setw(20) << s[i].price << std::left << setw(20) << s[i].type << std::left << setw(20) << s[i].kucun << endl; //输出结构体内容
	cout << "一共有" << (i + 1) << "本图书" << endl;
}

//添加书籍信息
/*
函数功能:添加书籍信息
函数参数:book s[] int&n
函数返回值:无
*/
void addMenu(book s[], int &n)
{
	int i;
	char a;
	system("cls"); //清屏
	cout << "\t================添加图书信息================\n";
	cout << "1.添加书籍"
		 << "\t"
		 << "2.返回上一级\n"
		 << "请输入指令";
	cin >> i;
	if (i == 1)
	{
		cout << "请输入要添加的数据(只能为文学,教育,管理,生活,艺术)" << endl;
		cout << "编号\t书名\t作者\t出版社\t金额\t类别\t当前库存\n";
		cin >> s[n].num >> s[n].name >> s[n].writer >> s[n].home >> s[n].price >> s[n].type >> s[n].kucun;
		for (i = 0; i < n; i++)
		{
			if (s[n].num == s[i].num) //检测编号是否重复
			{
				cout << "\n当前系统已存在所输入的书籍编号,添加失败\n"
					 << "正在跳转...\n";
				Sleep(2000);
				addMenu(s, n);
			}
		}
		if (check_type(s[n].type) == 0) //检测类别是否符合
		{
			cout << "该类别不存在,添加失败\n"
				 << "正在跳转...";
			Sleep(2000);
			addMenu(s, n);
		}
		else
		{
			cout << "添加成功,是否继续添加(Y),否则返回上一级(N)";
			n++;
			Sleep(2000);
			cin >> a;
			while (1)
			{
				if (a == 'Y')
					addMenu(s, n);
				else if (a == 'N')
					weihuMenu(s, n);
				else
				{
					cout << "输入错误,请重新输入";
					cin >> a;
				}
			}
		}
	}
	else
	{
		if (i == 2)
			weihuMenu(s, n);
		else
		{
			cout << "输入错误,正在跳转..";
			Sleep(2000);
			addMenu(s, n);
		}
	}
}

//删除书籍信息
/*
函数功能:删除书籍信息
函数参数:book s[],int&n
函数返回值:无
*/
void deleteMenu(book s[], int &n)
{
	system("cls"); //
	cout << "\t================删除书籍================\n";
	int i, k;
	string dnum;   //定义要删除的书籍
	display(s, n); //输出结构体内容
	cout << "\n1.删除书籍"
		 << "\t"
		 << "2.返回上一级\n"
		 << "请输入指令";
	cin >> i;
	if (i == 1)
	{
		cout << "请输入要删除书籍编号:";
		cin >> dnum;			//输入要删除的书籍编号
		for (i = 0; i < n; i++) //循环查找标号所在位置
		{
			if (dnum == s[i].num)
				break;
		}
		if (i == n) //判断出没有所对应的编号位置
		{
			cout << "\n当前系统不存在所输入的书籍编号,删除失败\n"
				 << "正在跳转.\n";
			Sleep(2000);
			deleteMenu(s, n);
		}
		else
		{
			for (k = i; k < n; k++) //将后一位对应编号内容放置前一位内
				s[k] = s[k + 1];
			n--;
			cout << "删除成功,正在跳转..\n";
			Sleep(1000);
			deleteMenu(s, n);
		}
	}
	else
	{
		if (i == 2)
			weihuMenu(s, n);
		else
		{
			cout << "输入错误,正在跳转...";
			Sleep(2000);
			deleteMenu(s, n);
		}
	}
}

//修改书籍类别
void amend_type(book s[], int n, string a)
{
	if (check_type(a) != 1) //检测类别是否符合
	{
		cout << "该类别不存在,修改失败\n"
			 << "正在跳转...";
		Sleep(3000);
		amendMenu(s, n);
	}
}

//修改书籍信息
/*
函数功能:修改书籍信息
函数参数:book s[],int n
函数返回值:无
*/
void amendMenu(book s[], int n)
{
	system("cls");
	cout << "\t================修改图书馆信息================\n";
	display(s, n);
	string anum, am; //定义要修改的书籍编号名称
	float ame;
	int amen;
	char a;
	int i, k;
	cout << "\n1.修改书籍"
		 << "\t"
		 << "2.返回上一级\n"
		 << "请输入指令";
	cin >> i;
	if (i == 1)
	{
		cout << "请输入需要修改的书籍编号\n";
		cin >> anum;
		for (i = 0; i < n; i++)
		{
			if (anum == s[i].num)
				break;
		}
		if (i == n)
		{
			cout << "当前系统不存在所输入的书籍编号,修改失败\n"
				 << "正在返回上一级" << endl;
			Sleep(2000);
			weihuMenu(s, n);
		}
		else
		{
			while (1)
			{
				system("cls");
				cout << "当前书籍信息为\n"
					 << std::left << setw(20) << "编号" << std::left << setw(20) << "书名" << std::left << setw(20) << "作者" << std::left << setw(20) << "出版社" << std::left << setw(20) << "金额" << std::left << setw(20) << "类别" << std::left << setw(20) << "当前库存量" << endl;
				cout << std::left << setw(20) << s[i].num << std::left << setw(20) << s[i].name << std::left << setw(20) << s[i].writer << std::left << setw(20) << s[i].home << std::left << setw(20) << s[i].price << std::left << setw(20) << s[i].type << std::left << setw(20) << s[i].kucun << endl; //输出结构体内容
				cout << "====================================================" << endl;
				cout << "1.书名\n"
					 << "2.作者\n"
					 << "3.出版社\n"
					 << "4.金额\n"
					 << "5.出版社\n"
					 << "6.当前库存量\n";
				cout << "7.返回上一级" << endl;
				cout << "请选择要修改的书籍数据序号";
				cin >> k;
				while (k < 1 || k > 8)
				{
					cout << "输入错误,请重新输入" << endl;
					cin >> k;
				}
				cout << "输入修改后的数据(类别只能为文学,教育,管理,生活,艺术)" << endl;
				switch (k)
				{
				case 1:
					cin >> am;
					s[i].name = am;
					break;
				case 2:
					cin >> am;
					s[i].writer = am;
					break;
				case 3:
					cin >> am;
					s[i].home = am;
					break;
				case 4:
					cin >> ame;
					s[i].price = ame;
					break;
				case 5:
					cin >> am;
					amend_type(s, n, am);
					s[i].type = am;
					break;
				case 6:
					cin >> amen;
					s[i].kucun = amen;
					break;
				case 7:
					cout << "正在返回" << endl;
					Sleep(3000);
					amendMenu(s, n);
				}

				cout << "修改成功";
				cout << "继续修改(Y),否则返回(N)";
				while (2)
				{
					cin >> a;
					if (a == 'Y')
						break;
					else if (a == 'N')
						weihuMenu(s, n);
					else
						cout << "输入错误,请重新输入";
				}
			}
		}
	}
	else if (i == 2)
		weihuMenu(s, n);
	else
	{
		cout << "输入错误,正在跳转.";
		Sleep(2000);
		amendMenu(s, n);
	}
}

//信息维护菜单
/*
函数功能:显示信息维护菜单
函数参数:book s[],int n
函数返回值:无
*/
void weihuMenu(book s[], int n)
{
	int select;
	while (1)
	{
		system("cls"); //清屏
		cout << endl
			 << "=================信息维护菜单=================\n";
		cout << "\t\t1.添加书籍\n";
		cout << "\t\t2.删除书籍\n";
		cout << "\t\t3.修改书籍\n";
		cout << "\t\t4.返回上一级\n";
		cout << "==============================================\n";
		cout << "请输入指令(1-4)";
		while (1)
		{
			cin >> select;
			if (select < 1 || select > 5)
				cout << "请重新输入序号(1-5)";
			else
				break;
		}
		switch (select)
		{
		case 1:
			addMenu(s, n);
			break;
		case 2:
			deleteMenu(s, n);
			break;
		case 3:
			amendMenu(s, n);
			break;
		case 4:
			mainMenu(s, n);
			break;
		}
	}
}
//编号升序排序
/*
函数功能:显示编号升序排序
函数参数:book s[],int n
函数返回值:无
*/
void numsort(book s[], int n)
{
	book t;
	int i, k;
	for (i = 0; i < n - 1; i++)
	{
		for (k = 0; k < n - i - 1; k++)
		{
			if (s[k].num > s[k + 1].num)
			{
				t = s[k];
				s[k] = s[k + 1];
				s[k + 1] = t;
			}
		}
	}
}
//金额降序
/*
函数功能:显示金额降序排序
函数参数:book s[] int n
函数返回值:无
*/
void Psort1(book s[], int n)
{
	system("cls");
	cout << endl
		 << "\t================金额降序================\n"
		 << endl;
	book t; //定义结构体对象，实现交换。
	int i, k;
	for (i = 0; i < n - 1; i++)
	{
		for (k = 0; k < n - i - 1; k++)
		{
			if (s[k].price < s[k + 1].price)
			{
				t = s[k];
				s[k] = s[k + 1];
				s[k + 1] = t;
			}
		}
	}
	display(s, n);
	cout << endl
		 << "5秒后返回";
	Sleep(5000);
	numsort(s, n);
	sortMenu(s, n);
}
//金额升序
/*
函数功能:显示金额升序排序
函数参数:book s[],int n
函数返回值:无
*/
void Psort(book s[], int n)
{
	system("cls");
	cout << endl
		 << "\t================金额升序排序================\n"
		 << endl;
	book t;
	int i, k;
	for (i = 0; i < n - 1; i++)
	{
		for (k = 0; k < n - i - 1; k++)
		{
			if (s[k].price > s[k + 1].price)
			{
				t = s[k];
				s[k] = s[k + 1];
				s[k + 1] = t;
			}
		}
	}
	display(s, n);
	cout << endl
		 << "5秒后返回";
	Sleep(5000);
	numsort(s, n);
	sortMenu(s, n);
}

//库存升序排序
/*
函数功能:显示库存升序
函数参数:book s[],int n
函数返回值:无
*/
void Ksort(book s[], int n)
{
	system("cls");
	cout << endl
		 << "\t================库存升序排序================\n"
		 << endl;
	book t;
	int i, k;
	for (i = 0; i < n - 1; i++)
	{
		for (k = 0; k < n - i - 1; k++)
		{
			if (s[k].kucun > s[k + 1].kucun)
			{
				t = s[k];
				s[k] = s[k + 1];
				s[k + 1] = t;
			}
		}
	}
	display(s, n);
	cout << endl
		 << "5秒后返回";
	Sleep(5000);
	numsort(s, n);
	sortMenu(s, n);
}

//库存降序排序
/*
函数功能:显示库存降序排序
函数参数:book s[],int n
函数返回值:无
*/
void Ksort1(book s[], int n)
{
	system("cls");
	cout << endl
		 << "\t================库存降序排序================\n"
		 << endl;
	book t;
	int i, k;
	for (i = 0; i < n - 1; i++)
	{
		for (k = 0; k < n - i - 1; k++)
		{
			if (s[k].kucun < s[k + 1].kucun)
			{
				t = s[k];
				s[k] = s[k + 1];
				s[k + 1] = t;
			}
		}
	}
	display(s, n);
	cout << endl
		 << "5秒后返回";
	Sleep(5000);
	numsort(s, n);
	sortMenu(s, n);
}
void hsort(book s[], int n)
{
	system("cls");
	cout << endl
		 << "\t================出版社排序(A-Z)================\n"
		 << endl;
	book t;
	int i, k;
	for (i = 0; i < n - 1; i++)
	{
		for (k = 0; k < n - i - 1; k++)
		{
			if (s[k].home > s[k + 1].home)
			{
				t = s[k];
				s[k] = s[k + 1];
				s[k + 1] = t;
			}
		}
	}
	display(s, n);
	cout << endl
		 << "5秒后返回";
	Sleep(5000);
	numsort(s, n);
	sortMenu(s, n);
}
void wsort(book s[], int n)
{
	system("cls");
	cout << endl
		 << "\t================书籍作者排序(A-Z)================\n"
		 << endl;
	book t;
	int i, k;
	for (i = 0; i < n - 1; i++)
	{
		for (k = 0; k < n - i - 1; k++)
		{
			if (s[k].writer > s[k + 1].writer)
			{
				t = s[k];
				s[k] = s[k + 1];
				s[k + 1] = t;
			}
		}
	}
	display(s, n);
	cout << endl
		 << "5秒后返回";
	Sleep(5000);
	numsort(s, n);
	sortMenu(s, n);
}
//排列主菜单
/*
函数功能:显示排序菜单
函数参数:book s[],int n
函数返回值:无
*/
void sortMenu(book s[], int n)
{
	int select;
	system("cls");
	cout << endl
		 << "==================排列菜单==================\n";
	cout << "\t\t1.金额升序\n";
	cout << "\t\t2.金额降序\n";
	cout << "\t\t3.当前库存量升序\n";
	cout << "\t\t4.当前库存量降序\n";
	cout << "\t\t5.出版社排序\n";
	cout << "\t\t6.作者排序\n";
	cout << "\t\t7.返回上一级\n";
	cout << "==============================================\n";
	cout << "请重新输入序号(1-7)";
	while (1)
	{
		cin >> select;
		if (select < 1 || select > 7)
			cout << "请重新输入序号(1-7)";
		else
			break;
	}
	switch (select)
	{
	case 1:
		Psort(s, n);
		break;
	case 2:
		Psort1(s, n);
		break;
	case 3:
		Ksort(s, n);
		break;
	case 4:
		Ksort1(s, n);
		break;
	case 5:
		hsort(s, n);
		break;
	case 6:
		wsort(s, n);
		break;
	case 7:
		mainMenu(s, n);
		break;
	}
}

//编号信息查询菜单
/*
函数功能:显示编号信息查询菜单
函数参数:book s[],int n
函数返回值:无
*/
void cxnum(book s[], int n)
{
	string cx; //定义要查询的书名编号
	int i;
	while (1)
	{
		system("cls");
		cout << endl
			 << "\t================书籍编号查询页面================\n"
			 << endl;
		cout << "请输入要查询的书籍编号";
		cin >> cx;
		for (i = 0; i < n; i++)
		{
			if (cx == s[i].num)
				break; //判断是否有对应编号
		}
		if (i == n)
		{
			cout << "当前系统不存在所输入的书籍信息,无法查询\n"
				 << "正在返回..";
			Sleep(2000);
			chaxunMenu(s, n);
		}
		else
		{
			cout << std::left << setw(20) << "编号" << std::left << setw(20) << "书名" << std::left << setw(20) << "作者" << std::left << setw(20) << "出版社" << std::left << setw(20) << "金额" << std::left << setw(20) << "类别" << std::left << setw(20) << "当前库存量" << endl;
			cout << std::left << setw(20) << s[i].num << std::left << setw(20) << s[i].name << std::left << setw(20) << s[i].writer << std::left << setw(20) << s[i].home << std::left << setw(20) << s[i].price << std::left << setw(20) << s[i].type << std::left << setw(20) << s[i].kucun << endl; //输出结构体内容
			cout << endl
				 << "三秒后返回";
			Sleep(3000);
			chaxunMenu(s, n);
		}
	}
}

//书名信息查询菜单
/*
函数功能:显示书名信息查询菜单
函数参数:book s[],int n
函数返回值:无
*/
void cxname(book s[], int n)
{
	string cx;		  //定义要查询的书名
	int j = 0, k = 0; // j判断行数，k表示满足的书籍数量
	while (1)
	{
		system("cls");
		cout << endl
			 << "\t================书籍书名查询页面================\n"
			 << endl;
		cout << "请输入要查询的书籍名字";
		cin >> cx;
		cout << std::left << setw(20) << "编号" << std::left << setw(20) << "书名" << std::left << setw(20) << "作者" << std::left << setw(20) << "出版社" << std::left << setw(20) << "金额" << std::left << setw(20) << "类别" << std::left << setw(20) << "当前库存量" << endl;
		for (int i = 0; i < n; i++)
		{
			if (cx == s[i].name) //判断是否有对应书籍名称
			{
				cout << std::left << setw(20) << s[i].num << std::left << setw(20) << s[i].name << std::left << setw(20) << s[i].writer << std::left << setw(20) << s[i].home << std::left << setw(20) << s[i].price << std::left << setw(20) << s[i].type << std::left << setw(20) << s[i].kucun << endl; //输出结构体内容
				j++;
				k++;
			}
			if (j > 9) //满足一页十行
			{
				system("pause"); //系统暂停
				j -= 10;
				system("cls"); //清屏
			}
		}
		if (k == 0)
		{
			cout << "未找到相应信息,无法查询\n"
				 << "正在返回..";
			Sleep(2000);
			break;
		}
		else
		{
			printf("共有%d本书", k);
			cout << endl
				 << "三秒后返回..";
			Sleep(3000);
			break;
		}
	}
	chaxunMenu(s, n);
}

//作者信息查询菜单
/*
函数功能:显示作者查询菜单
函数参数:book s[],int n
函数返回值:无
*/
void cxwriter(book s[], int n)
{
	string cx;		  //定义要查询的书籍作者
	int j = 0, k = 0; // j判断行数，k表示满足的书籍数量
	while (1)
	{
		system("cls");
		cout << endl
			 << "\t================书籍作者查询页面================\n"
			 << endl;
		cout << "请输入要查询的书籍作者";
		cin >> cx;
		cout << std::left << setw(20) << "编号" << std::left << setw(20) << "书名" << std::left << setw(20) << "作者" << std::left << setw(20) << "出版社" << std::left << setw(20) << "金额" << std::left << setw(20) << "类别" << std::left << setw(20) << "当前库存量" << endl;
		for (int i = 0; i < n; i++)
		{
			if (cx == s[i].writer)
			{
				cout << std::left << setw(20) << s[i].num << std::left << setw(20) << s[i].name << std::left << setw(20) << s[i].writer << std::left << setw(20) << s[i].home << std::left << setw(20) << s[i].price << std::left << setw(20) << s[i].type << std::left << setw(20) << s[i].kucun << endl; //输出结构体内容
				j++;
				k++;
			}
			if (j > 9) //满足一页十行
			{
				system("pause");
				j -= 10;
				system("cls");
			}
		}
		if (k == 0)
		{
			cout << "未找到相应信息,无法查询\n"
				 << "正在返回.." << endl;
			Sleep(2000);
			break;
		}
		else
		{
			printf("共有%d本书", k);
			cout << endl
				 << "三秒后返回";
			Sleep(3000);
			break;
		}
	}
	chaxunMenu(s, n);
}

//出版社信息查询菜单
/*
函数功能:显示出版社信息查询菜单
函数参数:book s[],int n
函数返回值:无
*/
void cxhome(book s[], int n)
{
	string cx;
	int j = 0, k = 0; // j判断行数，k表示满足的书籍数量
	while (1)
	{
		system("cls");
		cout << endl
			 << "\t================书籍出版社查询页面================\n"
			 << endl;
		cout << "请输入要查询的出版社";
		cin >> cx;
		cout << std::left << setw(20) << "编号" << std::left << setw(20) << "书名" << std::left << setw(20) << "作者" << std::left << setw(20) << "出版社" << std::left << setw(20) << "金额" << std::left << setw(20) << "类别" << std::left << setw(20) << "当前库存量" << endl;
		for (int i = 0; i < n; i++)
		{
			if (cx == s[i].home)
			{
				cout << std::left << setw(20) << s[i].num << std::left << setw(20) << s[i].name << std::left << setw(20) << s[i].writer << std::left << setw(20) << s[i].home << std::left << setw(20) << s[i].price << std::left << setw(20) << s[i].type << std::left << setw(20) << s[i].kucun << endl; //输出结构体内容
				j++;
				k++;
			}
			if (j > 9) //实现一页十行
			{
				system("pause");
				j -= 10;
				system("cls");
			}
		}
		if (k == 0)
		{
			cout << "未找到相应信息,无法查询\n"
				 << "正在返回..." << endl;
			Sleep(2000);
			break;
		}
		else
		{
			printf("共有%d本书", k);
			cout << endl
				 << "三秒后返回.";
			Sleep(3000);
			break;
		}
	}
	chaxunMenu(s, n);
}

//类别信息查询菜单
/*
函数功能:类别信息查询菜单
函数参数:book s[],int n
函数返回值:无
*/
void cxtype(book s[], int n)
{
	string cx;
	int j = 0, k = 0;
	while (1)
	{
		system("cls");
		cout << endl
			 << "\t================书籍类别查询菜单================\n"
			 << endl;
		cout << "请输入要查询的类别(文学,教育,管理,生活,艺术)";
		cin >> cx;
		cout << std::left << setw(20) << "编号" << std::left << setw(20) << "书名" << std::left << setw(20) << "作者" << std::left << setw(20) << "出版社" << std::left << setw(20) << "金额" << std::left << setw(20) << "类别" << std::left << setw(20) << "当前库存量" << endl;
		for (int i = 0; i < n; i++)
		{
			if (cx == s[i].type)
			{
				cout << std::left << setw(20) << s[i].num << std::left << setw(20) << s[i].name << std::left << setw(20) << s[i].writer << std::left << setw(20) << s[i].home << std::left << setw(20) << s[i].price << std::left << setw(20) << s[i].type << std::left << setw(20) << s[i].kucun << endl; //输出结构体内容
				j++;
				k++;
			}
			if (j > 9)
			{
				system("pause");
				j -= 10;
				system("cls");
			}
		}
		if (k == 0)
		{
			cout << "未找到相应信息,无法查询\n"
				 << "正在返回.." << endl;
			Sleep(2000);
			break;
		}
		else
		{
			printf("共有%d本书", k);
			cout << endl
				 << "三秒后返回..";
			Sleep(3000);
			break;
		}
	}
	chaxunMenu(s, n);
}

//信息查询列表主菜单
/*
函数功能:显示信息查询主菜单
函数参数:book s[],int n
函数返回值:无
*/
void chaxunMenu(book s[], int n)
{
	system("cls");
	int k;
	cout << endl
		 << "================信息查询菜单================\n";
	cout << "1.编号\n"
		 << "2.书名\n"
		 << "3.作者\n"
		 << "4.出版社\n"
		 << "5.类别(文学,教育,管理,生活,艺术)\n";
	cout << "6.返回上一级" << endl;
	cout << "====================================================" << endl;
	cout << "请根据以上信息提示输入要查询书籍数据序号(1-6)";
	cin >> k;
	while (k < 1 || k > 6)
	{
		cout << "输入错误,请重新输入" << endl;
		cin >> k;
	}
	switch (k)
	{
	case 1:
		cxnum(s, n);
		break;
	case 2:
		cxname(s, n);
		break;
	case 3:
		cxwriter(s, n);
		break;
	case 4:
		cxhome(s, n);
		break;
	case 5:
		cxtype(s, n);
		break;
	case 6:
		cout << "正在返回..." << endl;
		Sleep(2000);
		mainMenu(s, n);
	}
}

//主菜单
/*
函数功能:显示主菜单
函数参数:book s[],int n
函数返回值:无
*/
void mainMenu(book s[], int n)
{
	if(n==-1)
	{
		cout<<"无法进行"<<endl;
		return ;
	}
	int select;
	system("cls");
	cout << "\t欢迎使用图书管理系统\n"
		 << endl
		 << "================图书管理系统================\n";
	cout << "\t\t1.信息维护\n";
	cout << "\t\t2.所有信息查询\n";
	cout << "\t\t3.显示全部书籍\n";
	cout << "\t\t4.排序\n";
	cout << "\t\t5.退出\n";
	cout << "==============================================\n";
	cout << "请输入序号(1-5):";
	while (1)
	{
		cin >> select;
		if (select < 1 || select > 5)
			cout << "请重新输入序号(1-5)";
		else
			break;
	}
	switch (select)
	{
	case 1:
		weihuMenu(s, n);
		break;
	case 2:
		chaxunMenu(s, n);
		break;
	case 3:
		numsort(s, n);
		system("cls");
		display(s, n);
		cout << endl
			 << "五秒后返回..";
		Sleep(5000);
		mainMenu(s, n);
		break;
	case 4:
		sortMenu(s, n);
		break;
	case 5:
		saveData(s, n);
		cout << "正在保存并退出";
		Sleep(3000);
		exit(0);
		break;
	}
}

//测试函数
int main()
{
	book s[N];
	int num;
	num = readData(s);
	mainMenu(s, num);
	std::cout << "over!";
	return 0;
}
