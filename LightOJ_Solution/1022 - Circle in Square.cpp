#include<stdio.h>
#include<math.h>
int main()
{
    int t,testCase;
    double radious,area;
    scanf("%d",&testCase);
    for(t=1;t<=testCase;t++)
    {
        scanf("%lf",&radious);
        area=(radious*radious)*4 - 2*acos(0.0)*radious*radious;
        printf("Case %d: %.2lf\n",t,area);
    }
return 0;
}
