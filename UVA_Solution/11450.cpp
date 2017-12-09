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
#define dpClear(a) memset(a,-1,sizeof(a))
#define setfalse(a) memset(a,false,sizeof(a))
#define pb(number) push_back(number)
#define dx4 {-1,+1,0,0}
#define dy4 {-1,+1,0,0}
#define dx8 {-1,0,+1,-1,+1,-1,0,+1}
#define dy8 {+1,+1,+1,0,0,-1,-1,-1}
using namespace std;
vi product[21];
int dp [21][209];
int m,c;
int calc(int garment_item,int left){
    if(left<0)
        return -INF;
    if(garment_item==c){
        return m-left;
    }
    if(dp[garment_item][left]!=-1){
        return dp[garment_item][left];
    }
    int mx = -INF;
    for(int i = 0;i<product[garment_item].size();i++){
        mx = max(mx,calc(garment_item+1,left-product[garment_item][i]));
    }
    return dp[garment_item][left] = mx;
}
int main(){
    open("i.txt");
    int cases;
    cin>>cases;
    rep(t,1,cases+1){
        rep(i,0,21){
            product[i].clear();
        }
        cin>>m>>c;
        rep(i,0,c){
            int n;
            cin>>n;
            rep(j,0,n){
                int a;
                cin>>a;
                product[i].pb(a);
            }
        }
        memset(dp,-1,sizeof(dp));
        int a = calc(0,m);
        if(a<0){
            cout<<"no solution"<<endl;
        }
        else
            cout<<a<<endl;

    }
}
