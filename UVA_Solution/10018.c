#include<stdio.h>
long int reverse(long int num)
{
    long int rev=0;
    while(num!=0)
    {
        rev=rev*10+num%10;
        num=num/10;
    }
    return (rev);
}
int main()
{
    int index,test,iteration;
    long int num,reverse_num,total_num,palindrome;
    scanf("%d",&test);
    for(index=0;index<test;index++)
    {

        scanf("%ld",&num);
        iteration=0;
        while(++iteration)
        {
            reverse_num=reverse(num);
            total_num=reverse_num+num;
            palindrome=reverse(total_num);
            if(palindrome!=total_num)
            {
                num=total_num;
                continue;
            }
            else
            {
                printf("%ld %ld\n",iteration,palindrome);
                break;
            }
        }
    }
    return 0;
}
