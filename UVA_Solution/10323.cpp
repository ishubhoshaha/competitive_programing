#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        unsigned long long fact = 1;
        if(n>=0){
            if(n<8){
                printf("Underflow!\n");
            }
            else if(n>13){
                printf("Overflow!\n");
            }
            else{
                for(int i = 1;i<=n;i++){
                    fact*=i;
                }
                cout<<fact<<endl;
            }
        }
        else{
            n*=(-1);
            if(n%2==0){
                printf("Underflow!\n");
            }
            else
                printf("Overflow!\n");
        }

    }
}
