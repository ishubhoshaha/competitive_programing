#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#define N 1000000
using namespace std;
vector <double > factorialLog;
void lof_of_factorial()
{
    int i;
    double temp;
    factorialLog.push_back(0);
    for(i=1;i<=N;i++)
    {
        temp=log(i)+factorialLog[i-1];
        factorialLog.push_back(temp);

    }
}
int main()
{
    int t=1,testCase,number,base;
    double digit;
    lof_of_factorial();
    scanf("%d",&testCase);
    while(testCase--)
    {
        scanf("%d %d",&number,&base);
        digit=factorialLog[number]/log(base);
        digit=floor(digit)+1;
        printf("Case %d: %.lf\n",t++,digit);
    }
    return 0;
}
