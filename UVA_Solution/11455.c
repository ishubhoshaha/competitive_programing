#include<stdio.h>
#include<math.h>
int main()
{
    int t,test,a_side,b_side,c_side,d_side;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        scanf("%d %d %d %d",&a_side,&b_side,&c_side,&d_side);
        if( ( (a_side+b_side+c_side)>d_side ) && ( (a_side+b_side+d_side)>c_side )&& ( (a_side+c_side+d_side)>b_side ) &&( (b_side+c_side+d_side)>a_side ) )
        {
            if( (a_side==b_side)&&(c_side==d_side)&&(b_side==c_side) )
                printf("square\n");
            else if( (a_side==b_side && c_side==d_side) || (b_side==c_side && d_side==a_side) || (a_side==c_side&& b_side==d_side) )
                printf("rectangle\n");
            else
                printf("quadrangle\n");
        }
        else
            printf("banana\n");
    }
    return 0;
}
