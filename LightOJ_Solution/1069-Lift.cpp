#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    cin>>test;
    for(int cs = 1;cs<=test;cs++){
        int n,c;
        cin>>n>>c;
        int x = abs(n-c)*4;
        int y = n*4;
        //cout<<x<<" "<<y<<endl;
        cout<<"Case "<<cs<<": "<<x+y+19<<endl;
    }
}
