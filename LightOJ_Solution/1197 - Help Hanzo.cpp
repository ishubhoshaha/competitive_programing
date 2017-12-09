#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#define MAX32 21474833648
#define SQ 50000
using namespace std;
bool isPrime[SQ];
bool segment[100010];
vector<int>v;
void sieve()
{
    memset(isPrime,true,sizeof isPrime);
    for(int i=4;i<SQ;i+=2)
        isPrime[i]=false;
    for(int i=3;i*i<SQ;i+=2)
        if(isPrime[i]==true)
            for(int j=i*i;j<SQ;j+=i)
                isPrime[j]=false;
    v.push_back(2);
    for(int i=3;i<SQ;i+=2)
        if(isPrime[i]==true)
            v.push_back(i);
}
int segmented_sieve(unsigned start,unsigned end)
{
    int counter=0;
    int i=0;
    memset(segment,true,sizeof segment);
    if(start == 1)
        segment[0]=false;
    for(i=0;v[i]*v[i]<=end;i++)
    {
        unsigned s=v[i]*(int )((start+v[i]-1)/(v[i]));
        if(s==v[i])
            s+=v[i];
        for(int k=s;k<=end;k+=v[i])
        {
            segment[k-start]=false;
        }
    }
    for(int l=0;l<=end-start;l++)
        if(segment[l]==true)
            ++counter;
    return counter;
}
int main()
{
    sieve();
    int test,caseno;
    //freopen("r.txt","r",stdin);
    scanf("%d",&test);
    for(caseno=1;caseno<=test;caseno++)
    {
        unsigned start,end;
        scanf("%u %u",&start,&end);
        if(start==1 && end == 1)
            printf("Case %d: 0\n",caseno);
        else
            printf("Case %d: %d\n",caseno,segmented_sieve(start,end));
    }
    return 0;
}