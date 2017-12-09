#include<stdio.h>
long  sum_digit(long  n)
{
    long  add,sum=0;
    while(n>0)
    {
        add=n%10;
        n=n/10;
        sum=sum+add;
    }
    return (sum);
}
int main()
{
    long n,sum;
    while(scanf("%ld",&n)==1)
    {
        if(n==0)
            return 0;
        sum=sum_digit(n);
        while(sum>=10)
            sum=sum_digit(sum);
        printf("%ld\n",sum);
    }
    return 0;
}
