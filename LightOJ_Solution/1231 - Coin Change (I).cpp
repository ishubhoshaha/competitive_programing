#include<bits/stdc++.h>
using namespace std;
#define MAXCoin 50
#define MAXAmount 1000
#define MOD 100000007
int dp[MAXCoin][MAXAmount],coin[MAXCoin],c,make,MaxTake[MAXCoin];
int CC(int i,int amount){
    if(i>=c){
        if(amount==make)
            return 1;
        else return 0;
    }
    if(amount>make) return 0;
    if(amount==make) return 1;
    if(dp[i][amount]!=-1)
        return dp[i][amount];
    int x = 0;
    for(int j = 1;j<=MaxTake[i];j++){
        if(amount+coin[i]*j<=make)
            x =(x%MOD + CC(i+1,amount+coin[i]*j)%MOD)%MOD;
        else
            break;
    }
    x=(x%MOD + CC(i+1,amount)%MOD)%MOD;
    dp[i][amount] = x;
    return dp[i][amount];

}
int main(){
    int test ;
    scanf("%d",&test);
    for(int t = 1;t<=test;t++){
        memset(dp,-1,sizeof dp);
        scanf("%d %d",&c,&make);
        for(int i = 0;i<c;i++){
            scanf("%d",&coin[i]);
        }
        for(int i = 0;i<c;i++){
            scanf("%d",&MaxTake[i]);
        }
        printf("Case %d: %d\n",t,CC(0,0));
    }
}
