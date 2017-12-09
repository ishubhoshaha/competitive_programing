#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
long int Mccarthy(long int number)
{
    if (number==91)
       return 91;
    if (number>=101)
       return  (number-10);
    else if(number<=100)
        return (Mccarthy(Mccarthy(number+11)));
}
int main()
{
    long int mc,number;
    while(scanf("%ld",&number)==1&&number!=0)
    {
    	mc=Mccarthy(number);
    	printf("f91(%ld) = %ld\n",number,mc);
    }
    return 0;
}
