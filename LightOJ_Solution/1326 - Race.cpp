#include<iostream>
#include<cstdio>
#include<cstring>
#define MOD 10056
#define ull unsigned long long
using namespace std;
ull fact[1005];
ull stirNum[1005][1005];
ull stir[1005];
/*ull stirling (int n,int k)
{
    if(k==1 || n==k)
        return 1;
    if(stirNum[n-1][k-1]!=0 && stirNum[n-1][k]!=0)
        return stirNum[n-1][k-1]+stirNum[n-1][k]*k;
    //if(stirNum[n-1][k]!=0)
        //return stirNum[n-1][k];
    //cout<<"S:"<<endl;
    return stirling(n-1,k-1)+ stirling (n-1,k)*k;
}*/
void stirling ()
{
    stirNum[0][0]=0;stirNum[0][1]=1;
    for(int n=1;n<=1000;n++)
    {
        ull r=0;
        for(int k=1;k<=n;k++)
        {
            stirNum[n][k]=(stirNum[n-1][k-1]+stirNum[n-1][k]*k)%MOD;
            r=(r%MOD+( (stirNum[n][k] * fact[k])%MOD ) %MOD)%MOD;
        }
        stir[n]=r;
    }
}
void factorial()
{
    memset(fact,0,1005);
    for(int i=1;i<=1000;i++)
    {
        ull f=1;
        for(int j=1;j<=i;j++)
        {
            f=(f%MOD*j%MOD)%MOD;
        }
        fact[i]=f;
    }
}
int main()
{
    int n;
    factorial();
    stirling();
   // cout<<fact[10];
    int caseNum,cases;
    //freopen("i.txt","r",stdin);
    scanf("%d",&cases);
    for(caseNum=1;caseNum<=cases;caseNum++)
    {
        int number;
        scanf("%d",&number);
        printf("Case %d: %d\n",caseNum,stir[number]);
    }
    return 0;
}
