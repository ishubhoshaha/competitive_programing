#include<bits/stdc++.h>

#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define msi map<string, int>

#define visited_ true
#define unvisited_ false
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
#define dy4 {0,0,-1,+1}
#define dx8 {-1,0,+1,-1,+1,-1,0,+1}
#define dy8 {+1,+1,+1,0,0,-1,-1,-1}

using namespace std;
int main(){
    open("input.txt");
    string str,line[100];
    int l = 0,mxLength= 0;
    while(getline(cin,str)){
        line[l++] = str;
        int len = str.size();
        mxLength = max(mxLength,len);
    }
    //cout<<mxLength<<" "<<l;
    for(int j = 0;j<mxLength;j++){
        for(int i = l-1;i>=0;i--){
            if(line[i].size()>j)
                cout<<line[i][j];
            else
                cout<<" ";
        }
        cout<<endl;
    }
}
