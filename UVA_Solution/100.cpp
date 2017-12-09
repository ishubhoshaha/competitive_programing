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
int getResult (ull n){
    int c =1;
    while(n!=1){
        if(n%2==0){
            n/=2;
        }
        else
            n = (3*n)+1;
        ++c;
        //cout<<n<<endl;
    }
    //cout<<c<<endl;
    return c;
}
int main(){
    int a,b,mx;
    while(cin>>a>>b and a>0 and b>0){
        int sa= a,sb = b;
        if(a>b){
            swap(a,b);
        }
        mx = getResult(a);
        //cout<<mx<<endl;
        for(int i = a+1;i<=b;i++){
            mx = max(getResult(i),mx);
        }
        cout<<sa<<" "<<sb<<" "<<mx<<endl;
    }

}
