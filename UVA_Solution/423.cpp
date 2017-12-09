/*
Problem Type: Floyed Warshall
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
long long dist[101][101];
long long inf = 1LL<<60;
void reset(){
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            dist[i][j] = inf;
        }
        dist[i][i] = 0;
    }
}
long long getInt(string str){
    int len = str.length();
    long long sum = 0;
    rep(i,0,len){
        sum = sum *10 + str[i]-'0';
    }
    return sum;
}
void floyedWarshall(int totalPro){
    rep(k,0,totalPro){
        rep(i,0,totalPro){
            rep(j,0,totalPro){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
int main(){
    //open("inp.txt");
    int totalPro;
    while(cin>>totalPro){
        cin.ignore();
        reset();
        for(int i=1;i<totalPro;i++){
            for(int j = 0;j<i;j++){
                string n;
                cin>>n;
                if(n!="x"){
                    dist[i][j]=getInt(n);
                    dist[j][i]=getInt(n);
                }
            }
        }
        floyedWarshall(totalPro);
        long long ans = 0;
        rep(i,0,totalPro){
            ans = max(ans,dist[0][i]);
        }
        cout<<ans<<endl;

    }
}
