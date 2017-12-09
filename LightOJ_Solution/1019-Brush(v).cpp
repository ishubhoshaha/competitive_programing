#include<bits/stdc++.h>
using namespace std;
int weight[101][101];
void floyed(int node){
    for(int k = 1;k<=node;k++){
        for(int i = 1;i<=node;i++){
            for(int j = 1;j<=node;j++){
                weight[i][j] = min(weight[i][k]+weight[k][j],weight[i][j]);
            }
        }
    }
}
void init(){
    for(int i = 0;i<101;i++){
        for(int j = 0;j<101;j++){
            weight[i][j] = 1<<29;
        }
        weight[i][i] = 0;
    }
}
int main(){
    int test;
    scanf("%d",&test);
    for(int t = 1;t<=test;t++){
        init();
        getchar();
        int node,edge;
        scanf("%d %d",&node,&edge);
        for(int i = 1;i<=edge;i++){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            weight[u][v] = min(weight[u][v],w);
            weight[v][u] = weight[u][v];
        }
        floyed(node);
        if(weight[1][node]==1<<29) printf("Case %d: Impossible\n",t);
        else printf("Case %d: %d\n",t,weight[1][node]);
    }
}
