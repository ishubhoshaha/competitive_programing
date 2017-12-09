/*
	Problem Type: MST
	level: 2 (But it seems to me this problem statement is quite unclear.)
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
#define dpClear(a) memset(a,-1,sizeof(a))
#define setfalse(a) memset(a,false,sizeof(a))
#define pb(number) push_back(number)
#define dx4 {-1,+1,0,0}
#define dy4 {-1,+1,0,0}
#define dx8 {-1,0,+1,-1,+1,-1,0,+1}
#define dy8 {+1,+1,+1,0,0,-1,-1,-1}
using namespace std;
vector<pair<int,pii > > save_k_lines;
priority_queue<pair<int,pii >,vector<pair<int,pii> >,greater<pair<int,pii> > > pq,pq1;
#define MAX_NODE 1000000
vector<int>parentSet(MAX_NODE);
void initSet(int n){
    parentSet.resize(n);
    rep(i,0,n){
        parentSet[i] = i;
    }
}
int find(int u){
    return (parentSet[u] == u)? u : (parentSet[u] = find(parentSet[u]));
}
bool isSameSet(int u,int v){
    return (find(u)==find(v)) ? true : false;
}
int Kruskal(){
    int totalCost = 0;
    while(!pq.empty()){
        pair<int,pair<int,int> > temp;
        temp = pq.top();
        pq.pop();
        if(!isSameSet(temp.second.first,temp.second.second)){
            totalCost+=temp.first;
            //cout<<temp.second.first<<" "<<temp.second.second<<" "<<temp.first<<" "<<totalCost<<endl;
            parentSet[find(temp.second.first)] = find(temp.second.second);
        }
    }
    return totalCost;
}
int Kruskal_for_mkLines(){
    int totalCost = 0;
    while(!pq1.empty()){
        pair<int,pair<int,int> > temp;
        temp = pq1.top();
        pq1.pop();
        if(!isSameSet(temp.second.first,temp.second.second)){
            totalCost+=temp.first;
            //cout<<temp.second.first<<" "<<temp.second.second<<" "<<temp.first<<" "<<totalCost<<endl;
            parentSet[find(temp.second.first)] = find(temp.second.second);
        }
    }
    return totalCost;
}
int main(){
    open("908.txt");
    int n;
    bool flag = true;
    while(scanf("%d\n",&n)==1){
        //cin.ignore();
        parentSet.clear();
        if(!flag){
            cout<<endl;
        }
        int old = 0;
        flag = false;
        rep(i,0,n-1){
            int from,to,cost;
            cin>>from>>to>>cost;
            old+=cost;
            //pq.push(make_pair(cost,make_pair(from,to)));
        }
        cin.ignore();
        //initSet(n);
        //cout<<Kruskal()<<endl;
        int k;
        cin>>k;
        cin.ignore();
        rep(i,0,k){
            int from,to,cost;
            cin>>from>>to>>cost;

            pq.push(make_pair(cost,make_pair(from,to)));
        }
        cin.ignore();
        int m;
        cin>>m;
        cin.ignore();
        rep(i,0,m){
            int from,to,cost;
            cin>>from>>to>>cost;
            pq.push(make_pair(cost,make_pair(from,to)));
        }
        parentSet.clear();
        initSet(m+k);
        cout<<old<<endl<<Kruskal()<<endl;
    }

}
