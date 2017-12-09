/*
Problem Type: BFS
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
string dictionary[201];
vi adjlist[201];
int totalWord;
msi wordIndex;
bool isAdjacant(string a,string b){
    if(a.length()!=b.length())
        return false;
    int lenA = a.length();
    int c = 0;
    rep(i,0,lenA){
        if(a[i]!=b[i]){
            ++c;
            if(c==2){
                return false;
            }
        }
    }
    return true;
}
void createAdjList(){
    rep(i,0,totalWord){
        rep(j,i+1,totalWord){
            if(isAdjacant(dictionary[i],dictionary[j])){
                adjlist[wordIndex[dictionary[i]]].pb(wordIndex[dictionary[j]]);
                adjlist[wordIndex[dictionary[j]]].pb(wordIndex[dictionary[i]]);
            }
        }
    }
}
bool visit[201];
int dist[201];
int bfs(int src,int target){
    setfalse(visit);
    Clear(dist);
    queue<int> q;
    q.push(src);
    dist[src]=0;
    visit[src]=true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        int l = adjlist[u].size();
        if(target==u){
            return dist[u];
        }
        rep(i,0,l){
            int v = adjlist[u][i];
            if(!visit[v]){
                visit[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
void reset(){
    rep(i,0,201){
        dictionary[i].clear();
        adjlist[i].clear();
    }
    wordIndex.clear();
}
int main(){
    int testcase;
    //open("429.txt");
    cin>>testcase;
    cin.ignore();
    int newLine = 0;
    while(testcase--){
        //getchar();
        if(newLine==1){
            cout<<endl;
        }
        newLine = 1;
        reset();
        string str;

        totalWord=0;
        while(cin>>str and str!="*"){
            dictionary[totalWord] = str;
            wordIndex[str] = totalWord;
            totalWord++;
        }
        cin.ignore();
        createAdjList();
        string line;
        while(getline(cin,line)){
            if(line.length()==0)
                break;
            string from,to;
            stringstream ss(line);
            ss>>from>>to;
            cout<<from<<" "<<to<<" "<<bfs(wordIndex[from],wordIndex[to])<<endl;
        }
    }
}
