#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct student
{
    int num;
    string name;
    int score[4];
} ;
int main()
{
    void input(student &x);
    void print(student x);
    double average(student a[], int n,int i);
    string max(student a[], int n,int i);
    student std[100];
    int n;
    cout << "please enter number:";
    cin >> n;
    for (int i=1; i <= n;i++)
        input(std[i]);
    for (int i=1; i <= n;i++)
            print(std[i]);        
    for (int i=1; i <= 3;i++) //平均值
        {
            double ave[4];
            ave[i] = average(std, n, i);
            cout << "第" << i << "门科目平均分为 : "
                 << setiosflags(ios::fixed) << setprecision(2) << ave[i] << endl;
        }   
    for (int i=1; i <= 3;i++) //最高分
        {
            string name[4];
            name[i] = max(std, n,i);
            cout << "第" << i << "门科目最高分是 : " << name[i]<<endl;
        }
        return 0;
}

void input(student &x)
{
    cin >> x.num >> x.name >> x.score[1] >> x.score[2] >> x.score[3];
}
    
void print(student x)
{
    cout << setiosflags(ios::left) << setw(3) << x.num;
    cout << setiosflags(ios::left) << setw(8) << x.name;
    cout << setiosflags(ios::left) << setw(4) << x.score[1];
    cout << setiosflags(ios::left) << setw(4) << x.score[2];
    cout << setiosflags(ios::left) << setw(4) << x.score[3];
    cout << endl;
}

double average(student a[], int n,int i)
{
    double sum[4];
    for (int j = 1; j <= n;j++)
         sum[i] += a[j].score[i];
    double ave;
    ave = sum[i] / n;
    return (ave);
}

string max(student a[], int n,int i)
{
    student stu = a[1];
    for (int j = 1; j <= n;j++)
    if(stu.score[i]<a[j].score[i])
        stu = a[j];
    return (stu.name);
}
