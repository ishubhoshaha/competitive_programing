#include<bits/stdc++.h>

#define pii pair<int,int>
#define msi map<string,int>

#define vpii vector<pii>
#define vmsi vector<msi>


#define _visit true
#define _unvisit false
#define pb(n) push_back(n)
#define INF 2000000000

using namespace std;
int dist[1000][1000];
int min_dist[1000][1000];
int dx[] = {-1,+1,0,0};
int dy[] = {0,0,-1,+1};
int n,m;
struct node{
    int row,column,cost;
    node(){
    }
    node(int r,int co,int c){
        row = r,cost = c,column = co;
    }
    bool operator<(node x) const{
        return cost>x.cost;
    }
};
void dijsktra(int row,int column,int initalCost){
    //memset(min_dist,INF,sizeof (min_dist));
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            min_dist[i][j] = INF;
    priority_queue<node> pq;
    min_dist[row][column] = initalCost;
    pq.push(node(row,column,initalCost));
    while(!pq.empty()){
        int rowu,colu,c;
        node temp;
        temp = pq.top();
        pq.pop();
        rowu=temp.row,colu=temp.column,c=temp.cost;
        if(c==min_dist[rowu][colu]){
            for(int k=0;k<4;k++){
                int x= rowu+dx[k];
                int y= colu+dy[k];
                if(x>0 and y>0 and x<=n and y<=m and (c+dist[x][y]<min_dist[x][y])){
                    min_dist[x][y] = c+dist[x][y];
                    pq.push(node(x,y,min_dist[x][y]));
                }

            }
        }
    }
}
int main(){
    int testcase;
   // freopen("inp.txt","r",stdin);
    cin>>testcase;
    cin.ignore();
    for(int caseno=1;caseno<=testcase;caseno++){
        for(int i=0;i<1000;i++){
            for(int j=0;j<1000;j++){
                dist[i][j] = 0;
                min_dist[i][j] = 0;
            }
        }
        cin>>n>>m;
        cin.ignore();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&dist[i][j]);
            }
        }
        dijsktra(1,1,dist[1][1]);
//        for(int i=1;i<=n;i++){
//            for(int j=1;j<=m;j++){
//                printf("%d ",min_dist[i][j]);
//            }
//            cout<<endl;
//        }
        cout<<min_dist[n][m]<<endl;
    }

}
