#include<bits/stdc++.h>

#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define msi map<string, int>

#define ull unsigned long long
#define EPS 1e-9
#define Pi acos(-1.0)
#define INF 2000000000
#define _INF 127
#define _HALF_INF 63
#define rep(i,from,to) for(int i = from; i<to ;i++)
#define open(inp) freopen(inp,"r",stdin)
#define Clear(a) memset(a,0,sizeof(a))
#define setfalse(a) memset(a,false,sizeof(a))
#define pb(number) push_back(number)
#define dx4 {-1,+1,0,0}
#define dy4 {-1,+1,0,0}
#define dx8 {-1,0,+1,-1,+1,-1,0,+1}
#define dy8 {+1,+1,+1,0,0,-1,-1,-1}
using namespace std;
int column[9],line,a,b;
bool isPlaceable(int col,int row){
    for(int i = 1;i<col;i++){
        if(column[i] == row or abs(column[i]-row)==abs(col-i))
            return false;
    }
    return true;
}
void nqueen(int queen){

    for(int i =1;i<9;i++){//row
        if(isPlaceable(queen,i)){
            //cout<<" S"<<queen<<endl;
            column[queen] = i ;
            if(queen==8 and column[b]==a){
                printf("%2d      %d",++line,column[1]);
                for(int i = 2;i<9;i++){
                    printf(" %d",column[i]);

                }
                printf("\n");
            }
            else
                nqueen(queen+1);

        }
    }
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    getchar();
    while(testcase--){
        scanf("%d %d",&a,&b);
        line = 0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        nqueen(1);
        if(testcase){
            printf("\n");
        }
    }
}
