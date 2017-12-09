/*
Problem Type: Graph Theory, BFS variants, Graph Coloring
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
#define setfalse(a) memset(a,false,sizeof(a))
#define pb(number) push_back(number)
#define dx4 {-1,+1,0,0}
#define dy4 {-1,+1,0,0}
#define dx8 {-1,0,+1,-1,+1,-1,0,+1}
#define dy8 {+1,+1,+1,0,0,-1,-1,-1}
using namespace std;
vi adjList[201];
bool visit[201];
int color[201];
bool isBipatrit(int src){
    visit[src] = true;
    color[src] = 0;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        int l=adjList[u].size();

        rep(i,0,l){
            int v = adjList[u][i];
            if(!visit[v]){
                visit[v] = true;
                color[v] = color[u] + 1;
                q.push(v);
            }
            if(color[u]==color[v])
                return false;
        }
    }
    return true;
}
int main(){
    open("10004.txt");
    int node,edge;
    while(cin>>node>>edge and node!=0){
        cin.ignore();
        rep(i,0,201){//reset all container
            adjList[i].clear();
            color[i] = -1;
            visit[i] = false;
        }
        rep(i,0,edge){
            int from,to;
            cin>>from>>to;
            adjList[from].pb(to);
            adjList[to].pb(from);
        }
        if(isBipatrit(0)){
            cout<<"BICOLORABLE."<<endl;
        }
        else{
            cout<<"NOT BICOLORABLE."<<endl;
        }

    }
}
