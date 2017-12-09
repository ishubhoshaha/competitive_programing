#include<stdio.h>
int main()
{
    int test,index;
    long int a,b,c;
    scanf("%d",&test);
    for(index=1;index<=test;index++)
    {
        scanf("%ld %ld %ld",&a,&b,&c);
        if(((a+b)>c)&&((a+c)>b)&&((b+c)>a))
        {
            if((a==b)&&(a==c)&&(b==c))
                printf("Case %d: Equilateral\n",index);
            else if((a!=b)&&(a!=c)&&(b!=c))
                printf("Case %d: Scalene\n",index);
            else if((a==b)||(a==c)||(b==c))
                printf("Case %d: Isosceles\n",index);
        }
        else
            printf("Case %d: Invalid\n",index);
    }
    return 0;
}
//If i used long long int instead of long int, then i getting Wrong Answer.
