#include<stdio.h>
#include<string.h>
int main()
{
    char message[100000];
    int i;
    while(gets(message))
    {
        for(i=0;message[i]!='\0';i++)
        {
            message[i]=message[i]-7;
        }
        puts(message);
    }
    return 0;
}
