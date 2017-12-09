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

vi graph[100];
bool visit[100];
void dfs(int src){
    visit[src] = true;
    for(int i = 0;i<graph[src].size();i++){
        int v = graph[src][i];
        if(visit[v] == false)
            dfs(v);
    }
}

int main(){
    int cases;
    freopen("input.txt","r",stdin);
    cin>>cases;
    cin.ignore();
    for(int caseno = 1;caseno <= cases;caseno++){
        //getchar();
        msi input;
        memset(visit,false,sizeof visit);
        memset(graph,0,sizeof graph);
        char ch;
        cin>>ch;
        cin.ignore();
        int maxNode = (ch - 64) % 27 ;
        //cout<<maxNode;
        while(1){
            string str;
            getline(cin,str);
            //cout<<str<<endl;
            if(str.size()==0)
                break;
            string a,b;
            a=str[0];
            b=str[1];
            if (input.find(a)==input.end()){
                input[a] = (str[0] - 64) % 27;
            }
            if(input.find(b)==input.end()){
                input[b] = (str[1] - 64) % 27;
            }
            graph[input[a]].pb(input[b]);
            graph[input[b]].pb (input[a]);
        }
//        for(int i = 1;i<=maxNode;i++){
//            for(int j=0;j<graph[i].size();j++){
//                cout<<graph[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        int coutner = 0;
        for(int i=1;i<=maxNode;i++){
            if(visit[i]==false){
                dfs(i);
                ++coutner;
            }
        }
        cout<<coutner<<endl;
        if(cases!=caseno)
            cout<<endl;

    }
}
