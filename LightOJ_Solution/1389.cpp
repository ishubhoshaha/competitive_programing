#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("inp.txt","r",stdin);
    int test;
    cin>>test;
    for(int cases = 1;cases<=test;cases++){
        int len,place = 0;
        cin>>len;
        string str;
        cin>>str;
        for(int i = 0;i<len;i++){
            if(str[i]=='.'){
                place++;
                i+=2;
            }
        }
        printf("Case %d: %d\n",cases,place);
    }
}
