#include<bits/stdc++.h>

#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define msi map<string, int>

#define visit_ true
#define unvisit_ false
#define ull unsigned long long
#define EPS 1e-9
#define Pi acos(-1.0)
#define INF 200000000
#define _INF 127
#define _HALF_INF 63
#define rep(i,a,b) for(int i = a; i<b ;i++)
#define open(inp) freopen(inp,"r",stdin)
#define Clear(a) memset(a,0,sizeof(a))
#define setfalse(a) memset(a,false,sizeof(a))
#define pb(number) push_back(number)

using namespace std;
#define MAX 105
int decible[MAX][MAX];
void reset(){
    for(int i = 0;i<MAX;i++){
        for(int j = 0;j<MAX;j++){
            decible[i][j] = INF;
        }
        decible[i][i] = 0;
    }
}

void floyed_worshall_minmax(int cross){
    for(int k = 1;k<=cross;k++){
        for(int i = 1;i<=cross;i++){
            for(int j = 1;j<=cross;j++){
                decible[i][j] = min(decible[i][j],max(decible[i][k],decible[k][j]));
            }
        }
    }
}

int main(){
    int cross,road,query,caseno=0;
    open("10048.txt");
    while(cin>>cross>>road>>query and cross != 0 and road!=0 and query!=0){
        reset();
        cin.ignore();
        if(caseno!=0){
            cout<<endl;
        }
        for(int  i = 0;i<road;i++){
            int from,to,db;
            cin>>from>>to>>db;
            decible[from][to] = db;
            decible[to][from] = db;
        }

        floyed_worshall_minmax(cross);
        cout<<"Case #"<<++caseno<<endl;
        for(int i = 1;i<=query;i++){
            int from,to;
            cin>>from>>to;
            int result = decible[from][to];
            if(result!=INF)
                cout<<result<<endl;
            else
                cout<<"no path"<<endl;
        }
    }
}
