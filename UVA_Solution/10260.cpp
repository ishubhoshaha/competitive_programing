#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    map<char,int>mp;
    mp['B']= 1;mp['F']= 1;mp['P']= 1;mp['V']= 1;
    mp['C']= 2;mp['G']= 2;mp['J']= 2;mp['K']= 2;mp['Q']= 2;mp['S']= 2;mp['X']= 2;mp['Z']= 2;
    mp['D']= 3;mp['T']= 3;
    mp['L']= 4;
    mp['M']= 5;mp['N']= 5;
    mp['R']= 6;
    while(cin>>str){
        int len = str.length();
        char ch=' ';
        int previous_code=9;
        for(int i = 0;i<len;i++){
            if(str[i]=='A' or str[i]=='E' or str[i]=='I' or str[i]=='O' or str[i]=='U' or str[i]=='H' or str[i]=='W' or str[i]=='Y'or str[i]==ch){
                ch=str[i];
                previous_code = mp[str[i]];
                continue;
            }
            if(previous_code == mp[str[i]]){
                ch=str[i];
                previous_code = mp[str[i]];
                continue;
            }
            cout<<mp[str[i]];
            ch=str[i];
            previous_code = mp[str[i]];
        }
        cout<<endl;
    }
}
