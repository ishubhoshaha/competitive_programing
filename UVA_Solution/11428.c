#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,n,sum,w;
    while(scanf("%d",&n)==1)
    {
        w=0;
        if(n==0)
            return 0;
        for(i=1;i<100;i++)
        {
            for(j=0;j<=i;j++)
            {
                sum= (i*i*i) - (j*j*j);
                if(sum==n)
                {
                    w=1;
                    break;
                }
            }
            if(w==1)
                break;
        }

        if(sum==n)
            printf("%d %d\n",i,j);
        else
            printf("No solution\n");

    }
    return 0;
}
