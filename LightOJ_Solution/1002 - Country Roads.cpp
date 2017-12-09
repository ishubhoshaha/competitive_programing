#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int> > graph[501];
vector<int>dist(501,1<<29);
void init(){
    for(int i = 0;i<n;i++){
        graph[i].clear();
        dist[i] = 1<<29;
    }
}
void dijsktra(int s){
    priority_queue < pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    dist[s] = 0;
    pq.push(pair<int,int>(0, s));
    while (!pq.empty()) {
        pair<int,int> top = pq.top();
        pq.pop();
        int d = top.first, u = top.second;
        if (d == dist[u]){
 
            for(int i=0;i<graph[u].size();i++){
                int v = graph[u][i].first,weight_u_v = graph[u][i].second;
                if (max(weight_u_v,dist[u]) < dist[v]) {
 
                    dist[v] = max(weight_u_v,dist[u]);
                    pq.push(pair<int,int>(dist[v], v));
                }
 
            }
        }
    }
}
int main(){
 
    //freopen("in.txt","r",stdin);
    int test;
    scanf("%d",&test);
    for(int t = 1;t<=test;t++){
        getchar();
        int node,edge;
        scanf("%d %d",&n,&edge);
        for(int i = 0;i<edge;i++){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            graph[u].push_back(make_pair(v,w));
            graph[v].push_back(make_pair(u,w));
 
        }
        int home;
        scanf("%d",&home);
        dijsktra(home);
        printf("Case %d:\n",t);
        for(int i = 0;i<n;i++){
            if(dist[i]==1<<29)
                printf("Impossible\n");
            else{
                printf("%d\n",dist[i]);
            }
        }
        init();
 
    }
}
