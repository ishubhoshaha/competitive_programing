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

int a[40];
int t[40],result[40];
int n,make,mx = -1,x;


void subset_sum(int t_size,int sum, int index){
    if(sum > mx  and sum <= make){
        mx = sum;
        x = t_size;

        rep(j,0,t_size){
            result[j] = t[j];
        }
    }
    for( int i = index; i < n; i++ )
    {
        t[t_size] = a[i];
        subset_sum(t_size + 1, sum + a[i], i + 1);
    }
}


int main()
{
    //open("i.txt");
    while(cin>>make>>n){
        Clear(a);
        Clear(t);
        mx = -1;
        Clear(result);
        rep(i,0,n){
            cin>>a[i];
        }
        subset_sum(0,0,0);
        rep(i,0,x)
            cout<<result[i]<<" ";
        cout<<"sum:"<<mx<<endl;
    }
}
