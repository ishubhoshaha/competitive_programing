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
    //open("in.txt");
    cout<<"SHIPPING ROUTES OUTPUT"<<endl<<endl;
    int dataSet;
    cin>>dataSet;
    rep(no,0,dataSet){
        map<string,bool> visit;
        map<string,vector<string> > adjList;
        int warehouse,edge,shipingRQ;

        cin>>warehouse>>edge>>shipingRQ;
        cin.ignore();
        rep(i,0,warehouse){
            string node;
            cin>>node;
            adjList[node];
            visit[node] = false;
        }
        cin.ignore();
        rep(i,0,edge){
            string from,to;
            cin>>from>>to;
            adjList[from].push_back(to);
            adjList[to].push_back(from);
        }
        /// AdjList
//        for(map<string,vector<string> > ::iterator it = adjList.begin();it!=adjList.end();++it){
//            cout<<it->first<<" ->";
//            for(vector<string> ::iterator vit = it->second.begin();vit!=it->second.end();vit++){
//                cout<<*vit<<" ";
//            }
//            cout<<endl;
//        }
        cout<<"DATA SET  "<<no+1<<endl<<endl;
        rep(i,0,shipingRQ){
            int sz;
            bool isFound = false;
            string from,to;
            for(map<string,bool> ::iterator it = visit.begin();it!=visit.end();it++){
                it->second = false;
            }
            cin>>sz>>from>>to;

            /// BFS
            map<string,int> level;
            visit[from] = true;
            queue<string> q;
            q.push(from);
            level[from] = 0;
            while(!q.empty()){
                string u = q.front();
                //cout<<u<<endl;
                q.pop();
                if(u == to){
                    isFound = true;
                    break;
                }
                for(vector<string> ::iterator it = adjList[u].begin();it!=adjList[u].end();++it){
                    string v = *it;
                    if(!visit[v]){
                        visit[v] = true;
                        level[v] = level[u] + 1;
                        q.push(v);
                    }
                }
            }
            if(isFound){
                cout<<"$"<<sz*level[to]*100<<endl;
            }
            else
                cout<<"NO SHIPMENT POSSIBLE"<<endl;
        }
        cout<<endl;

    }
    cout<<"END OF OUTPUT"<<endl;
}
