#include<stdio.h>
#include<math.h>
int main()
{
    long int test,i,g,l,temp,temp1,temp2,n;
    scanf("%ld",&test);
    for (i=0;i<test;i++)
    {
        scanf("%ld %ld",&g,&l);
        temp1=g;
        temp2=l;
        if(g>l)
        {
            temp=g;
            g=l;
            l=temp;
        }
        while(g!=0)
        {
            n=l%g;
            l=g;
            g=n;
        }
        n=(temp1*temp2)/l;
        if((l==temp1)&&(n==temp2))
            printf("%ld %ld\n",l,n);
        else
            printf("-1\n");
    }
    return 0;
}
