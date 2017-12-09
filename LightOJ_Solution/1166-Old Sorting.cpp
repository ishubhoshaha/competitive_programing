#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("inp.txt","r",stdin);
    int test;
    cin>>test;
    for(int cases = 1;cases<=test;cases++){
        vector<int> v;
        int n,interchange = 0;
        cin>>n;
        for(int i = 0;i<n;i++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        for(int i = 0;i<n;i++){
            if(i+1 != v[i]){
                for(int j = i+1;j<n;j++){
                    if(v[j]==i+1){
                        swap(v[j],v[i]);
                        ++interchange;
                        break;
                    }
                }
            }
        }
        printf("Case %d: %d\n",cases,interchange);
    }
}
