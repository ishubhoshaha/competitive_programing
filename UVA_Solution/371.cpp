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
#define fr(i,from,to) for(int i = from; i<=to ;i++)
#define open(inp) freopen(inp,"r",stdin)
#define Clear(a) memset(a,0,sizeof(a))
#define setfalse(a) memset(a,false,sizeof(a))
#define pb(number) push_back(number)
#define dx4 {-1,+1,0,0}
#define dy4 {-1,+1,0,0}
#define dx8 {-1,0,+1,-1,+1,-1,0,+1}
#define dy8 {+1,+1,+1,0,0,-1,-1,-1}
using namespace std;

int main(){
    ull low,up;
    open("371.txt");
    while(cin>>low>>up and low and up){
        ull mx(0),sn;
        //fr(i,low,up)
        if(up<low){
            ull temp;
            temp = low;
            low = up;
            up = temp;
        }
        for(ull i= low;i<=up;i++){

            ull sv = i,counter(0);
            do{
                if(sv%2==0){
                    sv/=2;
                }
                else
                    sv = sv*3 +1;
                ++counter;
            }while(sv!=1);
            if(mx<counter){
                mx = counter;
                sn = i;
            }
        }
        printf("Between %llu and %llu, %llu generates the longest sequence of %llu values.\n",low,up,sn,mx);
        //cout<<sn<< " "<<mx<<endl;
    }
}
