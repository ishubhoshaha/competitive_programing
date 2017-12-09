#include<bits/stdc++.h>
using namespace std;
vector<int>graph[10005];
int isVisited[10005];
vector<int>get;
void DFS(int node){
    isVisited[node] = 1;
    for(int i = 0;i<graph[node].size();i++){
        if(!isVisited[graph[node][i]])
            DFS(graph[node][i]);
    }

    get.push_back(node);
}
void DFS1(int node){
    isVisited[node] = 1;
    for(int i = 0;i<graph[node].size();i++){
        if(!isVisited[graph[node][i]])
            DFS(graph[node][i]);
    }

}
void initialize(){
    for(int i = 0;i<10005;i++){
        graph[i].clear();
        isVisited[i] = 0;
    }
    get.clear();
}
int main(){
    //freopen("in.txt","r",stdin);
    int test;
    scanf("%d",&test);
    for(int t = 1;t<=test;t++){
        getchar();
        int node,edge;
        scanf("%d %d",&node,&edge);
        for(int i = 0;i<edge;i++){
            int u,v;
            scanf("%d %d",&u,&v);
            graph[u].push_back(v);
        }
        int ans = 0;
        for(int i = 1;i<=node;i++){
            if(!isVisited[i]){
                //cout<<i<<endl;
                DFS(i);
            }
        }
        memset(isVisited,0,sizeof isVisited);

        for(int i = node-1;i >= 0;i--){

            if(!isVisited[get[i]])
            {
                DFS1(get[i]);
                ans++;
            }
        }
        printf("Case %d: %d\n",t,ans);
        initialize();
    }
    return 0;
}
