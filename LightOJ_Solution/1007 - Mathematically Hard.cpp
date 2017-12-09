#include<iostream>
#include<cstdio>
#include<cstring>
#define bMAX 5000500
#define ull unsigned long long
using namespace std;
ull phi[bMAX];
void sieve()
{
    //score[1]=0;
    phi[1]=0;
    for(int i=2;i<bMAX;i++)
        phi[i]=i;
    for(int i=2;i<bMAX;i++)
    {
        if( phi[i]==i)
        {
            for(int j=i+i;j<bMAX;j+=i)
                {
                    phi[j]=phi[j]-phi[j]/i;
                }
            phi[i]=i-1;
        }
    }
    for(int i=2;i<bMAX;i++)
    {
        //phi[i]=;
        phi[i]=phi[i-1]+phi[i]*phi[i];
        //score[i]=score[i-1]+;
       // cout<<score[i]<<endl;
    }
}
int main()
{
    sieve();
    int cases,caseno;
    //freopen("L.txt","r",stdin);
    scanf("%d",&cases);
    //cout<<score[6]-score[5];
    for(caseno=1;caseno<=cases;caseno++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("Case %d: %llu\n",caseno,phi[b]-phi[a-1]);
        //cout<<phi[2];
    }
    return 0;

}
