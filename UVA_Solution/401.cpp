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
map<char,char> mp;
int main(){
    string input;
    mp['A'] = 'A';mp['H'] = 'H';mp['I'] = 'I';mp['M'] = 'M';mp['O'] = 'O';mp['T'] = 'T';
    mp['U'] = 'U';mp['V'] = 'V';mp['W'] = 'W';mp['X'] = 'X';mp['Y'] = 'Y';mp['1'] = '1';
    mp['8'] = '8';mp['E'] = '3';mp['3'] = 'E';mp['J'] = 'L';mp['L'] = 'J';mp['2'] = 'S';
    mp['S'] = '2';mp['Z'] = '5';mp['5'] = 'Z';
    //freopen("401.txt","r",stdin);
    while(getline(cin,input)){
        string mirror="",rvrs="";
        int len = input.length();
        for(int i = len-1;i>=0;i--){
                mirror += mp[input[i]];
                rvrs+=input[i];
        }
        //cout<<mp['B'];
        if(mirror == input && input == rvrs)
            cout<<input<<" -- is a mirrored palindrome."<<endl<<endl;
        else if(mirror == input && input != rvrs)
            cout<<input<<" -- is a mirrored string."<<endl<<endl;
        else if(mirror != input && input == rvrs)
            cout<<input<<" -- is a regular palindrome."<<endl<<endl;
        else
            cout<<input<<" -- is not a palindrome."<<endl<<endl;
    }
}
