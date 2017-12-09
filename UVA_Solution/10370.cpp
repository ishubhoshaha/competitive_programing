/*
Problem Type: Adhoc
*/
#include<bits/stdc++.h>

#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define msi map<string, int>

#define visited_ true
#define unvisited_ false
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
#define dy4 {0,0,-1,+1}
#define dx8 {-1,0,+1,-1,+1,-1,0,+1}
#define dy8 {+1,+1,+1,0,0,-1,-1,-1}
using namespace std;
int main(){
    int cases;
    open("10370.txt");
    cin>>cases;
    cin.ignore();
    while(cases--){
        int dp[1000] = {0};
        int n;
        cin>>n;
        cin.ignore();
        int sum = 0,mx = 0;
        for(int i =0;i<n;i++){
            int num;
            cin>>num;
            sum += num;
            dp[num-1]++;
            mx = max(mx,num);
        }
        int avg = sum/n,c = 0;
        for(int i = avg;i<=mx;i++)
            c+=dp[i];
            //cout<<dp[i]<<" ";
        double result = ((double)(c)/(double)(n))*100;
        printf("%.3lf%%\n",result);
    }
}

