#include<stdio.h>
int main()
{
    long int first_num,second_num;
    int test,index;
    scanf("%d",&test);
    for(index=1;index<=test;index++)
    {
        scanf("%ld %ld",&first_num,&second_num);
        if(first_num>second_num)
            printf(">\n");
        else if(first_num<second_num)
            printf("<\n");
        else
            printf("=\n");
    }
    return 0;
}
