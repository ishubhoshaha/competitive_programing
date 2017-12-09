#include<bits/stdc++.h>

#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define msi map<string, int>

#define visited_ true
#define unvisited_ false
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
#define dy4 {0,0,-1,+1}
#define dx8 {-1,0,+1,-1,+1,-1,0,+1}
#define dy8 {+1,+1,+1,0,0,-1,-1,-1}

using namespace std;
map<char,int> word;
int main(){
    open("news.txt");
    int cases;
    cin>>cases;
    //cout<<cases<<endl;
    cin.ignore();
    while(cases--){
        //cout<<"-"<<cases<<"-"<<endl;
        int k;
        cin>>k;
        cin.ignore();
        word.clear();
        rep(i,0,k){
            char w;
            int a;
            cin>>w>>a;
            word[w] = a;
        }
        int maxLine;
        double amount = 0;
        cin>>maxLine;
        cin.ignore();
        rep(i,0,maxLine){
            string inp;
            getline(cin,inp);
            //cout<<inp<<endl;
            int sz = inp.size();
            rep(i,0,sz){
                amount += word[inp[i]];
            }
        }
        printf("%.2lf$\n",amount/100);
        //cout<<amount/100<<"$"<<endl;
    }
}
