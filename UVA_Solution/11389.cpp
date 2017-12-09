/*
Problem Type: Greedy, Sorting
*/

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
int n,d,r;
class isValid{
public:
    int operator()(int x,int y){
        if(x+y>d){
            return (x+y)-d;
        }
        else
            return 0;
    }
};
int main(){

    while(cin>>n>>d>>r and n!=0){// and d!=0 and r!=0){
        vi morningShift,eveningShift;
        rep(i,0,n){
            int n;
            cin>>n;
            morningShift.pb(n);
        }
        rep(i,0,n){
            int n;
            cin>>n;
            eveningShift.pb(n);
        }
        sort(morningShift.begin(),morningShift.end());
        sort(eveningShift.begin(),eveningShift.end(),greater<int>());
        transform(morningShift.begin(),morningShift.end(),eveningShift.begin(),morningShift.begin(),isValid());
//        int sum = 0;
//        for(int i =0;i<morningShift.size();i++){
//            sum += morningShift[i];
//        }
        cout<<accumulate(morningShift.begin(),morningShift.end(),0)*r<<endl;
    }
}
