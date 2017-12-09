/*
Problem Type: Graph Traversal, Adhoc
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
    int testcase;
    cin>>testcase;
    cin.ignore();
    int c = 0;
    while(testcase--){
        if(c){
            c =1;
            getchar();
        }
        int neighbours,mx = INF,mxi;
        vi result[1000];
        cin>>neighbours;
        cin.ignore();
        for(int i = 1;i<=neighbours;i++){
            string str;
            getline(cin,str);
            stringstream ss(str);
            int n,outdegree=0;
            while(ss>>n){
                ++outdegree;
            }
            if(mx >= outdegree){
                mx = outdegree;
                mxi = i;
                result[outdegree].pb(i);
            }
        }
        int len = result[mx].size();
        cout<<result[mx][0];
        for(int i = 1;i<len;i++){
            cout<<" "<<result[mx][i];
        }
        cout<<endl;
    }
}
