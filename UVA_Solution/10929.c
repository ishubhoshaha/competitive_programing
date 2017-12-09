#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char str[1005];
    long sum,sum1,sum2,index,s1,s2,length,i;
    while(scanf("%s",&str)==1)
    {
        sum1=sum2=index=0;
        if(atoi(str)==0)
            return 0;
        while(str[index]!='\0')
        {
            if(index%2==1)
                sum1+=(str[index]-48);
            else
                sum2+=(str[index]-48);
            index++;
        }/*
        length=strlen(str);
        for(i=1;i<length;i=i+2)
            sum1+=(str[i]-0);
        for(i=0;i<length;i=i+2)
            sum2+=(str[i]-0);*/
        sum=sum1-sum2;
        if(sum%11==0)
            printf("%s is a multiple of 11.\n",str);
        else
            printf("%s is not a multiple of 11.\n",str);
    }
    return 0;
}
