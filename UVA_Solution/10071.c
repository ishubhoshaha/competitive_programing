#include<stdio.h>
int main()
{
    long long int v,t,s;
    while(scanf("%lld %lld",&v,&t)==2)
    {
        s=v*t*2;
        printf("%lld\n",s);
    }
    return 0;
}
