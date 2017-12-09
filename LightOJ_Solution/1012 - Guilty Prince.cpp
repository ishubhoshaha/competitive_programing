#include<bits/stdc++.h>
 
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define msi map<string, int>
#define mem(arrayName,i) memset(arrayName,int (i),sizeof arrayName)
#define pb(number) push_back(number)
#define _VISIT true
#define _UNVISIT false
#define INF 63
 
using namespace std;
int fx[] = {0,-1,+1,0};
int fy[] = {+1,0,0,-1};
char grid[21][21];
//string grid[21];
bool visited[21][21];
int cell = 1;
void dfs(int startx,int starty,int w,int h){
 
    visited[starty][startx] = _VISIT;
    for(int i=0;i<4;i++){
        int x = startx + fx[i];
        int y = starty + fy[i];
        if(x>=0 and y>=0 and x<w and y<h and visited[y][x]==_UNVISIT and grid[y][x]!='#'){
            ++cell;
            dfs(x,y,w,h);
        }
    }
}
int main()
{
    int cases;
    //freopen("1012.txt","r",stdin);
    scanf("%d",&cases);
    getchar();
    for(int caseno = 1;caseno <= cases;caseno++){
//        for(int i=0;i<21;i++)
//            grid[i].clear();
        memset(grid,0,sizeof (grid));
        int wide,hight,startx,starty;
        scanf("%d %d",&wide,&hight);
        getchar();
//        for(int i=0;i<=hight;i++){
//            getline(cin,grid[i]);
//        }
        for(int i=0;i<hight;i++){
            for(int j=0;j<wide;j++){
                cin>>grid[i][j];
                if(grid[i][j]=='@'){
                    startx=j;
                    starty=i;
                }
            }
        }
//        for(int i= 0;i<hight;i++)
//            cout<<grid[i]<<endl;
        bool flag = true;
//        for(int i=0;i<hight;i++){
//            for(int j=0;j<grid[i].length();j++){
//                if(grid[i][j]=='@'){
//                    startx=j;
//                    starty=i;
//                    flag = false;
//                    break;
//                }
//            }
//            if(flag == false)
//                break;
//        }
        cell = 1;
        memset(visited,false,sizeof (visited));
 
        dfs(startx,starty,wide,hight);
        printf("Case %d: %d\n",caseno,cell);
 
    }
    return 0;
}