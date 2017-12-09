#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int prime(int n)
{
    int i;
    if( (n==0) || (n==1) )
        return 0;
    for(i=2;i<=n;i++)
        if(n%i==0)
            break;
    if(i==n)
        return 1;
    else
        return 0;
}
int main()
{
    int t,test,i,index,j,k,l,temp,m;
    char str[2500];
    scanf("%d",&test);
    int *storage,*primecheck;
    for(t=1;t<=test;t++)
    {
        k=0;
        storage=(int *)calloc(62,sizeof(int));//Use calloc instead of malloc CoZ it assign array to 0
        primecheck=(int *)calloc(500,sizeof(int));
        scanf("%s",str);
        for(i=0;str[i]!='\0';i++)
        {
            if(isalpha(str[i]))
            {
                if(islower(str[i]))
                {
                    index=str[i]-97;
                    storage[index]+=1;
                }
                else
                {
                    index=(str[i]-65)+26;
                    storage[index]+=1;
                }
            }
            else
            {
                index=(str[i]-48)+26+26;
                storage[index]+=1;
            }
        }
        j=0;
        for(i=0;i<62;i++)
        {
            //if(storage[i]!=0)
                k=prime(storage[i]);
            if(k==1)
            {
                if(i<26)
                    l=i+97;
                else if( (i>25)&&(i<52) )
                    l=i+39;
                else
                    l=i-4;
                primecheck[j++]=l;
            }
        }
        if(primecheck[0]!=0)
        {
            printf("Case %d: ",t);
            for(i=1;i<j;i++)//Short by laxicographically asccending(USING BUBBLE SHORT)
                for(m=0;m<j-i;m++)
                    if(primecheck[m]>primecheck[m+1])
                    {
                        temp=primecheck[m];
                        primecheck[m]=primecheck[m+1];
                        primecheck[m+1]=temp;
                    }
            for(i=0;i<j;i++)
                printf("%c",primecheck[i]);
            printf("\n");
        }
        else
            printf("Case %d: empty\n",t);
    }
    return 0;
}
