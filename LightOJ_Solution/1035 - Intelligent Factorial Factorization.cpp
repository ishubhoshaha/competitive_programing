#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

#define N 101
int isPrime[N];
int factor[N];
int main()
{
    vector <int> v;
    int sqrtN=sqrt(N);
    int i,j;
    for(i=4;i<=N;i+=2)
        isPrime[i]=1;
    isPrime[0]=1;
    isPrime[1]=1;
    for(i=3;i<=sqrtN;i+=2)
        if(isPrime[i]==0)
            for(j=i*i;j<=N;j+=i)
                isPrime[j]=1;
    for(i=0;i<=N;i++)
        if(isPrime[i]==0)
            v.push_back(i);
    int t,testCase,number,num,sum;
    cin>>testCase;
    for(t=1;t<=testCase;t++)
    {
        sum=0;
        cin>>number;
        memset(factor,0,N);
        for(i=0;v[i]<=number;i++)
        {
            sum=0;
            num=number;
            if(v[i]<=number/2)
            {
                while(num>=1)
                {
                    sum+=num/v[i];
                    num/=v[i];
                }
                factor[v[i]]=sum;
            }
            else
                factor[v[i]]=1;
        }

        printf("Case %d: %d = ",t,number);
        for(j=0;j<=v[i-1];j++)
        {
            if(factor[j]!=0)
            {if(j!=v[i-1])
                printf("%d (%d) * ",j,factor[j]);
            else
                printf("%d (%d)",j,factor[j]);}

        }
        cout<<endl;
    }
}
