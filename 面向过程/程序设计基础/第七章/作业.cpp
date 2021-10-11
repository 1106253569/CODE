#include <iostream>
#include <iomanip>
struct student
{
    int num;
    std::string name;
    int score[3];
};
void input(student &x)
{
    std::cin >>x.name >> x.score[0] >> x.score[1] >> x.score[2];
}
void print(student &x)
{
    std::cout << x.name<<"\n";
    for (int i = 0; i < 3;i++)
        std::cout <<x.score[i]<<"\n";
    std::cout << "\n";
}
void print(student *S,int M)
{
    std::cout << S[M-1].name<<" ";
    int sum = S[M-1].score[0] + S[M-1].score[1] + S[M-1].score[2];
    std::cout << sum << "\n";
}

student* Rearrange(student *a,int n)
{
    int SumNum(student &s);
    for (int i = 0; i < n;i++)
        for (int j = i; j < n;j++)
        {
            if(SumNum(a[i])<SumNum(a[j]))
            {
                student temp;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            else if(SumNum(a[i])==SumNum(a[j]))
            for (int k = 0; k <= 3;k++)
            {
                if(k==3)
                {
                    if(a[i].name>a[j].name)
                    {
                        student temp;
                        temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                    }
                    break;
                }
                if(a[i].score[k]<a[j].score[k])
                {
                    student temp;
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                    break;
                } 
            }
        }
    return a;
}
int SumNum(student &s)
{
    return (s.score[0] + s.score[1] + s.score[2]);
}

int main()
{
    void input(student & x);
    void print(student & x);
    void print(student *S, int M);
    student* Rearrange(student *a, int n);
    int N,M;
    std::cin >> N;
    student std[1024];
    student *People;
    for (int i = 0; i < N;i++)
    {
        input(std[i]);
    }
    People=Rearrange(std, N);
    std::cin >> M;
    print(People, M);
    return 0;
}



