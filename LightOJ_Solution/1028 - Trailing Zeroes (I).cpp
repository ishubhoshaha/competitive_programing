#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#define N 1500000
#define lolo long long
using namespace std;
bool isPrime[N];
vector <lolo > primeList,trailZero;

void sieve()
{
    int i,j;
    int sqrtN=sqrt(N);
    memset(isPrime,true,N);
    for(i=4;i<N;i+=2)
        isPrime[i]=false;
    isPrime[0]=isPrime[1]=false;
    for(i=3;i<=sqrtN;i+=2)
        if(isPrime[i]==true)
            for(j=i*i;j<N;j+=i)
                isPrime[j]=false;
    for(i=0;i<N;i++)
        if(isPrime[i]==true)
            primeList.push_back(i);
}
lolo numberofDivisor(lolo number)
{
    lolo sqrtNumber=sqrt(number);
    lolo i,j,power,divisor=1;
    for(i=0;primeList[i]<=sqrtNumber;i++)
    {
        power=0;
        if(number%primeList[i]==0)
        {
            while(number%primeList[i]==0)
            {
                number/=primeList[i];
                power++;
            }
        }
        divisor=divisor * (power+1);
        sqrtNumber=sqrt(number);
    }
    if(number>1)
        divisor*=2;

    return divisor;

}
int main()
{
    sieve();
    lolo number,testCase,t=1;
    scanf("%lld",&testCase);
    /*for(i=1;i<=2000000000000;i++)
    {
        trailZero.push_back(numberofDivisor(i)-1);
    }*/
    while(testCase--)
    {
        scanf("%lld",&number);
            printf("Case %lld: %lld\n",t++,numberofDivisor(number)-1);//substract 1 bcz base start from 2
    }

    return 0;
}
