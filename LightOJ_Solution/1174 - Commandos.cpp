#include<bits/stdc++.h>
 
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define msi map<string, int>
#define Fr(i,start,end,increment) for(int i=start;i<=end;i+=increment)
using namespace std;
 
vi graph[101];
vi level(101,0);
vi level1(101,0);
bool visit[101];
 
void bfs(int src) {
    memset(visit,false,sizeof visit);
    level1.clear();
    visit[src]=true;
    level1[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        int sz=graph[u].size();
        Fr(i,0,sz-1,1) {
            int v=graph[u][i];
            if(visit[v]==false){
                visit[v]=true;
                level1[v]=level1[u]+1;
                q.push(v);
            }
        }
    }
}
int main() {
    int cases;
    //freopen("3.txt","r",stdin);
    cin>>cases;
    cin.ignore();
    Fr(caseno,1,cases,1) {
        memset(graph,0,sizeof graph);
        level.clear();
        level1.clear();
 
        int nodes,edge;
        scanf("%d\n",&nodes);
        scanf("%d\n",&edge);
        Fr(i,1,edge,1) {/// Graph Input
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
//        Fr(i,0,edge-1,1) { /// Print Adjancy List
//            int x=graph[i].size();
//            Fr(j,0,x-1,1)
//                cout<<graph[i][j]<<" ";
//            cout<<endl;
//        }
        int source,target;
        cin>>source>>target;
        cin.ignore();
 
        bfs(source);
        Fr(i,0,nodes-1,1)
            level[i]=level1[i];
 
        bfs(target);
 
        int m=0;
        Fr(i,0,nodes-1,1){ ///
            int temp;
            temp=level[i]+level1[i];
            m=max(m,temp);
        }
        printf("Case %d: %d\n",caseno,m);
    }
}