#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char number[40];
    long int length,index,sum,digit,cmp;
    while(gets(number))
    {
        index=sum=0;

        if(!strcmp(number,"0"))
            return 0;

        length=strlen(number);
        while(number[index]!='\0')
        {
            digit=number[index]-48;
            sum+=(digit*(pow(2,length)-1));
            length--;
            index++;
        }

        printf("%ld\n",sum);
    }
    return 0;
}
