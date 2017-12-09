#include<stdio.h>
#include<math.h>

int main()
{
    long long int firstNumber,secondNumber,counter,add1,add2,sum,carry;
    while(scanf("%lld %lld",&firstNumber,&secondNumber)==2)
    {
        counter=sum=carry=0;
        if((firstNumber == 0)&& (secondNumber == 0))
            break;
        while( (firstNumber!=0)||(secondNumber!=0) )
        {
            sum = firstNumber % 10 + secondNumber % 10 + carry;
            carry =0;
            firstNumber = firstNumber / 10;
            secondNumber = secondNumber / 10;
            if(sum > 9)
                {
                    carry = sum/10;
                    counter++;
                }
        }

        if(counter!=0)
        {
            if(counter==1)
                printf("%lld carry operation.\n",counter);
            else
                printf("%lld carry operations.\n",counter);
        }
        else
            printf("No carry operation.\n");
    }
    return 0;
}
