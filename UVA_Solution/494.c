#include<stdio.h>
#include<string.h>
int main()
{
    int i,word;
    char str[1999];
    while(gets(str))
    {
        word=0;
        i=0;
        while(str[i]!='\0')
        {
            if ( ((str[i]>=65)&&(str[i]<=90)) || ((str[i]>=97)&&(str[i]<=122)) )
                if(((str[i+1]<65)||(str[i+1]>90)) && ((str[i+1]<97)||(str[i+1]>122)) )
                    word++;
            i++;
        }
        printf("%d\n",word);
    }
    return 0;
}
