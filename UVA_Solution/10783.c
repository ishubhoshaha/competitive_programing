#include<stdio.h>
int main()
{
    long int upper,lower,sum,test,index,i;
    scanf("%ld",&test);
    for (index=1;index<=test;index++)
    {
        sum=0;
        scanf("%ld",&lower);
        scanf("%ld",&upper);
        for(i=lower;i<=upper;i++)
        {
            if(i%2==1)
                sum=sum+i;
        }
        printf("Case %ld: %ld\n",index,sum);
    }

}
