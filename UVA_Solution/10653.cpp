#include<bits/stdc++.h>

#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define msi map<string, int>
#define mem(arrayName,i) memset(arrayName,int (i),sizeof arrayName)
#define pb(number) push_back(number)
#define _VISIT true
#define _UNVISIT false

#define INF 2000000000
#define _INF 127
#define _HALF_INF 63

using namespace std;
int adjMatrix[1001][1001];
bool visit[1001][1001];
int dist[1001][1001];

int dx[] = {+1,-1,0,0};
int dy[] = {0,0,+1,-1};
int row,column;
int BFS(int startX,int startY,int destX,int destY){
    queue<pii > q;
    q.push(make_pair(startX,startY));
    visit[startX][startY] = true;
    dist[startX][startY] = 0;
    while(!q.empty()){
        int ux,uy;
        pii temp;
        temp= q.front();
        ux = temp.first;
        uy = temp.second;
        q.pop();
        if(ux==destX and uy==destY){
            return dist[ux][uy];
        }
        else{
            for(int i =0;i<4;i++){
                int x,y;
                x = ux+dx[i];
                y = uy+dy[i];
                if(x>=0 and y>=0 and x<row and y<column and !visit[x][y] and adjMatrix[x][y]==0){
                    visit[x][y] = true;
                    dist[x][y] = dist[ux][uy] + 1;
                    q.push(pii (x,y));
                }
            }
        }
    }
    return dist[destX][destY];
}
int main(){

    freopen("in.txt","r",stdin);
    while(cin>>row>>column and row!=0 and column!=0){
        for(int i = 0;i<1001;i++){
            for(int j = 0;j<1001;j++){
                adjMatrix[i][j] = 0;
                visit[i][j] = false;
                dist[i][j] = 0;
            }
        }

        int n;
        cin>>n;
        cin.ignore();
        for(int i = 0 ;i<n;i++){
            int r,num;
            cin>>r>>num;
            cin.ignore();
            for(int j = 0;j<num;j++){
                int c;
                cin>>c;
                adjMatrix[r][c]=1;
            }
        }
        int startX,startY,destX,destY;
        cin>>startX>>startY;
        cin>>destX>>destY;
//        for(int i = 0;i<row;i++){
//            for(int j =0;j<column;j++){
//                cout<<adjMatrix[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        cout<<BFS(startX,startY,destX,destY)<<endl;
    }
}
