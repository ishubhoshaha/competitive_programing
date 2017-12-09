#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int a;
        scanf("%d",&a);
        v.push_back(a);
    }
    int query;
    scanf("%d",&query);
    for(int i = 0;i<query;i++){
        int q;
        scanf("%d",&q);
        int l,u;
        l = lower_bound(v.begin(),v.end(),q)-v.begin() -1;
        u = upper_bound(v.begin(),v.end(),q)-v.begin();

        if(l<0){
            cout<<"X"<<" "<<v[u]<<endl;
        }else if(u==n)
            cout<<v[l]<<" "<<"X"<<endl;
        else
            cout<<v[l]<<" "<<v[u]<<endl;
    }
}
