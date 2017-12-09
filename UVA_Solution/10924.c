#include<stdio.h>
#include<string.h>
int prime(int number)
{
    int i;
    if(number==1)
        return 1;
    for(i=2;i<=number;i++)
        if(number%i==0)
            break;
    if(number==i)
        return 1;
    else
        return 0;

}
int main()
{
    char word[20];
    int index,number,sum,d;
    while(gets(word))
    {

        index=sum=0;
        while(word[index]!='\0')
        {
            //printf("I\n");
            if( (word[index]>64)&&(word[index]<91) )
            {

                number=word[index]-64+26;
                sum+=number;
            }
            else
            {
                number=word[index]-96;
                sum+=number;
            }
            index++;
        }
        //printf("%d\n",sum);
        d=prime(sum);
        if(d==1)
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");
    }
    return 0;
}
