/*
Problem Type: Adhoc
Critical Test Case: WERTYUIOP[]SDFGHJKL;'XCVBNM,./234567890-=
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
map<char,char> alternateKey;
int main(){
    alternateKey['W'] = 'Q';
    alternateKey['S'] = 'A';
    alternateKey['X'] = 'Z';
    alternateKey['E'] = 'W';
    alternateKey['D'] = 'S';
    alternateKey['C'] = 'X';
    alternateKey['R'] = 'E';
    alternateKey['F'] = 'D';
    alternateKey['V'] = 'C';
    alternateKey['T'] = 'R';
    alternateKey['G'] = 'F';
    alternateKey['B'] = 'V';
    alternateKey['Y'] = 'T';
    alternateKey['H'] = 'G';
    alternateKey['B'] = 'V';
    alternateKey['N'] = 'B';
    alternateKey['U'] = 'Y';
    alternateKey['J'] = 'H';
    alternateKey['M'] = 'N';
    alternateKey['I'] = 'U';
    alternateKey['K'] = 'J';
    alternateKey[','] = 'M';
    alternateKey['O'] = 'I';
    alternateKey['L'] = 'K';
    alternateKey['.'] = ',';
    alternateKey['P'] = 'O';
    alternateKey['['] = 'P';
    alternateKey['\''] = ';';
    alternateKey[';'] = 'L';
    alternateKey['/'] = '.';
    alternateKey['2'] = '1';
    alternateKey['3'] = '2';
    alternateKey['4'] = '3';
    alternateKey['5'] = '4';
    alternateKey['6'] = '5';//W
    alternateKey['8'] = '7';
    alternateKey['9'] = '8';
    alternateKey['0'] = '9';
    alternateKey['-'] = '0';
    alternateKey['='] = '-';
    alternateKey[' '] = ' ';
    alternateKey[']'] = '[';
    alternateKey['\\'] = ']';
    alternateKey['7'] = '6';
    //int ch = ''';
    string input;
    while(getline(cin,input)){
        int sz=input.size();
        for(int i = 0;i<sz;i++){
            cout<<alternateKey[input[i]];
        }
        cout<<endl;
    }
}
