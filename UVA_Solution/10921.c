#include<stdio.h>
#include<string.h>
int main()
{
    char inputstring[32];
    int i,length;
    while(gets(inputstring))
    {
        length=strlen(inputstring);
        for(i=0;i<length;i++)
        {
            if(inputstring[i]>64 && inputstring[i]<=67)
            inputstring[i]='2';
            else if(inputstring[i]>67 && inputstring[i]<=70)
            inputstring[i]='3';
            else if(inputstring[i]>70 && inputstring[i]<=73)
            inputstring[i]='4';
            else if(inputstring[i]>73 && inputstring[i]<=76)
            inputstring[i]='5';
            else if(inputstring[i]>76 && inputstring[i]<=79)
            inputstring[i]='6';
            else if(inputstring[i]>79 && inputstring[i]<=83)
            inputstring[i]='7';
            else if(inputstring[i]>83 && inputstring[i]<=86)
            inputstring[i]='8';
            else if(inputstring[i]>86 && inputstring[i]<=90)
            inputstring[i]='9';
        }
        puts(inputstring);
    }
    return 0;

}
