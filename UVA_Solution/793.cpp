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
#define INF 2000000000
#define _INF 127
#define _HALF_INF 63

#define open(inp) freopen(inp,"r",stdin)
#define Clear(a) memset(a,0,sizeof(a))
#define setfalse(a) memset(a,false,sizeof(a))
#define pb(number) push_back(number)
#define rep(i,a,b) for(int i = a;i<=b;i++)
using namespace std;
#define MAX 1500
vi pset(MAX);
void initSet(int sz){
    pset.resize(sz);
    rep(i,0,sz){
        pset[i] = i;
    }
}
int FindSet(int u){
    return (pset[u]==u) ? u : (pset[u] = FindSet(pset[u]));
}
bool isSameSet(int u,int v){
    return (FindSet(u)==FindSet(v)?true:false);
}
void unionSet(int u,int v){
    pset[FindSet(u)]= FindSet(v);
}
int main(){
    int testcase;
    open("inp.txt");
    cin>>testcase;
    cin.ignore();
    getchar();
    rep(caseno,1,testcase){
        //getchar();
        pset.clear();
        string str;
        int right = 0,wrong = 0;
        int n;
        cin>>n;
        cin.ignore();
        initSet(n);
        while(getline(cin,str)){
            if(str.size()==0){
                break;
            }
            stringstream ss(str);
            string check;
            int from,to;
            while(ss>>check>>from>>to){
                if(check == "c"){
                    unionSet(from,to);
                }
                else if(check == "q"){
                    if(isSameSet(from,to)){
                        ++right;
                    }
                    else
                        ++wrong;
                }
            }
        }
        cout<<right<<","<<wrong<<endl;
        if(caseno!=testcase){
            cout<<endl;
        }
    }
}
