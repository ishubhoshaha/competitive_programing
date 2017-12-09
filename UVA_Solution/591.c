#include<stdio.h>
int main()
{
    long int stacks,movenumber=0,i,height,total=0,set=1,b;
    long int bricks[150];
    while(scanf("%ld",&stacks)==1)
    {

        total=0;
        movenumber=0;
        for(i=0;i<stacks;i++)
            scanf("%ld",&bricks[i]);
        for(i=0;i<stacks;i++)
        {
            total+=bricks[i];

        }
        height=total/stacks;
        for(i=0;i<stacks;i++)
        {
            if(bricks[i]>height)
                movenumber=movenumber+(bricks[i]-height);
        }
        printf("Set #%ld\n",set++);
        printf("The minimum number of moves is %ld.\n\n",movenumber);
    }
    return 0;
}
