
#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,counter,pcounter;
    float temp;
    while(scanf("%d %d",&a,&b)==2)
    {
    	if ((a==0)&&(b==0))
            return 0;
        else
        {
            pcounter=0;
            for (counter=a;counter<=b;counter++)
            {
                temp=sqrt(counter);
                int t=(int)temp;
                if(temp==t)
                pcounter++;
            }
        }
        printf("%d\n",pcounter);
    }
    return 0;
}

