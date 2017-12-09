#include<stdio.h>
#include<math.h>
int main()
{
    long int t,test,i,n,num[100000],digit,zero,one,two,three,four,five,six,seven,eight,nine;
    scanf("%ld",&test);
    for(t=1;t<=test;t++)
    {
        scanf("%ld",&n);
        zero=one=two=three=four=five=six=seven=eight=nine=0;
        for(i=1;i<=n;i++)
            num[i-1]=i;
        for(i=0;i<n;i++)
        {
            while(num[i]!=0)
            {
                digit=num[i]%10;
                num[i]/=10;
                switch (digit)
                {
                    case 1:
                        one++;
                        break;
                    case 2:
                        two++;
                        break;
                    case 3:
                        three++;
                        break;
                    case 4:
                        four++;
                        break;
                    case 5:
                        five++;
                        break;
                    case 6:
                        six++;
                        break;
                    case 7:
                        seven++;
                        break;
                    case 8:
                        eight++;
                        break;
                    case 9:
                        nine++;
                        break;
                    default:
                        zero++;
                        break;
                }
            }
        }
        printf("%ld %ld %ld %ld %ld %ld %ld %ld %ld %ld\n",zero,one,two,three,four,five,six,seven,eight,nine);
    }
    
    getch();
    return 0;
}
