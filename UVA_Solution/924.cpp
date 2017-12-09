#include<bits/stdc++.h>

#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define msi map<string, int>

#define visit_ true
#define unvisit_ false
#define ull unsigned long long
#define EPS 1e-9
#define Pi acos(-1.0)
#define INF 2000000000
#define _INF 127
#define _HALF_INF 63

#define open(inp) freopen(inp,"r",stdin)
#define setZero(a) memset(a,0,sizeof(a))
#define setfalse(a) memset(a,false,sizeof(a))
#define pb(number) push_back(number)

using namespace std;
vi adjList[2505];
bool visit[2505];
int level[2505];
map<int,int> boomSize;
void bfs(int src){
    setfalse(visit);
    setZero(level);

    visit[src] = true;
    level[src] = 0;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        int s = adjList[u].size();
        for(int i = 0;i<s;i++){
            int v = adjList[u][i];
            if(!visit[v]){
                visit[v] = true;
                level[v] = level[u] + 1;
                boomSize[level[v]] ++;
                q.push(v);
            }
        }
    }
}
int main(){
    int employeeNumber;
    open("r.txt");
    //while(cin>>employeeNumber){
            cin>>employeeNumber;
            cin.ignore();
            for(int i =0;i<employeeNumber;i++){
            int n;
            cin>>n;
            cin.ignore();
            for(int j =0;j<n;j++){
                int to;
                cin>>to;
                adjList[i].pb(to);
            }
        }
        cin.ignore();
        int t;
        cin>>t;
        cin.ignore();
        for(int i = 0;i<t;i++){
            int src;
            cin>>src;
            bfs(src);
            int mx=-1,day;
            for(map<int,int> ::iterator map_it = boomSize.begin();map_it!=boomSize.end();map_it++){
                //cout<<map_it->first<<" "<<map_it->second<<endl;
                if(mx<map_it->second){
                    day=map_it->first;
                    mx=map_it->second;
                }
            }
            if(mx==-1){
                cout<<"0"<<endl;
            }
            else
                cout<<mx<<" "<<day<<endl;
            boomSize.clear();
        }
    //}

}
