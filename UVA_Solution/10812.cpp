#include<bits/stdc++.h>

#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define msi map<string, int>
#define mem(arrayName,i) memset(arrayName,int (i),sizeof arrayName)
#define pb(number) push_back(number)
#define _VISIT true
#define _UNVISIT false
#define ull unsigned long long
#define INF 2000000000
#define _INF 127
#define _HALF_INF 63

using namespace std;
int main(){
    int n;
    cin>>n;
    cin.ignore();
    while(n--){
        long long sum,dif,a,b;
        cin>>sum>>dif;
        long long s = sum+dif;
        if(s%2 == 0){
            a=(s)/2;
            b=sum-a;
        }
        else
            b=-1;
        //cout<<sum-a;
        if(b<0)
            cout<<"impossible"<<endl;
        else
            cout<<a<<" "<<b<<endl;
    }
}
