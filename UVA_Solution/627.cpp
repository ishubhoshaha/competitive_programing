/*
    Problem Type: BFS
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
#define Clear(a,val) memset(a,val,sizeof(a))
#define setfalse(a) memset(a,false,sizeof(a))
#define pb(number) push_back(number)
#define dx4 {-1,+1,0,0}
#define dy4 {-1,+1,0,0}
#define dx8 {-1,0,+1,-1,+1,-1,0,+1}
#define dy8 {+1,+1,+1,0,0,-1,-1,-1}
using namespace std;
vi adjList[305];
bool visit[305];
int parent[305];
bool bfs(int src,int target){
    setfalse(visit);
    Clear(parent,0);
    queue<int> q;
    q.push(src);
    visit[src] = true;
    parent[src] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u==target)
            return true;
        int l = adjList[u].size();
        rep(i,0,l){
            int v = adjList[u][i];
            if(!visit[v]){
                visit[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return false;

}
void print(int src,int target){
    if(target==src)
        cout<<src;
        //return;
    else{
        print(src,parent[target]);
        cout<<" "<<target;
    }
}
int main(){
    open("net.txt");
    int n;
    bool isFirst = true;
    cout<<"-----"<<endl;
    while(cin>>n){
        if(!isFirst){
            cout<<"-----"<<endl;
        }
        rep(i,0,n)
            adjList[i].clear();
        isFirst = false;
        rep(j,0,n){
            string input;
            cin>>input;
            int len = input.length();
            rep(i,0,len){
                if(input[i]=='-'or input[i]==',')
                    input[i] = ' ';
            }
            stringstream ss(input);
            int k=0,r;
            while(ss>>r){
                if(k!=0)
                    adjList[j+1].pb(r);
                k=1;
            }
        }
        int m;
        cin>>m;
        rep(i,0,m){
            int from,to;
            cin>>from>>to;
            if(bfs(from,to)){
                print(from,to);
                //printf("\b");
            }
            else
                cout<<"connection impossible";
            cout<<endl;
        }

    }
}
