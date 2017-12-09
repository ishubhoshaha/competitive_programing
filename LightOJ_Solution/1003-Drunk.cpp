#include<bits/stdc++.h>
using namespace std;
vector<int>graph[10005];
map<string ,int>mp;
int indegree[10005];

void TopSort(int node){
    queue<int>q;
    for(int i = 1;i<=node;i++){
        if(indegree[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0;i<graph[u].size();i++){
            int v = graph[u][i];
            indegree[v]--;
            if(indegree[v]==0)
                q.push(v);

        }

    }
}
void Initialize(){
    for(int i = 0;i<10005;i++){
        graph[i].clear();
        indegree[i] = 0;
    }
    mp.clear();
}
int main(){
    int test;
    scanf("%d",&test);
    for(int t = 1;t<=test;t++){

        int n,x = 1;
        scanf("%d",&n);
        for(int i = 0;i<n;i++){
            string u,v;
            cin>>u>>v;
            if(mp.find(u)==mp.end())
            {
                mp[u] = x++;
            }
            if(mp.find(v)==mp.end())
            {
                mp[v] = x++;
            }
            graph[mp[u]].push_back(mp[v]);
            indegree[mp[v]]++;
        }
        x = mp.size();
        TopSort(x);
        bool f = false;
        for(int i = 1;i<=x;i++){
            if(indegree[i]!=0){
                f = true;
            }
        }
        if(f) printf("Case %d: No\n",t);
        else printf("Case %d: Yes\n",t);
        Initialize();
    }

}
