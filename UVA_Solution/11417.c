#include<stdio.h>
int gcd(int i,int j)
{
    int temp;
    if(i>j)
    {
        temp=j;
        j=i;
        i=temp;
    }
    while(i!=0)
    {
        temp=i;
        i=j%i;
        j=temp;
    }
    return (j);
}
int main()
{
    int test,i,j,n,g;
    if(n==0)
        return 0;
    while((scanf("%d",&n)==1))
    {
        g=0;
        if(n==0)
            return 0;
        for(i=1;i<n;i++)
        {
            for (j=i+1;j<=n;j++)
            {
                g=g+gcd(i,j);
            }
        }
        printf("%d\n",g);
    }
    return 0;
}
