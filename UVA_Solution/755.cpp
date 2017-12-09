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
    map<char,char> charMap;
    charMap['a'] = '2';
    charMap['b'] = '2';
    charMap['c'] = '2';
    charMap['d'] = '3';
    charMap['e'] = '3';
    charMap['f'] = '3';
    charMap['g'] = '4';
    charMap['h'] = '4';
    charMap['i'] = '4';
    charMap['j'] = '5';
    charMap['k'] = '5';
    charMap['l'] = '5';
    charMap['m'] = '6';
    charMap['n'] = '6';
    charMap['o'] = '6';
    charMap['p'] = '7';
    charMap['r'] = '7';
    charMap['s'] = '7';
    charMap['t'] = '8';
    charMap['u'] = '8';
    charMap['v'] = '8';
    charMap['w'] = '9';
    charMap['x'] = '9';
    charMap['y'] = '9';
    charMap['1'] = '1';
    charMap['2'] = '2';
    charMap['3'] = '3';
    charMap['4'] = '4';
    charMap['5'] = '5';
    charMap['6'] = '6';
    charMap['7'] = '7';
    charMap['8'] = '8';
    charMap['9'] = '9';
    charMap['0'] = '0';
    //open("in.txt");
    int cases;
    cin>>cases;
    getchar();
    bool isFirst = false;
    rep(no,0,cases){
        map<string,int> op;
        if(isFirst){
            getchar();
        }
        isFirst = true;
        int totalNumber;
        cin>>totalNumber;
        cin.ignore();
        rep(line,0,totalNumber){
            string number,answer= "";
            getline(cin,number);
            int len = number.size(),j=1;
            rep(i,0,len){
                if(j==4){
                    answer+="-";
                    ++j;
                }
                if(number[i]!='-'){
                    char ch = tolower(number[i]);
                    //cout<<charMap[ch]<<endl;
                    answer= answer+charMap[ch];
                    ++j;
                }
            }
            op[answer]++;
            //cout<<answer<<endl;
        }
        bool flag  = true;
        for(map<string,int> ::iterator it = op.begin();it!=op.end();it++){
            if(it->second!=1){
                cout<<it->first<< " " <<it->second<<endl;
                flag = false;
            }
        }
        if(flag){
            cout<<"No duplicates."<<endl;
        }
        if(no+1!=cases)
            cout<<endl;
    }
}
