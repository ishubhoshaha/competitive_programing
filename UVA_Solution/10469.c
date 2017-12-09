#include<stdio.h>
int main()
{
    int num1,num2,sum;
    while(scanf("%d %d",&num1,&num2)!=EOF)
    {
        sum=num1^num2;
        printf("%d\n",sum);
    }
    return 0;
}
