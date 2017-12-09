#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)
int main(){
    int test;
    //cout<<acos(-1);
    cin>>test;
    for(int cs = 1;cs<=test;cs++){
        double R,n,r;
        cin>>R>>n;
        double x = sin(pi/n);
        //cout<<x;
        r = R*x;
        r = r/(x+1);
        cout<<"Case "<<cs<<": "<<setprecision(10)<<r+.0000000001<<endl;
    }
}
