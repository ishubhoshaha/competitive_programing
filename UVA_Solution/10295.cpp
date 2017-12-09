/*
	Problem Type: Adhoc,STL
*/

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
int main(){
    open("in.txt");
    int m,n;
    cin>>m>>n;
    map<string,long long> dictionary;
    rep(i,0,m){
        string str;
        long long value;
        cin>>str>>value;
        dictionary[str] = value;
    }
    rep(i,0,n){
        string str;
        long long totalV = 0;
        while(getline(cin,str) and str.find(".")==string::npos){
            stringstream ss (str);
            string word;
            while(ss>>word){
                totalV += dictionary[word];
            }
        }
        cout<<totalV<<endl;
    }
}
