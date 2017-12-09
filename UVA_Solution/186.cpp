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
#define INF 20000000
#define _INF 127
#define _HALF_INF 63
#define rep(i,a,b) for(int i = a; i<b ;i++)
#define open(inp) freopen(inp,"r",stdin)
#define Clear(a) memset(a,0,sizeof(a))
#define setfalse(a) memset(a,false,sizeof(a))
#define pb(number) push_back(number)

using namespace std;
#define MAX 100

msi cities;
map<int,string> city_index;
map< pii,pair<string,int> > info;
int dist[MAX][MAX];
int root[MAX][MAX];
int citiCounter ;
vi path;
void reset(){
    for(int i = 0;i < MAX;i++ ){
        for(int j = 0;j < MAX;j++){
            dist[i][j] = INF;
            root[i][j] = i;
        }
        dist[i][i] = 0;
    }
    cities.clear();
    city_index.clear();
    info.clear();
}
void floyed_worshall(){
    for(int k = 0;k<citiCounter;k++){
        for(int i = 0;i<citiCounter;i++){
            for(int j = 0;j<citiCounter;j++){
                if(dist[i][k]+dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k]+dist[k][j];
                    root[i][j] = root[k][j];
                }
            }
        }
    }
}
void createPath(int src,int target){
    if(src!=target)
        createPath(src,root[src][target]);
    //cout<<target<< " ";
    path.pb(target);
}
int main(){
    reset();
    citiCounter = 0;
    open("186.txt");
    while(cin.peek()!= '\n'){
        string from,to,route;
        int d;
        getline(cin,from,',');

        if(cities.find(from) == cities.end()){
            cities[from] = citiCounter;
            city_index[citiCounter] = from;
            ++citiCounter;
        }
        getline(cin,to,',');
        if(cities.find(to) == cities.end()){
            cities[to] = citiCounter;
            city_index[citiCounter] = to;
            ++citiCounter;
        }
        getline(cin,route,',');
        cin>>d;
        cin.ignore();
        dist[cities[from]][cities[to]] = min(dist[cities[from]][cities[to]],d);
        dist[cities[to]][cities[from]] = min(dist[cities[to]][cities[from]],d);
        pair<string,int> p = info[make_pair(cities[from],cities[to])];
        if(p.first.length()!=0)
            route = p.first;
        info[make_pair(cities[from],cities[to])] = make_pair(route,dist[cities[from]][cities[to]]);
        info[make_pair(cities[to],cities[from])] = make_pair(route,dist[cities[to]][cities[from]]);
    }
    floyed_worshall();
    int cases=1;
    string from,to;
    cin.ignore();

    while(cin.peek() != EOF){
        //if(cases!=1){
            cout<<endl<<endl;
       // }

        cases++;

//        printf("From                ");
//        printf(" To                  ");
//        printf(" Route     ");
//        printf(" Miles\n");
        printf("From                 To                   Route      Miles\n");
        printf("-------------------- -------------------- ---------- -----\n");

        getline(cin,from,',');
        getline(cin,to);
        int sum = 0;
        createPath(cities[from],cities[to]);
        for(int i = 0;i<path.size()-1;i++){
            pair<string,int> temp;
            temp = info[make_pair(path[i],path[i+1])];
            printf("%-20s %-20s %-10s %5d\n",city_index[path[i]].c_str(),city_index[path[i+1]].c_str(),temp.first.c_str(),temp.second);
            sum+=temp.second;
        }

        printf("                                                     -----\n");
        printf("                                          Total      %5d\n",sum);

        path.clear();
    }
}
