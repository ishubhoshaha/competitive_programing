#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#define Million 1000100
#define ull unsigned long long
using namespace std;
bool isPrime[Million];
vector <int> primeList;
void sieve()
{
    memset(isPrime,true,Million);
    for(int i=4;i<Million;i+=2)
        isPrime[i]=false;
    for(int i=3;i*i<Million;i+=2)
        if(isPrime[i]==true)
            for(int j=i*i;j<Million;j+=i)
                isPrime[j]=false;
    for(int i=2;i<Million;i++)
        if(isPrime[i]==true)
            primeList.push_back(i);
}
int GCD (int a,int b)
{
    while(b>0)
    {
        a=a%b;
        a=a^b;
        b=a^b;
        a=a^b;
    }
    return a;
}
ull primeFactorization(ull lcm,ull lcm_ab)
{
    ull l=lcm,l_ab=lcm_ab,counter_l=0,counter_ab=0,c=1;
    for(int i=0;primeList[i]*primeList[i]<=lcm || primeList[i]*primeList[i]<=lcm_ab ; i++)
    {
        counter_ab=counter_l=0;
        if(l%primeList[i]==0)
        {
            while(l%primeList[i]==0)
            {
                l/=primeList[i];
                ++counter_l;
                //cout<<counter_l<<endl;
            }
        }
        if(l_ab%primeList[i]==0)
        {
            while(l_ab%primeList[i]==0)
            {
                l_ab/=primeList[i];
                ++counter_ab;
                //cout<<counter_ab<<endl;
            }
        }
        //cout<<counter_ab<< " "<< counter_l<<endl;
        if(counter_ab!=counter_l)
            c*=pow(primeList[i],max(counter_ab,counter_l));
    }
    return c;
}
int main()
{
    int t=1,testCase;
    ull a,b,lcm,lcm_ab;
    sieve();
    //freopen("i.txt","r",stdin);
    scanf("%d",&testCase);

    while(testCase--)
    {
        scanf("%llu %llu %llu",&a,&b,&lcm);
        lcm_ab=a*b/GCD(a,b);
        //printf("%llu",a*b);
        if(lcm%lcm_ab==0)
            printf("Case %d: %llu\n",t++,primeFactorization(lcm,lcm_ab));
        else
            printf("Case %d: impossible\n",t++);
    }
    return 0;
}
