/*
Problem Type: Graph,BFS,STL MAP
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
map<string,vector<string> > adjList;
map<string,bool>visit;
map<string,string> parent;
bool bfs(string src,string target){
    parent[src] = "null";
    visit[src] = true;
    queue<string> q;
    q.push(src);
    while(!q.empty()){
        string u = q.front();
        q.pop();
        if(u == target)
            return true;
        for(vector<string> ::iterator Vit = adjList[u].begin();Vit!=adjList[u].end();Vit++){
            string v = *Vit;
            if(!visit[v]){
                visit[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return false;
}
void print(string src,string target){
    if(parent[target]=="null"){
        return;
    }
    else{
        print(src,parent[target]);
        cout<<parent[target]<<" "<<target<<endl;
    }
}
int main(){
    //open("inp.txt");
    int n;
    bool nl= false;
    while(cin>>n){
        adjList.clear();
        parent.clear();
        visit.clear();
        if(nl){
            getchar();
            cout<<endl;
        }
        nl = true;
        rep(i,0,n){
            string from,to;
            cin>>from>>to;
            adjList[from].pb(to);
            adjList[to].pb(from);
        }
        string src,target;
        cin>>src>>target;
        if(bfs(src,target)){
            print(src,target);
        }
        else
            cout<<"No route"<<endl;

//        for(map<string,string> ::iterator it = parent.begin();it!=parent.end();it++){
//            cout<<it->first<<" ";
//        }
//        cout<<endl;
//        for(map<string,string> ::iterator it = parent.begin();it!=parent.end();it++){
//            cout<<it->second<<" ";
//        }
//        cout<<endl;

//        cout<<"Adjacency List"<<endl;
//        for(map<string,vector<string> > ::iterator it = adjList.begin(); it!=adjList.end();it++){
//            vector<string> temp = it->second;
//            cout<<it->first<<"--> ";
//            for(int i = 0;i<temp.size();i++){
//                cout<<temp[i]<<" ";
//            }
//            cout<<endl;
//        }
    }
}
