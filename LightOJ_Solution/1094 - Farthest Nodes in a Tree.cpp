#include<bits/stdc++.h>
using namespace std;
int visit[30001];
vector<pair<int,int> >graph[30001];
int dist[30001];
int mx = INT_MIN,save;
void dfs(int node){
    visit[node] = true;
    for(int i = 0;i<graph[node].size();i++){
        int v = graph[node][i].first,w = graph[node][i].second;
        if(!visit[v]){
            dist[v] = dist[node]+w;

            if(dist[v]>mx){
                save = v;
                mx = dist[v];
                //cout<<w<<endl;
            }
            dfs(v);
        }
    }
}
void flash(){
    for(int i = 0;i<30001;i++){
        visit[i] = false;
        dist[i] = 0;
        graph[i].clear();
    }
    mx = INT_MIN;
}
void init(int n){
    for(int i = 0;i<n;i++){
        visit[i] = false;
        dist[i] = 0;
    }
}
int main(){

    //freopen("in.txt","r",stdin);
    int test;
    scanf("%d",&test);
    for(int t = 1;t<=test;t++){
        int n;
        scanf("%d",&n);
        for(int i = 0;i<n-1;i++){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            graph[u].push_back(make_pair(v,w));
            graph[v].push_back(make_pair(u,w));
        }
        dfs(0);
        init(n);
        dfs(save);
        printf("Case %d: %d\n",t,mx);
        flash();
    }
    return 0;
}
