#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,c=0;
    freopen("abc.txt","r",stdin);
    while(scanf("%d",&n)==1){
        vector<int> v;
        pair<int,int> p;
        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            v.push_back(num);
        }
        sort(v.begin(),v.end());
        int m;
        cin.ignore();
        cin>>m;
        int d=9000000;
        int lb = lower_bound(v.begin(),v.end(),m)-v.begin();
        lb-=1;
        //cout<<lb;
        for(int i = lb;i>0;i--){
            for(int j = 0 ;j<lb;j++){
                if(v[i]+v[j]>m)
                    break;
                if(v[i]+v[j]==m){
                    if(abs(v[i]-v[j])<d){
                        p.first=v[i];
                        p.second=v[j];
                        d=abs(v[i]-v[j]);
                        break;
                    }
                }
            }
        }
        if(p.first< p.second)
            cout<<"Peter should buy books whose prices are "<<p.first<<" and "<<p.second<<"."<<endl;
        else
            cout<<"Peter should buy books whose prices are "<<p.second<<" and "<<p.first<<"."<<endl;
        cout<<endl;
        getchar();
    }
}
