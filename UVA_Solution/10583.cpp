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

using namespace std;
int parent[50005];
//int Rank[50005];
bool check[50005];
void make_set(int sz){
    for(int i = 1;i<=sz;i++){
        parent[i] = i;
    }
}
int Find(int u){
    return (parent[u] == u) ?  u : ( parent[u] = Find(parent[u]) );
}
void union_set(int u,int v){
//    if(Rank[u]>Rank[v]){
//        parent[v] = u;
//    }
//    else if(Rank[v]>Rank[u]){
//        parent[u] = v;
//    }
//    else{
//        parent[v] = u;
//        Rank[u]++;
//    }
    parent[Find(v)] = Find(u);
}

int main(){
    int n,m,caseno=0;
    open("inp.txt");
    while(cin>>n>>m and n!=0 and m!=0){
        for(int i =0;i<50005;i++){
            parent[i] = 0;
            check[i]=false;
        }
        cin.ignore();
        make_set(n);
        for(int i = 1;i<=m;i++){
            int from,to;
            cin>>from>>to;
            union_set(from,to);
        }
        int c=0;
        for(int i = 1;i<=n;i++){
            int a = Find(i);
            if(!check[a]){
                ++c;
                check[a] = true;
            }
        }
        printf("Case %d: %d\n",++caseno,c);
    }
}
