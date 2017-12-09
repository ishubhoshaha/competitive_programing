#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    cin>>test;
    for(int cases = 1;cases<=test;cases++){
        int n,track,ans = -1;
        cin>>n;
        vector<int>c;
        c.push_back(0);
        for(int i = 0;i<n;i++){
            int a;
            cin>>a;
            c.push_back(a);
            if(ans<(c[i+1]-c[i])){
                ans = c[i+1]-c[i];
            }
        }
        track = ans;
        for(int i = 0;i<n;i++){
            //ans = max(c[i+1]-c[i],ans);
            if(ans<(c[i+1]-c[i])or ans==0){
                track++;
                break;
            }
            if(ans == (c[i+1]-c[i])){
                --ans;
            }
        }

        printf("Case %d: %d\n",cases,track);
    }
}
