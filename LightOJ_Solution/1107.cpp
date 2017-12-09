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

int main(){
    int cases;
    //freopen("1107.txt","r",stdin);
    cin>>cases;
    cin.ignore();
    for(int caseno=1;caseno<=cases;caseno++){
        printf("Case %d:\n",caseno);
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cin.ignore();
        int query;
        cin>>query;
        for(int i=1;i<=query;i++){
            int x,y;
            cin>>x>>y;
            if(x>=x1 and x<=x2 and y>=y1 and y<=y2){
                cout<<"Yes"<<endl;
            }
            else
                cout<<"No"<<endl;
        }
    }
}
