#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct student
{
    int num;
    string name;
    student *next;
};
int main()
{
    void input(int &n);
    student *creat();
    void *print(student * head);
    student *del(student * head, int n);
    student *insert(student * head);
    student *information;
    information=creat();
    cout << endl
         << "学生信息：" << endl;
    print(information);    
    information=del(information,5);
    print(information);
    information=insert(information);
    return 0;
}

student *creat()
{
    student *head;
    student *p1, *p2;
    int n = 0;
    p1 = p2 = new student;
    cout << "输入学号和姓名:"<<endl;
    cin >> p1->num >> p1->name;
    head = NULL;
    while(p1->num!=0)
    {
        n = n + 1;
        if(n==1)
            head = p1;
            else
                p2->next = p1;
            p2 = p1;
            p1 = new student;
            cin >> p1->num >> p1->name;
    }
    p2->next = NULL;
    return (head);
}

void *print(student * head)
{
    student *p;
    p = head;
    while(p->next!=0)
    {
        cout << setiosflags(ios::left) << setw(4) << p->num;
        cout << setiosflags(ios::left) << setw(8) << p->name << endl;
        p = p->next;
    }
}

student *del(student *head,int n)
{
    student *p1, *p2;
    if(head==NULL)
    {
        cout << "list null" << endl;
        return (head);
    }
    p1 = head;
    while(n!=p1->num&&p1->next!=0)
    {
        p2 = p1;
        p1 = p1->next;        
    }
    if(n==p1->num)
    {
        if(p1==head)
            head = p1->next;
        else
            p2->next = p1->next;
    }
    else
        cout << "cannot find";
    return (head);
}

void input(int &n)
{
    cin >> n;
}

student *insert(student*head)
{
    student *p;
    cout << "enter new information:";
    cin >> p->num >> p->name;
    int a = p->num;
    if(head==NULL)
    {
        cout << "list null" << endl;
        head->next = p;
        p->next = 0;
        return (head);
    }
    student *p1,*p2;
    p1 = head;
    while(a!=p1->num&&p1->next!=0)
    {
        p2 = p1;
        p1 = p1->next;
    }
    if(a==p1->num)
    {
        if(p1==head)
            head->next = p;
        else
        {
             p2->next = p;
             p->next = p1;
        }
        return (head);       

    }
}