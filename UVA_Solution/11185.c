#include<stdio.h>
#include<math.h>
int main()
{
    long int i,index,index2,number;
    int result[100];
    for(i=1;i<=100;i++)
    {
        index=0;
        scanf("%ld",&number);
        if(number<0)
            return 0;
        if(number!=0)
        {
            while(number!=0)
            {
                result[index]=number%3;
                number=number/3;
                index++;
            }
            for(index2=index-1;index2>=0;index2--)
                printf("%d",result[index2]);
            //printf("\n");
        }
        else
            printf("0");
        printf("\n");
    }
}
