#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int cs = 1;cs<=t;cs++){
        unsigned long long ans = 0,n,k;
        cin>>n>>k;

        if(n*n>=k){
            ans = 1;
            for(int i = 1;i<=k;i++){
                ans = ans*n*n/i;
                n--;
            }
        }

        printf("Case %d: %llu\n",cs,ans);
    }

}
