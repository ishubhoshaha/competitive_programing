#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int getAnswer(ull a,ull l){
    int counter=1;
    if(a==l)
        return 1;
    while(a!=1 ){
        if(a>l){
            --counter;
            break;
        }
        ++counter;
        if(a%2==0){
            a/=2;
        }
        else{
            a=3*a+1;
        }
    }
    return counter;
}
int main(){
    //freopen("694.txt","r",stdin);
    int cases=0;
    ull a,l;
    while(cin>>a>>l and a!=-1 and l!=-1){
        printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n",++cases,a,l,getAnswer(a,l));
    }
}
