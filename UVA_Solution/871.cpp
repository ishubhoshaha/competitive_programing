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
int dx[] = {-1,0,+1,-1,+1,-1,0,+1};
int dy[] = {+1,+1,+1,0,0,-1,-1,-1};
using namespace std;
string grid[30],temp[30];
int visit[30][30];
int bloobs = 0;
int grid_row,grid_column;

void dfs(int srcX,int srcY){
    visit[srcX][srcY] = 1;
    ++bloobs;
    for(int k = 0;k<8;k++){
        int x = srcX + dx[k];
        int y = srcY + dy[k];
        if(x>=0 and y>=0 and x<grid_row and y<grid_row and temp[x][y]=='1' and visit[x][y]==0){
            dfs(x,y);
        }
    }
}
int main(){
    int cases,caseno;
    //freopen("r.txt","r",stdin);
    cin>>cases;
    cin.ignore();
    getchar();
    int bl = 0;
    for(caseno = 1;caseno<=cases;caseno++){
        if(bl!=0)
            cout<<endl;
        string str;
        for(int i =0;i<30;i++){
            grid[i].clear();
            for(int j =0;j<30;j++){
                visit[i][j]=0;
            }
        }

        int l = 0;
        while(getline(cin,str)){
            if(str.length()==0){
                break;
            }
            grid[l]=str;
            temp[l++]=str;
        }
        grid_row=l;
        int max_bloobs= 0;
        for(int i = 0;i<grid_row;i++){
            for(int j =0;j<grid_row;j++){
                if(visit[i][j] == 0 and grid[i][j]=='1'){
                    dfs(i,j);
                    max_bloobs=max(bloobs,max_bloobs);
                    bloobs=0;
                }
            }
        }
        cout<<max_bloobs<<endl;
        if(caseno!=cases)
            cout<<endl;
    }
}


