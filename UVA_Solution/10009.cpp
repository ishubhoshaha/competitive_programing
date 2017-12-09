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
#define MAX 100
vi graph[MAX];
vi parents(MAX);
bool visit[MAX];
msi nodeMap;
map<int,string> nodeIndex;
vi op;
string output;

void BFS(int src,int dest){
    memset(visit,_UNVISIT,sizeof visit);
    parents.clear();
    queue<int> q;
    q.push(src);
    visit[src] = _VISIT;
    parents[src] = src;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u==dest)
            break;
        else{
            int sz = graph[u].size();
            for(int i=0;i< sz;i++){
                int v = graph[u][i];
                if(visit[v]== _UNVISIT){
                    visit[v]=_VISIT;
                    parents[v] = u;
                    q.push(v);
                }
            }

        }
    }
}

void print(int src,int dest){
    if(src==dest){
        op.pb(src);
        string s=nodeIndex[src];
        output += s[0];
        return ;
    }
    else
    {
        print(src,parents[dest]);
        op.pb(dest);
        string s=nodeIndex[dest];
        output += s[0];
    }
}

int main(){
    int cases;
    //freopen("10009.txt","r",stdin);
    cin>>cases;
    cin.ignore();

    for(int caseno = 1;caseno<=cases;caseno++){
        getchar();
//        msi nodeMap;
//        map<int,string> nodeIndex;
        nodeMap.clear();
        nodeIndex.clear();
        for(int i=0;i<MAX;i++)
            graph[i].clear();
        memset(graph,0,sizeof graph);
        int tedge,tquery,citiCounter=1;
        cin>>tedge>>tquery;
        cin.ignore();
        for(int i=1 ;i<=tedge ;i++){
            string from,to;
            cin>>from>>to;
            if(nodeMap.find(from)==nodeMap.end()){
                nodeMap[from]=citiCounter;
                nodeIndex[citiCounter]= from;
                citiCounter++;
            }
            if(nodeMap.find(to)==nodeMap.end()){
                nodeMap[to]=citiCounter;
                nodeIndex[citiCounter]= to;
                citiCounter++;
            }
            graph[nodeMap[from]].pb(nodeMap[to]);
            graph[nodeMap[to]].pb(nodeMap[from]);

        }
        //cin.ignore();
        for(int i =1;i<=tquery;i++){
            string from,to;
            cin>>from>>to;
            BFS(nodeMap[from],nodeMap[to]);
            output="";
            print(nodeMap[from],nodeMap[to]);
            cout<<output<<endl;
        }
        if(cases!=caseno)
            cout<<endl;
    }
}
