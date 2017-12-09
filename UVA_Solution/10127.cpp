#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n)==1){
        int mul=1%n;
        int ans=1;
        if(n!=1)
        while(mul){
            ans++;
            mul = ((mul*10)+1)%n;
        }
        printf("%d\n",ans);
    }
}
