#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define MAX 10000001
using namespace std;
bool isPrime[MAX];
vector<int>prime;
void sieve()
{
    int i,j;
    memset(isPrime,true,sizeof isPrime);
    for(i=4;i<MAX;i+=2)
        isPrime[i]=false;
    for(i=3;i*i<MAX;i+=2)
        if(isPrime[i]==true)
            for(j=i*i;j<MAX;j+=i)
                isPrime[j]=false;
    isPrime[0]=false;
    isPrime[1]=false;
    for(i=0;i<MAX;i++)
        if(isPrime[i]==true)
            prime.push_back(i);
}
int goldbach(int i)
{
    int count=0;
        for(int j=0;j<prime.size()&&prime[j]<=i/2;j++)
        {
            if(isPrime[i-prime[j]]==true)
                count++;
        }
        return count;
}
int main()
{
    sieve();
    int caseno,cases;
  //freopen("i.txt","r",stdin);
    scanf("%d",&cases);
    for(caseno=1;caseno<=cases;caseno++)
    {
        int number;
        scanf("%d",&number);
        printf("Case %d: %d\n",caseno,goldbach(number));
    }
    return 0;
}
