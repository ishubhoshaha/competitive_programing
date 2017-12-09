#include<bits/stdc++.h>

#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define msi map<string, int>
#define mem(arrayName,i) memset(arrayName,int (i),sizeof arrayName)
#define pb(number) push_back(number)
#define _VISIT true
#define _UNVISIT false
#define READ(str) freopen( str,"r",stdin)

#define INF 2000000000
#define _INF 127
#define _HALF_INF 63

using namespace std;
int grid[101][101];
int dx[]={-1,0,+1,-1,0,+1,-1,0,+1};
int dy[]={-1,-1,-1,0,0,0,+1,+1,+1};
int main(){
    int row,column;
    READ("10189.txt");
    //freopen("w.txt","w",stdout);
    int counter=0;
    while(scanf("%d %d",&row,&column)&&(row!=0&&column!=0)){
        if(counter != 0)
            printf("\n");
        getchar();
        memset(grid,0,sizeof grid);
        char ch;
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                scanf("%c",&ch);
                if(ch=='*')
                    grid[i][j] = -1;
                else
                    grid[i][j] = 0;
            }
            getchar();
        }
        for(int i = 0;i<row;i++){
            for(int j = 0;j<column;j++){
                if(grid[i][j]==-1){
                    for(int k = 0;k<=8;k++){
                        int x,y;
                        x=i+dx[k];
                        y=j+dy[k];
                        //cout<<x<<" "<<y<<endl;
                        if(x>=0 and y>=0 and x<row and y<column and grid[x][y]!=-1){

                            ++grid[x][y];
                        }
                    }
                }
            }
        }
        printf("Field #%d:\n",++counter);
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(grid[i][j]==-1){
                    printf("*");
                }
                else
                    printf("%d",grid[i][j]);
            }
            printf("\n");
        }
    }
}
