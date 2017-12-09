#include<stdio.h>
#include<math.h>
int main()
{
    long int n,k,sum,remainBut,remain;
    while(scanf("%ld %ld",&n,&k)==2)
    {
        sum=n;
        remainBut=0;
        while(n>=k)
        {
            //n=n/k+remainBut;
            remainBut=n%k;
            remain=n/k;
            sum=sum+remain;
            n=remain+remainBut;

        }
        printf("%ld\n",sum);
    }
    return 0;
}/*
{
    have=cigarette;
    extra=0;
    while(buts>k)
    {
        //buts=cigarette+extra;
        extra=buts%k;
        cigarette=(buts/k);
        have=have+cigarette;
        buts=buts/k+buts%k;

    }
    printf("%ld\n", have);*/
