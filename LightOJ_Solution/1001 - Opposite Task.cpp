#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    cin>>test;
    for(int cases = 1;cases<=test;cases++){
        int n;
        cin>>n;
        if(n>10){
            for(int i = 1;i<n;i++){
                if((n-i)<=10){
                    cout<<min(i,n-i)<<" "<<max(i,n-i)<<endl;
                    break;                }
            }
        }
        else
            cout<<"0 "<<n<<endl;
    }
}
