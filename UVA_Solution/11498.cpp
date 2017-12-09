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
    int k;
   // freopen("11498.txt","r",stdin);
    while(scanf("%d",&k) and k!=0){
        int x,y;
        cin>>x>>y;
        cin.ignore();
        for(int i=1;i<=k;i++){
            int p,q;
            cin>>p>>q;
            if(p==x or q==y){
                cout<<"divisa"<<endl;
            }
            else if(p<x and q>y){
                cout<<"NO"<<endl;
            }
            else if(p>x and q>y){
                cout<<"NE"<<endl;
            }
            else if(p>x and q<y){
                cout<<"SE"<<endl;
            }
            else {
                cout<<"SO"<<endl;
            }
        }
    }
}
