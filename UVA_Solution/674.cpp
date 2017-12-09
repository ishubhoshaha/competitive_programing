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
int make,counter=0;
int dp[6][7500];
int coin[]={1,5,10,25,50};
int coinChange(int i, int amount){
//cout<<i<<" "<<amount<<endl;
    if(i>=5){
        if(amount==0){
            return 1;
        }
        else //r1 = 0;
            return 0;
    }

    if(dp[i][amount]!=-1){
        return dp[i][amount];
    }
    int r1=0,r2=0;
    if(amount-coin[i]>=0){
        r1=coinChange(i,amount-coin[i]);
    }
    r2=coinChange(i+1,amount);
    dp[i][amount] = r1+r2;
    return dp[i][amount];
}
int main(){
    memset(dp,-1,sizeof(dp));
    while(cin>>make){

        cout<<coinChange(0,make)<<endl;
    }

}
