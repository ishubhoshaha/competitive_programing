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

int main(){
    int n,q,cases=0;
    while(cin>>n>>q and n!=0 and q!=0){
        vi marbel;
        rep(i,0,n){
            int num;
            cin>>num;
            marbel.pb(num);
        }
        cin.ignore();
        cout<<"CASE# "<<++cases<<":"<<endl;
        sort(marbel.begin(),marbel.end());
        rep(i,0,q){
            int f;
            cin>>f;

            //bool flag = binary_search(marbel.begin(),marbel.end(),f);
            vi::iterator low = lower_bound(marbel.begin(),marbel.end(),f);
            int loc = low-marbel.begin();

            if(marbel[loc]!=f){
                cout<<f<<" not found"<<endl;
            }
            else{
                cout<<f<<" found at "<<loc+1<<endl;
            }
        }
    }
}
