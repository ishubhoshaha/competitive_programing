#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    cin>>test;
    for(int cases = 1;cases<=test;cases++){
        getchar();
        int n,sum=0;
        cin>>n;
        for(int i = 0;i<n;i++){
            int a;
            cin>>a;
            if(a>0){
                sum+=a;
            }
        }
        printf("Case %d: %d\n",cases,sum);

    }
}
