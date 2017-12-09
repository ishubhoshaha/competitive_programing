#include<bits/stdc++.h>

#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define msi map<string, int>

#define ull unsigned long long
#define EPS 1e-9
#define Pi acos(-1.0)
#define INF 2000000000
#define _INF 127
#define _HALF_INF 63
#define rep(i,from,to) for(int i = from; i<to ;i++)
#define open(inp) freopen(inp,"r",stdin)
#define Clear(a) memset(a,0,sizeof(a))
#define setfalse(a) memset(a,false,sizeof(a))
#define pb(number) push_back(number)
#define dx4 {-1,+1,0,0}
#define dy4 {-1,+1,0,0}
#define dx8 {-1,0,+1,-1,+1,-1,0,+1}
#define dy8 {+1,+1,+1,0,0,-1,-1,-1}
using namespace std;
ull dp[30005];
int coin[] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
ull coinChange(){
    Clear(dp);
    dp[0] = 1;
    rep(i,0,11){
        rep(j,coin[i],30004){
            dp[j] = dp[j] + dp[j-coin[i]];
        }
    }
}
int main(){
    int money_int,money_double;
    coinChange();
    double m;
    while(scanf("%d.%d",&money_int,&money_double)){
        int money = money_int*100+money_double;
        if(money==0)
            break;
        if(money_double<10)
            printf("%3d.0%d%17llu\n",money_int,money_double,dp[money]);
        else
            printf("%3d.%d%17llu\n",money_int,money_double,dp[money]);
    }
}
/*
Critical Input:
299.5
Note: 299.5 means 299.05 taka
*/
