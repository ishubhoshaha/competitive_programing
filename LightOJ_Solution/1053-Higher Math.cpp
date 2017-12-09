#include<bits/stdc++.h>
using namespace std;
int main(){
    int cases;
    cin>>cases;
    for(int test = 1;test<=cases;test++){
        int a,b,c;
        cin>>a>>b>>c;
        cout<<"Case "<<test<<": ";
        if((a*a+b*b)==c*c or (a*a+c*c)==b*b or (b*b+c*c)==a*a ){
            cout<<"yes"<<endl;
        }
        else
            cout<<"no"<<endl;
    }
}

